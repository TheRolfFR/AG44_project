#include "../include/Graph.h"
#include "../include/Vertice.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int getDigits(int number) {
    if(number == 0)
        return 1;

    int digits = 0;
    while(number != 0) {
        digits++;
        number /= 10;
    }

    return digits;
}

void Graph::generateRandomGraph(int nVertices, char typeOfGraph) {
    if(nVertices > 0) {
        srand(time(NULL));

        for(int i = 0; i < nVertices; i++) {
            this->listVertices.push_back(Vertice(i));
        }

        int id = 0;
        for(int a = 0; a < nVertices; a++) {
            for(int b = 0; b < nVertices; b++) {
                if(a != b && rand()%6 == 1) {
                    this->listEdge.push_back(Edge(id, &this->listVertices[a], &this->listVertices[b]));
                    if(typeOfGraph == 'n')
                        this->listEdge.push_back(Edge(id, &this->listVertices[b], &this->listVertices[a])); // DIAGONAL
                    id++;
                    this->listVertices[a].addNeighbour(&this->listVertices[b]);
                }
            }
        }
    } else {
        cerr << "needs a positive number of vertices, given " << nVertices;
        exit(-1);
    }
}

void Graph::generateRandomGraph(int nVertices, char typeOfGraph, int minCost, int maxCost) {
    if(nVertices > 0) {
        srand(time(NULL));

        for(int i = 0; i < nVertices; i++) {
            this->listVertices.push_back(Vertice(i));
        }

        int id = 0;
        for(int a = 0; a < nVertices; a++) {
            for(int b = 0; b < nVertices; b++) {
                int valRandom = rand()%(maxCost-minCost+1)+minCost;
                cout<<valRandom<<endl;
                if(a != b && rand()%6 == 1) {
                    this->listEdge.push_back(Edge(id, &this->listVertices[a], &this->listVertices[b],valRandom));
                    if(typeOfGraph == 'n')
                        this->listEdge.push_back(Edge(id, &this->listVertices[b], &this->listVertices[a],valRandom)); // DIAGONAL
                    id++;
                    this->listVertices[a].addNeighbour(&this->listVertices[b]);
                }
            }
        }
    } else {
        cerr << "needs a positive number of vertices, given " << nVertices;
        exit(-1);
    }
}

Graph::Graph() : typeOfGraph('n') {
//    generateRandomGrvoid Graph::generateRandomGraph(int nVertices, char typeOfGraph, int minCost, int maxCost) {aph(0, this->typeOfGraph);
//    create empty graph
}

Graph::Graph(int nVertices) : typeOfGraph('n')
{
    generateRandomGraph(nVertices, this->typeOfGraph);
}

Graph::Graph(int nVertices, char tOfGraph): typeOfGraph(tOfGraph) {
    generateRandomGraph(nVertices, this->typeOfGraph);
}

Graph::Graph(const char* filepath) {
    loadFromFile(filepath);
}

Graph::Graph(int nVertices, char tOfGraph, int minCost, int maxCost): typeOfGraph(tOfGraph) {
    generateRandomGraph(nVertices, this->typeOfGraph,minCost,maxCost);
}

void Graph::print() {
    cout << "graph with " << this->listVertices.size() << " vertices and " << this->listEdge.size() << " edges" << endl;
    for(auto i = this->listVertices.begin(); i != this->listVertices.end(); ++i) {
        (*i).print();
    }
}

void Graph::printAsList() {
    int x = (int)this->listVertices.size();
    for (int i = 0; i<x; ++i){
        for (int j = 0; j<x; ++j){
            if (isLinked(this->listVertices[i].id,this->listVertices[j].id)){
                    cout << this->listVertices[j].id << "; ";
            }
        }
        cout << endl;
    }
}

void Graph::saveAsAdjencyList(const char* filepath){
    ofstream file(filepath);

    file << this->listVertices.size() << endl;
    file << this->typeOfGraph << endl;
    file << "l" << endl;

    int x = (int)this->listVertices.size();
    for (int i = 0; i<x; ++i){
        for (int j = 0; j<x; ++j){
            if (isLinked(this->listVertices[i].id,this->listVertices[j].id)){
                    file << this->listVertices[j].id << " ";
            }
        }
        file << endl;
    }
    file.close();
}

Vertice* Graph::getVertice(int id) {
    auto i = this->listVertices.begin();
    Vertice *result = NULL;

    while(result == NULL && i != this->listVertices.end()) {
        if((*i).getId() == id)
            result = &(*i);

        ++i;
    }

    return result;
}

void Graph::saveAsMatrix(const char filepath[]) {
    ofstream file(filepath);

    file << this->listVertices.size() << endl;
    file << this->typeOfGraph << endl;
    file << "m" << endl;

    int length = (int) this->listVertices.size();
    for(int i = 0; i < length; ++i) {
        for(int j = 0; j < length; ++j) {
            if(this->isLinked(listVertices[i].id, listVertices[j].id)) {
                for (int k=0; k<4-getDigits(this->getEdge(&listVertices[i], &listVertices[j])->cost); ++k)
                {
                    file << " ";
                }
                file << this->getEdge(&listVertices[i], &listVertices[j])->cost;
            } else {
                file << "   0";
            }
            file << " ";
        }
        file << endl;
    }

    file.close();
}

