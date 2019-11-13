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
            // get neighbour id ?
            int v = g.listVertices[u].neighbours[i].first;

            // get edge id ?
            int idEdge = g.listVertices[u].neighbours[i].second;

            // get edge weight
            double weight= g.LstEdges[idEdge]->dist;

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
                g.listVertices[v]->predecessor = u;

                // make ?
                g.listVertices[v]->PreviousEdgeId = g.listVertices[u].neighbours[i].second;
            }
        }
    }

    int curr = dest;
    cout << curr->id << "; ";

    // while the current Vertice is different from the source
    while (curr != src){
        // get the source id of current edge in list
        int idEdge=g.listEdge[curr]->PreviousEdgeId;
        // get the corresponding edge
        Edge* edge = g.LstEdges[idEdge];
        // increase the path distance by its cost
        PathDistance += edge->dist;
        // update current to predecessor
        curr = g.listEdge[curr]->Pred;

        // print current edge id
        cout << curr->id << "; ";
    }

    // go to line
    cout << endl;

    // print distance
    cout<< << "Distance = " << PathDistance << endl;
    return true;
}
