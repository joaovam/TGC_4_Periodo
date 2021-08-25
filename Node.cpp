#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node()
{
}

Node::~Node()
{
}

Node::Node(Vertex *vertex)
{
    setVertex(vertex);
}
Node::Node(string label)
{
    this->setVertex(new Vertex(-1, label));
}
Node::Node(Vertex *vertex, Node *next)
{
    setVertex(vertex);
    setNext(next);
}

Vertex *Node::getVertex()
{
    return vertex;
}
Node *Node::getNext()
{
    return next;
}

void Node::setVertex(Vertex *vertex)
{
    vertex = vertex;
}
void Node::setNext(Node *next)
{
    next = next;
}
