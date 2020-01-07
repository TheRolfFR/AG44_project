#include "TopologicalSort.h"


TopologicalSort::TopologicalSort():dfs()
{
    //ctor
}

TopologicalSort::~TopologicalSort()
{
    //dtor
}

TopologicalSort::TopologicalSort(const TopologicalSort& other):dfs(other.dfs)
{
    //copy ctor
}

TopologicalSort& TopologicalSort::operator=(const TopologicalSort& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

int* TopologicalSort::execute (Graph& graph, Vertice* s)
{
    int* res = dfs.execute(graph, s);
    int taille = (int)(graph.listVertices.size());
    int v;
    int j = 0;
    for (int i = taille; i>1; i-=2)
    {
        v = res[j];
        res[j]=res[taille-j-1];
        res[taille-j-1] = v;
        ++j;
    }
    return res;
}
