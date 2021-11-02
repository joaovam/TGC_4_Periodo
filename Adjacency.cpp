#include "Adjacency.h"
Adjacency::Adjacency()
{
}
Adjacency::Adjacency(Vertex *vertex, int weight)
{
    setVertex(vertex);
    setWeight(weight);
}
Adjacency::~Adjacency()
{
}
void Adjacency::setVertex(Vertex *vertex)
{
    this->vertex = vertex;
}
void Adjacency::setWeight(int weight)
{
    this->weight = weight;
}
void Adjacency::setNext(Adjacency *next)
{
    this->next = next;
}
Vertex *Adjacency::getVertex()
{
    return vertex;
}
int Adjacency::getWeight()
{
    return weight;
}
Adjacency *Adjacency::getNext()
{
    return next;
}