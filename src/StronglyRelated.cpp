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

int* StronglyRelated::execute(Graph& g) {
    int* firstResult = dfs.execute(g, &g.listVertices[0]);
    Graph h = g.getTransposed();
    return dfs.execute(h, firstResult);
}

void StronglyRelated::print (Graph& graph, int* result)
{
    dfs.print(graph, result);
    cout << endl;

    // reset colors
    for(int i = 0; i < (int) graph.listVertices.size(); i++) {
        graph.listVertices[i].color = 'w';
    }

    int lastId = -1, p;
    Vertice* predecessor = NULL;
    for(int i = 0; i < (int) graph.listVertices.size(); i++) {
        // if first one or it is not visited then display it
        if(lastId == -1 || graph.listVertices[i].color == 'w') {
            // if first one display arrow
            if(lastId == -1) {
                // first one
                cout << "[ " << result[i];
                lastId = result[i];
            } else {
                // not first one and not visited
                bool hasPredecessor = false;
                predecessor = graph.getVertice(lastId);

                p = 0;
                while(p < (int) predecessor->neighbours.size() && !hasPredecessor) {
                    hasPredecessor = predecessor->neighbours[p]->id == result[i];
                    ++p;
                }

                // if this one is a predecessor of the old id then display an arrow and the id
                if(hasPredecessor) {
                    cout << " -> " << result[i];
                } else // else go to line with new graph
                {
                    cout << " ]" << endl << "[ " << result[i];
                }

                lastId = result[i];
            }
        }

        graph.getVertice(result[i])->color = 'g';
    }

    cout << " ]" << endl;
}
