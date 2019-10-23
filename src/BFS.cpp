#include "BFS.h"
#include <queue>

BFS::BFS() : lastResults(), resultIndex(0)
{
    //ctor
}

BFS::~BFS()
{
    //dtor
}

BFS::BFS(const BFS& other) : lastResults(other.lastResults), resultIndex(other.resultIndex)
{
    //copy ctor
}

BFS& BFS::operator=(const BFS& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
int* BFS::execute(Graph& graph, Vertice* s) {
    int *result = new int[graph.listVertices.size()];
    resultIndex = 0;
    lastResults.push_back(result); // memory leak safety

    for(int i = 0; i < (int) graph.listVertices.size(); ++i) {
        result[i] = -1;
        Vertice& v = graph.listVertices[i];
        v.color = 'w';
        v.dist = 1;
        v.predecessor = NULL;
    }

    s->color = 'w';
    s->dist = 0;
    s->predecessor = NULL;
    this->visit(s);

    // loop for strongly connected graphs
    for(int i = 0; i < (int) graph.listVertices.size(); ++i) {
        if(graph.listVertices[i].color == 'w') {
            this->visit(&graph.listVertices[i]);
        }
    }

    return result;
}
void BFS::visit(Vertice* s) {
    queue <Vertice*> Q;
    int* result = this->lastResults.back();

    cout << "visit from" << s->id << endl;

    Vertice *u, *v;
    Q.push(s);
    while(!Q.empty()) {
        // dequeue
        u = Q.front();
        Q.pop();
        cout << "dequeuing " << u->id << endl;

        result[resultIndex] = u->id;
        ++resultIndex;

        for(int i = 0; i < (int) u->neighbours.size(); ++i) {
            v = u->neighbours[i];
            if(v->color == 'w') {
                v->color = 'g';
                v->dist = u->dist + 1;
                v->predecessor = u;
                // enqueue
                Q.push(v);
                cout << " queuing " << v->id << endl;
            }
        }
        u->color = 'b';
    }
}

void BFS::printResult(int* result, Graph& graph) {
    cout << "[ ";
    for(int i = 0; i < (int) graph.listVertices.size(); i++) {
        cout << result[i] << " ";
    }
    cout << "]";
}
