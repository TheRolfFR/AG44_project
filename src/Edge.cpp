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
    this->cost = 0;
}

Edge::Edge(int id, Vertice* source, Vertice* dest, int cost)
{
    this->id = id;
    this->src = source;
    this->dst = dest;
    this->cost = cost;
}

Edge::~Edge()
{
    //dtor
}

void Edge::print() {
    cout << "edge #" << id << " between " << src->getId() << " and " << dst->getId() << " (cost "<< cost <<")" << endl;
}

int Edge::getId() {
    return this->id;
}

int Edge::getSrcId() {
    return this->src->getId();
}

int Edge::getDstId() {
    return this->dst->getId();
}
