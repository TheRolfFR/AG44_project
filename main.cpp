#include <iostream>
#include "include/Graph.h"
#include "DFS.h"
#include "BFS.h"
#include "Timer.h"
#include "TopologicalSort.h"
#include "StronglyRelated.h"

using namespace std;

int main()
{
    Graph g("exStronglyConnected.txt");

    g.PrintAsMatrix();

    StronglyRelated r;
    int* result = r.execute(g);

    r.print(g, result);
}
