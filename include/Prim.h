#ifndef PRIM_H
#define PRIM_H

#include "Vertice.h"
#include "Graph.h"


class Prim
{
    public:
        Prim();
        virtual ~Prim();
        Prim(const Prim& other);
        Prim& operator=(const Prim& other);

        void execute (Graph, Vertice);
        void affiche (Vertice)

    protected:

    private:
};

#endif // PRIM_H
