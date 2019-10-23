#include <iostream>
#include "include/Graph.h"
#include "DFS.h"
#include "BFS.h"

using namespace std;

int main()
{
    Graph g("testMatrix.txt");
    g.PrintAsMatrix();
    BFS bfs;
    int* result = bfs.execute(g, g.getVertice(0));
    cout << endl << "BFS: ";
    bfs.printResult(result, g);
    DFS dfs;
    cout << "DFS: ";
    int* res = dfs.execute(g, g.getVertice(0));
    dfs.print(g, res);
    return 0;
}
