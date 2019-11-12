#include <iostream>
#include "include/Graph.h"
#include "DFS.h"
#include "BFS.h"
#include "Timer.h"

using namespace std;

int main()
{

    Graph g(19, 'o');

    g.PrintAsMatrix();

    cout << "2*transposed: " << endl;
    Graph h = g.getTransposed();
    Graph i = h.getTransposed();
    i.PrintAsMatrix();

    return 0;
}
