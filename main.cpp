#include <iostream>

#include "include/Graph.h"

#include "BFS.h"
#include "DFS.h"
#include "Dijkstra.h"
#include "Kruskal.h"
#include "Prim.h"
#include "StronglyRelated.h"
#include "TopologicalSort.h"
#include "StronglyRelated.h"
#include "WarshallFloyd.h"

int main()
{
     // 'o' for directed, 'n' for undirected
    Graph g(11, 'o', 1, 20);
    // Graph g(11); // generate an undirected graph with 11 vertices
    // Graph g(11, 'o'); // generate an directed graph with 11 vertices
    // Graph g(11, 'o', 1, 20, true); // generate a complete graph
    // Graph g("RoumanieMatrix.txt"); // load a file
    // g.saveAsAdjencyList("filename.txt"); // save as adjency list
    // g.saveAsMatrix("filename.txt") // save as matrix
    // g.getTransposed(); // return g^t

    g.printAsMatrix();

    BFS bfs;
    bfs.printResult(bfs.execute(g, g.getVertice(1)), g);

    DFS dfs;
    dfs.execute(g, g.getVertice(1));
    dfs.printLatestTree();

    Dijkstra dij;
    dij.execute(g, 1, 10);

    Kruskal kr;
    Graph res = kr.execute(g);
    res.printAsMatrix();

    Prim pr;
    pr.execute(g, g.getVertice(1));

    StronglyRelated sr;
    sr.execute(g);
    sr.printLatestTree();

    TopologicalSort ts;
    ts.execute(g, g.getVertice(1));

    WarshallFloyd wf;
    Graph h = wf.execute(g);
    h.printAsMatrix();

    return 0;
}
