#include <iostream>
#include "include/Graph.h"
#include "BFS.h"

using namespace std;

int main()
{
    Graph g("testMatrix.txt");
    g.printAsList();
    BFS bfs;
    int* result = bfs.execute(g, g.getVertice(0));
    bfs.printResult(result, g);
    return 0;
}
