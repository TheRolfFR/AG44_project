#include <iostream>
#include "include/Graph.h"
#include "DFS.h"
#include "BFS.h"
#include "Timer.h"
#include "TopologicalSort.h"

using namespace std;

int main()
{
    Graph g("testAdgency.txt");
    g.PrintAsMatrix();
    g.printAsList();
    BFS bfs;
    DFS dfs;
    TopologicalSort tps;

    int* res = dfs.execute(g, g.getVertice(0));
    dfs.print(g, res);
    res = tps.execute(g,g.getVertice(0));
    dfs.print(g, res);

    /*Timer timer;

    cout << endl << "BFS: ";
    timer.start();
    int* result = bfs.execute(g, g.getVertice(0));
    cout << timer.stop() << "s" << endl;
    //bfs.printResult(result, g);

    cout << "DFS: ";
    timer.start();
    int* res = dfs.execute(g, g.getVertice(0));
    cout << timer.stop() << "s" << endl;
    //dfs.print(g, res);
    return 0;*/
}
