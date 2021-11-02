#ifndef ADJACENCY_H
#define ADJACENCY_H
#include "Vertex.h"
class Adjacency
{
private:
    Vertex *vertex;
    int weight; //weight of edge
    Adjacency *next;

public:
    Adjacency();
    Adjacency(Vertex *vertex, int weight);
    ~Adjacency();
    void setVertex(Vertex *vertex);
    void setWeight(int weight);
    void setNext(Adjacency *next);
    Vertex *getVertex();
    int getWeight();
    Adjacency *getNext();
};
#endif
