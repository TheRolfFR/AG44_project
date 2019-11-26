#include "WarshallFloyd.h"
#include <math.h>
#include <algorithm>

WarshallFloyd::WarshallFloyd()
{
    //ctor
}

WarshallFloyd::~WarshallFloyd()
{
    //dtor
}

WarshallFloyd::WarshallFloyd(const WarshallFloyd& other)
{
    //copy ctor
}

WarshallFloyd& WarshallFloyd::operator=(const WarshallFloyd& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

Graph WarshallFloyd:: execute(Graph& g)
{
    int n = g.listVertices.size();
    int a = std::numeric_limits<int>::max()/2;
    Graph res(n,'o',a,a,true);

    //initialize res
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if (g.isLinked(g.listVertices[i].getId(),g.listVertices[j].getId()))
                res.getEdge(&res.listVertices[i],&res.listVertices[j])->cost=g.getEdge(&g.listVertices[i],&g.listVertices[j])->cost;
        }
    }
    //find the shortest path
    for (int k=0; k<n; ++k)
    {
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (i!=j && i!=k && j!=k)
                    res.getEdge(&res.listVertices[i],&res.listVertices[j])->cost=std::min(res.getEdge(&res.listVertices[i],&res.listVertices[j])->cost,res.getEdge(&res.listVertices[i],&res.listVertices[k])->cost+res.getEdge(&res.listVertices[k],&res.listVertices[j])->cost);
            }
        }
    }
    return res;
}
