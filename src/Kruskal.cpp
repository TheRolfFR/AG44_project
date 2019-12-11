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
void Kruskal::printResult(Graph g) {
    cout << "=== result of Kruskal ===" << endl;
    g.printAsMatrix();
}

Graph Kruskal::execute(Graph& g) {
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

    //debug print result
//    printResult(edgeSet);

    //make a new graph from this set of edges
    Graph result;

    // copy vertices
    for(std::set<Vertice*>::iterator it=verticeSet.begin(); it!=verticeSet.end(); ++it) {
       result.listVertices.push_back(Vertice(*(*it)));
       result.listVertices.back().neighbours.clear();
    }

    // copy edges
    Edge* tmp;
    int id = 0;
    for(std::set<Edge*>::iterator it=edgeSet.begin(); it!=edgeSet.end(); ++it){
        tmp = (*it);
        Edge clone = Edge(*tmp);
        clone.setId(id); ++id;
        result.listEdge.push_back(clone);
        // add reverse edge because this graph is undirected
        result.listEdge.push_back(Edge(id, tmp->dst, tmp->src, tmp->cost)); ++id;

        // add respective neighbours
        result.getVertice(tmp->src->id)->addNeighbour(result.getVertice(tmp->dst->id));
        result.getVertice(tmp->dst->id)->addNeighbour(result.getVertice(tmp->src->id));
    }

    return result;
}

//void Kruskal::print(std::vector<TreeNode*> trees) {
//    for(int i = 0; i < (int) trees.size(); ++i) {
//        trees[i]->print();
//    }
//}
