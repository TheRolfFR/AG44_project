#include "Prim.h"
#include <algorithm>
#include <bits/stdc++.h>

Prim::Prim()
{
    //ctor
}

Prim::~Prim()
{
    //dtor
}

Prim::Prim(const Prim& other)
{
    //copy ctor
}

Prim& Prim::operator=(const Prim& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Prim::execute (Graph g, Vertice v)
{

    int n = g.listVertices.size();
    int a = std::numeric_limits<int>::max();

    vector<Vertice*> q;

    for (int i=0;i<n;++i)
    {
        g.listVertices[i].dist = a;
        g.listVertices[i].predecessor = NULL;
        q.push_back (&g.listVertices[i]);
    }
    v.dist = 0;

    while (q.size() > 0)
    {
        sort(q.begin(),q.end());
        Vertice* pv = q.front();
        q.erase(q.begin());

        for (unsigned int i=0; i<pv->neighbours.size(); ++i)
        {
            if (std::find(q.begin(), q.end(), pv->neighbours[i])!=q.end() && g.getEdge(pv,pv->neighbours[i])->cost < pv->neighbours[i]->dist)
            {
                pv->neighbours[i]->predecessor = pv;
                pv->neighbours[i]->dist = g.getEdge(pv,pv->neighbours[i])->cost;
            }
        }
    }
}
