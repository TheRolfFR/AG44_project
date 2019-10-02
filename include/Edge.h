#ifndef EDGE_H
#define EDGE_H
#include "Vertice.h"


class Edge
{
    public:
        Edge(int, Vertice*, Vertice*);
        virtual ~Edge();
        void setId(int);
        void print();
        int getId();

    private:
        int id;
        short direction;
        Vertice* src;
        Vertice* dst;
};

#endif // EDGE_H
