#include <iostream>
#include "include/Graph.h"

using namespace std;

int main()
{
    Graph h(19, 'o');
    h.saveAsMatrix("testMatrix.txt");
    Graph g("testMatrix.txt");
    g.printMap();
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
