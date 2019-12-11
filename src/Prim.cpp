#include "Prim.h"
#include <algorithm>
#include <bits/stdc++.h>
#include "TreeNode.h"

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

bool Prim::find(vector<Vertice*> q, Vertice* pv) {
    bool result = false;

    unsigned int i = 0;
    while(i < q.size() && !result) {
        if(*q[i] == *pv)
            result = true;
        ++i;
    }

    return result;
}

bool cmp (Vertice* i,Vertice* j) { return (i->dist <j->dist); }

bool Prim::execute (Graph g, Vertice v)
{
    int n = g.listVertices.size();
    int a = std::numeric_limits<int>::max()-1;

    vector<Vertice*> q;

    for (int i=0;i<n;++i)
    {
        g.listVertices[i].dist = a;
        g.listVertices[i].predecessor = NULL;
        Vertice* tmp = &g.listVertices[i];
        q.push_back (tmp);
    }
    v.dist = 0;

    while (q.size() > 0)
    {
        sort(q.begin(),q.end(), cmp);
        Vertice* pv = q.front();
        q.erase(q.begin());

        for (int i=0; i< (int) pv->neighbours.size(); ++i)
        {
            if (this->find(q, pv->neighbours[i]) && g.getEdge(pv,pv->neighbours[i])->cost < pv->neighbours[i]->dist)
            {
                g.getVertice(pv->neighbours[i]->id)->predecessor = g.getVertice(pv->id);
                g.getVertice(pv->neighbours[i]->id)->dist = g.getEdge(pv,pv->neighbours[i])->cost;
            }
        }
    }

    std::cout << "=== Prim result === " << std::endl;
    int nbOfRoot = 0;
    for(unsigned int i = 0; i < g.listVertices.size(); ++i) {
        if(g.listVertices[i].predecessor == NULL){
            ++nbOfRoot;
        }
    }
    if(nbOfRoot == 1) {
        std::cout << "You can build a tree" << std::endl;
        vector<TreeNode> resultTreeNodes;
        TreeNode* rootNode;

        // create all nodes
        for(unsigned int i = 0; i < g.listVertices.size(); ++i) {
            resultTreeNodes.push_back(TreeNode(g.listVertices[i].id, NULL));
        }

        // put predecessors
        for(unsigned int i = 0; i < g.listVertices.size(); ++i) {
            if(g.listVertices[i].predecessor != NULL)
                resultTreeNodes[g.listVertices[i].predecessor->id].addChild(&resultTreeNodes[g.listVertices[i].id]);
            else
                rootNode = &resultTreeNodes[g.listVertices[i].id];
        }

        rootNode->print();
        return true;
    }
    else
        std::cout << "You can't build a tree" << std::endl;

    return false;
}
