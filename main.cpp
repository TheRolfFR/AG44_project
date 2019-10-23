#include <iostream>
#include "include/Graph.h"
<<<<<<< HEAD
#include "DFS.h"
=======
#include "BFS.h"
>>>>>>> 73ba4e8b0804cbfc57bbca92720a1e1bf60eae90

using namespace std;

int main()
{
<<<<<<< HEAD
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
=======
    Graph g("testMatrix.txt");
    g.printAsList();
    BFS bfs;
    int* result = bfs.execute(g, g.getVertice(0));
    bfs.printResult(result, g);
>>>>>>> 73ba4e8b0804cbfc57bbca92720a1e1bf60eae90
    return 0;
}
