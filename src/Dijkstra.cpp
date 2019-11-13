#include <iostream>
#include <limits>
#include <set>
#include "Dijkstra.h"

Dijkstra::Dijkstra()
{
    //ctor
}

Dijkstra::~Dijkstra()
{
    //dtor
}

Dijkstra::Dijkstra(const Dijkstra& other)
{
    //copy ctor
}

Dijkstra& Dijkstra::operator=(const Dijkstra& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

bool Dijkstra::execute(Graph& g, int src, int dest){
    int PathDistance=0;
    if ((g.getVertice(src)->neighbours.size()==0)  ||  (src==dest)) {
        return false;
    }

    g.getVertice(src)->predecessor = NULL;

    int Max = numeric_limits<int>::max();

    set< pair<double, int> > setdest;
    set< pair<double, int> >::iterator tmp;

    vector<double> cost(g.listVertices.size(), Max);

    cost[src] = 0;
    setdest.insert(make_pair(cost[src], src));
    while (!setdest.empty() ){
        tmp = setdest.begin();
        int u = (*tmp).second;
        setdest.erase(setdest.begin());
        if (u == dest) break;
        if (g.listVertices[u].neighbours.size()==0) continue;

        // for each neighbour
        for (int i=0;i< (int) g.listVertices[u].neighbours.size();i++){
            // get neighbour id vertex ext ?
            int v = g.listVertices[u].neighbours[i]->id;

            // get edge id ?
            int idEdge = g.getEdge(&g.listVertices[u], &g.listVertices[v])->id;

            // get edge weight
            double weight= g.getEdge(idEdge)->cost;

            // if neighbour cost is greater than my cost and the weight
            if (cost[v] > cost[u] + weight ){
                // erase set UNKNOWN if UNKNOWN
                if (cost[v] != Max){
                    setdest.erase(setdest.find(make_pair(cost[v], v)));
                }

                // increase weight
                cost[v] = cost[u] + weight;

                // insert pair of cost
                setdest.insert(make_pair(cost[v], v));

                // make the predecessor of v u
                g.listVertices[v].predecessor = g.getVertice(u);
            }
        }
    }

    int curr = dest;
    cout << curr << "; ";

    // while the current Vertice is different from the source
    while (curr != src){
        // get the source id of current edge in list
        Edge* edge = g.getEdge(g.getVertice(curr), g.getVertice(curr)->predecessor);

        // increase path distance
        PathDistance += edge->cost;

        // update current to predecessor
        curr = g.listVertices[curr].predecessor->id;

        // print current edge id
        cout << curr << "; ";
    }

    // go to line
    cout << endl;

    // print distance
    cout << "Distance = " << PathDistance << endl;
    return true;
}
