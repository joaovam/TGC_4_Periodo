#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H
#include "Node.h"
class AdjacencyList
{

private:
    Node *first;
    Node *last;

public:
    AdjacencyList();
    ~AdjacencyList();
    void add(Node *node);
    void remove(Node *node);
    void print();
};

#endif