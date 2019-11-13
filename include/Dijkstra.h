#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "Graph.h"

class Dijkstra
{
    public:
        Dijkstra();
        virtual ~Dijkstra();
        Dijkstra(const Dijkstra& other);
        Dijkstra& operator=(const Dijkstra& other);
        bool execute(Graph&, int, int);

    protected:

    private:
};

#endif // DIJKSTRA_H
