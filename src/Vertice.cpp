#include "../include/Vertice.h"
#include <vector>

Vertice::Vertice(int id)
{
    this->id = id;
}

void Vertice::setId(int id) {
    this->id = id;
}

int Vertice::getId() {
    return this->id;
}

Vertice::~Vertice()
{
}

void Vertice::addNeighbour(Vertice* neighbour) {
    this->neighbours.push_back(neighbour);
}

void Vertice::print() {
    for(auto i = this->neighbours.begin(); i != this->neighbours.end(); ++i) {
        cout << "V#" << this->id << " has neighbour V#" << (*i)->getId() << endl;
    }
}