Edge* Graph::getEdge(int id) {
    auto i = this->listEdge.begin();
    Edge *result = NULL;

    while(result == NULL && i != this->listEdge.end()) {
        if((*i).getId() == id)
            result = &(*i);

        ++i;
    }

    return result;
}

Edge* Graph::getEdge (Vertice* src, Vertice* dst)
{
    for (int i=0; i<(int)(this->listEdge.size()); ++i)
    {
        if (this->listEdge[i].src->id == src->id && this->listEdge[i].dst->id == dst->id)
        {
            return &this->listEdge[i];
        }
    }

    return NULL;
}

void Graph::printAsMatrix() {
    int digits = getDigits(this->listVertices.size());
    int beforeSpaces;

    // before spaces
    for(int i = 0; i < digits+1; i++) { cout << " "; }

    // header numbers
    for(int i = 0; i < (int) this->listVertices.size(); i++) {
        cout << this->listVertices.at(i).getId() << "    ";
    }
    cout << endl;

    // print relations
    for(int i = 0; i < (int) this->listVertices.size(); i++) {
        cout << this->listVertices[i].getId();

        // before spaces
        beforeSpaces = digits - getDigits(this->listVertices[i].getId());
        for(int a = 0; a < beforeSpaces; a++) { cout << "  "; }

        for(int a = 0; a < (int) this->listVertices.size(); a++) {
            // before spaces
            beforeSpaces = getDigits(this->listVertices[a].getId()) - 1;
            for(int c = 0; c < beforeSpaces; c++) { cout << " "; }

            // print relation
            if(isLinked(this->listVertices[i].getId(), this->listVertices[a].getId())) {
                cout << this->getEdge(&listVertices[i], &listVertices[a])->cost;
                for (int k=0; k<5-getDigits(this->getEdge(&listVertices[i], &listVertices[a])->cost); ++k)
                    {
                        cout << " ";
                    }
            } else {
                cout << "     ";
            }
        }
        cout << endl;
    }
}

bool Graph::isLinked(int srcId, int dstId) {
    for(int i = 0; i < (int)this->listEdge.size(); i++) {
        if(this->listEdge[i].getSrcId() == srcId && this->listEdge[i].getDstId() == dstId) {
            return true;
        }
    }
    return false;
}

void Graph::loadFromFile(const char filepath[]) {
    ifstream file(filepath);

    std::string line;

    file >> line;
    int length = atoi(line.c_str());
    int value;
    cout << "file with " << length << " vertices" << endl;

    file >> line;
    if(line[0] == 'o' || line[0] == 'n') {
        bool notdirected = line[0] == 'n';

        file >> line;
        if(line[0] == 'm' || line[0] == 'l') {
            // first we make "length" vertices
            for(int i = 0; i < length; ++i) {
                this->listVertices.push_back(Vertice(i));
            }

            if(line[0] == 'm') {
                // we have a matrix

                // then we make the edges between the vertices thanks to the file
                for(int srcIndex = 0; srcIndex < length; ++srcIndex) {
                    for(int dstIndex = 0; dstIndex < length; ++dstIndex) {
                        file >> value;
                        if(value != 0) {
                            this->listEdge.push_back(Edge(srcIndex, &listVertices[srcIndex], &listVertices[dstIndex],value));
                            if(notdirected)
                                this->listEdge.push_back(Edge(srcIndex, &listVertices[dstIndex], &listVertices[srcIndex],value));

                            this->listVertices[srcIndex].addNeighbour(&this->listVertices[dstIndex]);
                        }
                        // file >> ";";
                    }
                    // file >> endl;
                }

                file.close();
                return;
            } else {
                // we have an adjency list

                string line="";
                getline(file, line);
                int originVertice = 0;
                while (getline(file, line))
                {
                    istringstream iss(line);
                    int destinationVertice;
                    //if (!(iss>>destinationVertice)){continue;}

                    while (iss>>destinationVertice)
                    {
                        this->listEdge.push_back(Edge(originVertice, &listVertices[originVertice], &listVertices[destinationVertice]));
                        if(notdirected)
                            this->listEdge.push_back(Edge(originVertice, &listVertices[destinationVertice], &listVertices[originVertice]));
                        // louis you forgot this important line
                        this->listVertices[originVertice].addNeighbour(&this->listVertices[destinationVertice]);
                    }
                    ++originVertice;
                }

                file.close();
                return;
            }
        }
    }

    file.close();

    cerr << "file read with an error while parsing";
    exit(1);
}

Graph::~Graph()
{
}

Graph Graph::getTransposed() {
    Graph g;

    g.typeOfGraph = this->typeOfGraph;

    // create all vertices with same ids
    for(int i = 0; i < (int) this->listVertices.size(); ++i) {
        g.listVertices.push_back(Vertice(this->listVertices[i].getId()));
    }

    // create inverted edges with same ids
    // add inverted neighbourEdge* getEdge (Vertice*, Vertice*);s
    for(int i = 0; i < (int) this->listEdge.size(); ++i) {
        g.listEdge.push_back(Edge(this->listEdge[i].getId(), g.getVertice(this->listEdge[i].getDstId()), g.getVertice(this->listEdge[i].getSrcId())));

        // add origin vertice to the neighbours of destination vertice
        g.getVertice(this->listEdge[i].getDstId())->addNeighbour(g.getVertice(this->listEdge[i].getSrcId()));
    }

    return g;
}
