
#ifndef NODE_H
#define NODE_H
#include "Vertex.h"
#include "Adjacency.h"
class Node
{
private:
    Vertex *vertex;
    //Node *next;
    Adjacency *next; //Go to right
    Node *bottom;    //Go to bottom
                     // a ser implementado para remoção do array de edge da lista de adjacência

public:
    Node();
    ~Node();

    Node(Vertex *vertex);
    Node(string label);
    Node(Vertex *vertex, Adjacency *next, Node *bottom);

    Vertex *getVertex();
    Adjacency *getNext();
    Node *getBottom();
    void setVertex(Vertex *vertex);
    void setNext(Adjacency *next);
    void setBottom(Node *bottom);
    Node *clone();
};

#endif