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
    friend class TopologicalSort;
    friend class StronglyRelated;
    friend class Dijkstra;

    public:
        Graph();
        Graph(int);
        Graph(int, char);
        Graph(const char *);
        Graph(int, char, int, int);
        virtual ~Graph();
        void print();
        Vertice* getVertice(int);
        Edge* getEdge(int);
        Edge* getEdge (Vertice*, Vertice*);
        void printAsMatrix();
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
        void generateRandomGraph(int, char, int, int);
};

#endif // GRAPH_H
