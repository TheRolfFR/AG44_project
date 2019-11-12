#include "StronglyRelated.h"

StronglyRelated::StronglyRelated() : dfs()
{
    //ctor
}

StronglyRelated::~StronglyRelated()
{
    //dtor
}

StronglyRelated::StronglyRelated(const StronglyRelated& other) : dfs(other.dfs)
{
    //copy ctor
}

StronglyRelated& StronglyRelated::operator=(const StronglyRelated& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void StronglyRelated::execute(Graph& g) {
    int* firstResult = dfs.execute(g, &g.listVertices[0]);
    Graph h = g.getTransposed();
    int* secondResult = dfs.execute(h, firstResult);
}
