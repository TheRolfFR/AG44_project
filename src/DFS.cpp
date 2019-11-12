#include "DFS.h"
#include "Constants.h"
#include <vector>

DFS::DFS()
{
    //ctor
}

DFS::~DFS()
{
    //dtor
}

DFS::DFS(const DFS& other)
{
    //copy ctor
}

DFS& DFS::operator=(const DFS& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

int* DFS::execute (Graph& graph, Vertice* s)
{
    int* result = new int[graph.listVertices.size()];
    this->resultIndex = 0;
    lastResults.push_back(result);

    for (int i = 0; i<int(graph.listVertices.size());++i)
    {
        graph.listVertices[i].color = 'w';
        graph.listVertices[i].predecessor = NULL;
    }
    this->time = 0;
    this->visit(graph,s);
    for (int i=0;i<int(graph.listVertices.size());++i)
    {
        if (graph.listVertices[i].color == 'w')
        {
            this->visit(graph, &graph.listVertices[i]);
        }
    }
    return result;
}

// uses array of vertices
int* DFS::execute (Graph& graph, int* enterArray)
{
    int* result = new int[graph.listVertices.size()];
    this->resultIndex = 0;
    lastResults.push_back(result);

    for (int i = 0; i<(int)(graph.listVertices.size());++i)
    {
        graph.listVertices[i].color = 'w';
        graph.listVertices[i].predecessor = NULL;
    }
    this->time = 0;

    Vertice *s = graph.getVertice(enterArray[0]);

    this->visit(graph,s);
    // for each element in coming result array
    for (int i=0;i<int(graph.listVertices.size());++i)
    {
        if (s[i].color == 'w')
        {
            this->visit(graph, s+i);
        }
    }
    return result;
}

void DFS::visit (Graph& graph,Vertice* u)
{
    int* result = this->lastResults.back();
    ++ this->time;
    u->dist = this->time;
    u->color = 'g';
    for (int i=0; i < int(u->neighbours.size()); ++i)
    {
        if (u->neighbours[i]->color == 'w')
        {
            u->neighbours[i]->predecessor = u;
            this->visit(graph,u->neighbours[i]);
        }
    }
    u->color ='b';
    ++ this->time;
    u->endDepth = time;
    result[resultIndex] = u->id;
    ++ resultIndex;
}

void DFS::print (const Graph& graph, int* result)
{
    cout << "[ ";
    for(int i = 0; i < (int) graph.listVertices.size(); i++) {
        cout << result[i] << " ";
    }
    cout << "]" << endl;
}
