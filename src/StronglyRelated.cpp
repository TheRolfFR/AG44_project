#include "StronglyRelated.h"
#include <vector>

StronglyRelated::StronglyRelated() : dfs() , tos()
{
    //ctor
}

StronglyRelated::~StronglyRelated()
{
    //dtor
}

StronglyRelated::StronglyRelated(const StronglyRelated& other) : dfs(other.dfs), tos(other.tos)
{
    //copy ctor
}

StronglyRelated& StronglyRelated::operator=(const StronglyRelated& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    this->dfs = rhs.dfs;
    this->tos = rhs.tos;

    return *this;
}

int* StronglyRelated::execute(Graph& g) {
    int* firstResult = tos.execute(g, &g.listVertices[0]);

    Graph h = g.getTransposed();

    int* r = dfs.execute(h, firstResult);
    return r;
}

void StronglyRelated::printLatestTree()
{
    std::cout << std::endl << "=== Result of last StronglyRelated execution ===" << std::endl;
    dfs.printLatestTree();
}
