#include <iostream>
#include "include/Graph.h"
#include "WarshallFloyd.h"
#include "StronglyRelated.h"
#include "Prim.h"
#include "Kruskal.h"
#include "TopologicalSort.h"
#include "StronglyRelated.h"

using namespace std;

int main()
{
    Graph g(11, 'o', 1, 20);
    g.printAsMatrix();

    DFS dfs;
    Prim prim;
    Kruskal kr;
    StronglyRelated sr;

    sr.execute(g);
    sr.printLatestTree();

    return 0;
}
