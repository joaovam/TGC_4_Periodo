
#ifndef NODE_H
#define NODE_H
#include "Vertex.h"
class Node
{
private:
    Vertex *vertex;
    Node *next;   //Go to right
    Node *bottom; //Go to bottom
    //int weight;   //Weight of the edge // a ser implementado para remoção do array de edge da lista de adjacência

public:
    Node();
    ~Node();

    Node(Vertex *vertex);
    Node(string label);
    Node(Vertex *vertex, Node *next, Node *bottom);

    Vertex *getVertex();
    Node *getNext();
    Node *getBottom();
    void setVertex(Vertex *vertex);
    void setNext(Node *next);
    void setBottom(Node *bottom);
    Node *clone();
};

#endif