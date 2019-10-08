#include <iostream>
#include "include/Graph.h"

using namespace std;

int main()
{
    Graph g(19);
    g.printMap();
    g.saveAsMatrix("testMatrix.txt");
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
    return 0;
}
