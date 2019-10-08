#include "../include/Graph.h"
#include "../include/Vertice.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <fstream>

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

Graph::Graph(int nVertices) : typeOfGraph('n')
{
    if(nVertices > 0) {
        srand(time(NULL));

        for(int i = 0; i < nVertices; i++) {
            this->listVertices.push_back(Vertice(i));
        }

        int id = 0;
        for(int a = 0; a < nVertices; a++) {
            for(int b = 0; b < nVertices; b++) {
                if(a != b && rand()%2 == 1) {
                    this->listEdge.push_back(Edge(id, &this->listVertices[a], &this->listVertices[b]));
                    // this->listEdge.push_back(Edge(id, &this->listVertices[b], &this->listVertices[a])); // DIAGONAL
                    id++;
                    this->listVertices[a].addNeighbour(&this->listVertices[b]);
                    this->listVertices[b].addNeighbour(&this->listVertices[a]);
                }
            }
        }
    } else {
        cerr << "needs a positive number of vertices, given " << nVertices;
        exit(-1);
    }
}

Graph::Graph(int nVertices, char tOfGraph): typeOfGraph(tOfGraph) {}

void Graph::print() {
    cout << "graph with " << this->listVertices.size() << " vertices and " << this->listEdge.size() << " edges" << endl;
    for(auto i = this->listVertices.begin(); i != this->listVertices.end(); ++i) {
        (*i).print();
    }
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
                file << "1";
            } else {
                file << "0";
            }
            file << ";";
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

void Graph::printMap() {
    int digits = getDigits(this->listVertices.size());
    int beforeSpaces;

    // before spaces
    for(int i = 0; i < digits+1; i++) { cout << " "; }

    // header numbers
    for(int i = 0; i < (int) this->listVertices.size(); i++) {
        cout << this->listVertices.at(i).getId() << " ";
    }
    cout << endl;

    // print relations
    for(int i = 0; i < (int) this->listVertices.size(); i++) {
        cout << this->listVertices[i].getId();

        // before spaces
        beforeSpaces = digits - getDigits(this->listVertices[i].getId());
        for(int a = 0; a < beforeSpaces; a++) { cout << " "; }

        for(int a = 0; a < (int) this->listVertices.size(); a++) {
            // before spaces
            beforeSpaces = getDigits(this->listVertices[a].getId()) - 1;
            for(int c = 0; c < beforeSpaces; c++) { cout << " "; }

            // print relation
            if(isLinked(this->listVertices[i].getId(), this->listVertices[a].getId())) {
                cout << " X";
            } else {
                cout << "  ";
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

Graph::~Graph()
{
    //free(this->listEdge);
}
