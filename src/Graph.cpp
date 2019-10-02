#include "../include/Graph.h"
#include "../include/Vertice.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>


using namespace std;

Graph::Graph(int nVertices)
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

bool Graph::isLinked(int srcId, int dstId) {
    for(auto i = this->listEdge.begin(); b != )
}

Graph::~Graph()
{
    //free(this->listEdge);
}
