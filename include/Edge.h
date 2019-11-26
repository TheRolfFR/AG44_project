#ifndef EDGE_H
#define EDGE_H
#include "Vertice.h"


class Edge
{
    friend class Graph;
    friend class Dijkstra;
    friend bool operator<(Edge&, Edge&);
    friend class Kruskal;

    public:
        Edge(int, Vertice*, Vertice*);
        Edge(int, Vertice*, Vertice*, int);
        virtual ~Edge();
        void setId(int);
        void print();
        int getId();
        int getSrcId();
        int getDstId();

    private:
        int id;
        short direction;
        int cost;
        Vertice* src;
        Vertice* dst;
};

bool operator<(Edge&, Edge&);

#endif // EDGE_H
