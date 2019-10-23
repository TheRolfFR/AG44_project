#include <iostream>
#include "include/Graph.h"
#include "DFS.h"
#include "BFS.h"
#include "Timer.h"

using namespace std;

int main()
{
    Graph g("testAdgency.txt");
    g.PrintAsMatrix();
    g.printAsList();
    BFS bfs;
    DFS dfs;
    Timer timer;

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
    return 0;
}
