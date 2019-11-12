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
    Graph h = graph.getTransposed();
    h.PrintAsMatrix();

    dfs.print(graph, result);
    cout << endl;

    // reset colors
    for(int i = 0; i < (int) h.listVertices.size(); ++i) {
        h.listVertices[i].color = 'w';
    }

    int lastId = -1, p;
    Vertice* currentVertice = NULL;
    for(int i = 0; i < (int) graph.listVertices.size(); ++i) {
        // if first one or it is not visited then display it
        if(lastId == -1 ) {
            cout << "[ " << result[i];
        } else {
            // not first one and not visited
            bool canGoSomewhere = false;
            currentVertice = h.getVertice(result[i]);

            p = 0;
            while(p < (int) currentVertice->neighbours.size() && !canGoSomewhere) {
                canGoSomewhere = currentVertice->neighbours[p]->color == 'w';
                ++p;
            }

            // display arrow
            cout << " -> " << result[i];
            // if you can't go somewhere its end
            if(!canGoSomewhere) {
                cout << " ]" << endl << "[ ";
            }

        }

        lastId = result[i];

        graph.getVertice(result[i])->color = 'g';
    }

    cout << " ]" << endl;
}
