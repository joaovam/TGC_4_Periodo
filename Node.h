
#ifndef NODE_H
#define NODE_H
#include "Vertex.h"
class Node
{
private:
    Vertex *vertex;
    Node *next;

public:
    Node();
    ~Node();

    Node(Vertex *vertex);
    Node(string label);
    Node(Vertex *vertex, Node *next);

    Vertex *getVertex();
    Node *getNext();
    void setVertex(Vertex *vertex);
    void setNext(Node *next);
};

#endif