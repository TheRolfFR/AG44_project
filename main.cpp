#include <iostream>
#include "include/Graph.h"
#include "DFS.h"

using namespace std;

int main()
{
    Graph g(19, 'o');
    g.PrintAsMatrix();
    DFS dfs;
    int* result = dfs.execute(g,g.getVertice(0));
    cout<<endl;
    dfs.print(g,result);
//
//    cout << endl;
//
//    Vertice *first = g.getVertice(5);
//    first->print();
//
//    cout << endl;
//
//    Edge *edge = g.getEdge(25);
//    edge->print();
    return 0;
}
