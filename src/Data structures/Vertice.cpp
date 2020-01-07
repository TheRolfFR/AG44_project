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

bool operator<(Vertice& Vertice1, Vertice& Vertice2) {
    return Vertice1.dist < Vertice2.dist;
}

bool operator==(Vertice& Vertice1, Vertice& Vertice2) {
    return Vertice1.id == Vertice2.id;
}
