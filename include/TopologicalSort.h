#ifndef TOPOLOGICALSORT_H
#define TOPOLOGICALSORT_H
#include "DFS.h"
#include "Graph.h"
#include "Vertice.h"


class TopologicalSort
{
    public:
        TopologicalSort();
        virtual ~TopologicalSort();
        TopologicalSort(const TopologicalSort& other);
        TopologicalSort& operator=(const TopologicalSort& other);

        int* execute (Graph&, Vertice*);

    protected:

    private:
        DFS dfs;
};

#endif // TOPOLOGICALSORT_H
