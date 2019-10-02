#include "../include/Edge.h"
#include "../include/Vertice.h"

using namespace std;

void Edge::setId(int id) {
    this->id = id;
}

Edge::Edge(int id, Vertice* source, Vertice* dest)
{
    this->id = id;
    this->src = source;
    this->dst = dest;
}

Edge::~Edge()
{
    //dtor
}

void Edge::print() {
    cout << "edge #" << id << " between " << src->getId() << " and " << dst->getId() << endl;
}

int Edge::getId() {
    return this->id;
}
