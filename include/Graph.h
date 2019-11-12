#ifndef GRAPH_H
#define GRAPH_H
#include "Vertice.h"
#include "Edge.h"
#include <iostream>
#include <vector>

class Graph
{
    friend class BFS;
    friend class DFS;
    friend class StronglyRelated;
    public:
        Graph();
        Graph(int);
        Graph(int, char);
        Graph(const char *);
        virtual ~Graph();
        void print();
        Vertice* getVertice(int);
        Edge* getEdge(int);
        void PrintAsMatrix();
        void printAsList();
        void saveAsMatrix(const char*);
        void saveAsAdjencyList(const char*);
        void loadFromFile(const char*);
        Graph getTransposed();

    private:
        char typeOfGraph; // 'o' for directed, 'n' for undirected
        vector<Vertice> listVertices;
        vector<Edge> listEdge;
        int ** cost;
        bool isLinked(int, int);
        void generateRandomGraph(int, char);
};

#endif // GRAPH_H
