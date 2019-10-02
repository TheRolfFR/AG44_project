#ifndef GRAPH_H
#define GRAPH_H
#include "Vertice.h"
#include "Edge.h"
#include <iostream>
#include <vector>

class Graph
{
    public:
        Graph(int);
        virtual ~Graph();
        void print();
        Vertice* getVertice(int);
        Edge* getEdge(int);
        bool isLinked(int, int);

    private:
        vector<Vertice> listVertices;
        vector<Edge> listEdge;
        int ** cost;
};

#endif // GRAPH_H
