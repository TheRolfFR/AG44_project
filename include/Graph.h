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
        Graph(int, char);
        virtual ~Graph();
        void print();
        Vertice* getVertice(int);
        void saveAsMatrix(const char[]);
        Edge* getEdge(int);
        void printMap();

    private:
        char typeOfGraph; // 'o' for directed, 'n' for undirected
        vector<Vertice> listVertices;
        vector<Edge> listEdge;
        int ** cost;
        bool isLinked(int, int);
};

#endif // GRAPH_H
