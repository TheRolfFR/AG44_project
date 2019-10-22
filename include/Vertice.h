#ifndef VERTICE_H
#define VERTICE_H
#include <iostream>
#include <vector>

using namespace std;

class Vertice
{
    friend class BFS:
    friend class DFS;
    friend class Graph;
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
        Vector *predecessor;

        int startDepth;
        int endDepth;

        int id;
        vector<Vertice*> neighbours;
};

#endif // VERTICE_H
