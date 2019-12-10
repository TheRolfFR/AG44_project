#include "Kruskal.h"
#include <bits/stdc++.h>
#include <limits>
#include <set>

Kruskal::Kruskal()
{
    //ctor
}

Kruskal::~Kruskal()
{
    //dtor
}

Kruskal::Kruskal(const Kruskal& other)
{
    //copy ctor
}

Kruskal& Kruskal::operator=(const Kruskal& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Kruskal::EraseElementFromVector(vector<TreeNode*> myvector, TreeNode* node) {
    if(node == NULL)
        return;

    int i = 0;
    int foundIndex = -1;
    while(i < (int) myvector.size() && foundIndex != -1) {
        if(myvector[i]->id == node->id)
            foundIndex = i;

        ++i;
    }
}

bool Kruskal::containsAtMostOne(const set<Vertice*> vertices, Vertice* u, Vertice* v) {
    bool foundU = std::find(vertices.begin(), vertices.end(), u) != vertices.end();
    bool foundV = std::find(vertices.begin(), vertices.end(), v) != vertices.end();

    return !(foundU && foundV);
}

bool Kruskal::contains(const set<Vertice*> vertices, Vertice* u) {
    return std::find(vertices.begin(), vertices.end(), u) != vertices.end();
}

void Kruskal::printResult(const set<Edge*>& edges) {
    for(std::set<Edge*>::iterator it=edges.begin(); it!=edges.end(); ++it)
       (*it)->print();
}

set<Edge*> Kruskal::execute(Graph& g) {
    // sort edges by decreasing order
    sort(g.listEdge.begin(), g.listEdge.end());

    // initialize full things
    set<Vertice*> verticeSet;
    set<Edge*>edgeSet;
    for(unsigned int i = 0; i < g.listEdge.size(); i++) {
        Edge& e = g.listEdge[i];
        if(containsAtMostOne(verticeSet, e.src, e.dst)) {
            edgeSet.insert(&e);
            if(!contains(verticeSet, e.src))
                verticeSet.insert(e.src);
            if(!contains(verticeSet, e.dst))
                verticeSet.insert(e.dst);
        }
    }
    return edgeSet;
}

//void Kruskal::print(std::vector<TreeNode*> trees) {
//    for(int i = 0; i < (int) trees.size(); ++i) {
//        trees[i]->print();
//    }
//}
