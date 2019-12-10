#ifndef VERTICE_H
#define VERTICE_H
#include <iostream>
#include <vector>

using namespace std;

class Vertice
{
    friend bool compareDistance(Vertice* a, Vertice* b);
    friend class BFS;
    friend class DFS;
    friend class Graph;
    friend class StronglyRelated;
    friend class Dijkstra;
    friend class Prim;
    friend bool operator<(Vertice&, Vertice&);

    public:
        Vertice(int);
        virtual ~Vertice();
        void setId(int);
        int getId();
        void addNeighbour(Vertice*);
        void print();

    protected:

    private:
        char color;
        int dist;
        Vertice* predecessor;

        int startDepth;
        int endDepth;

        int id;
        vector<Vertice*> neighbours;
};

bool operator<(Vertice&, Vertice&);

#endif // VERTICE_H

