#include <iostream>
#include "include/Graph.h"
#include "DFS.h"
#include "BFS.h"
#include "Timer.h"

using namespace std;

int main()
{
<<<<<<< HEAD
    Graph g("europe.txt");
    //g.printAsList();

=======
    Graph g("testAdgency.txt");
    g.PrintAsMatrix();
    g.printAsList();
>>>>>>> b634d3012bd7e6b4f197bab948c1e08f69a75e58
    BFS bfs;
    DFS dfs;
    Timer timer;

    cout << endl << "BFS: ";
    timer.start();
    int* result = bfs.execute(g, g.getVertice(6));
    cout << timer.stop() << "s" << endl;
    bfs.printResult(result, g);

    cout << "DFS: ";
    timer.start();
    int* res = dfs.execute(g, g.getVertice(6));
    cout << timer.stop() << "s" << endl;
    dfs.print(g, res);
    return 0;
}
