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
Node::Node(Vertex *vertex, Node *next, Node *bottom)
{
    setVertex(vertex);
    setNext(next);
    setBottom(bottom);
}

Vertex *Node::getVertex()
{
    return vertex;
}
Node *Node::getNext()
{
    return next;
}
Node *Node::getBottom()
{
    return bottom;
}
void Node::setVertex(Vertex *vertex)
{
    vertex = vertex;
}
void Node::setNext(Node *next)
{
    next = next;
}
void Node::setBottom(Node *bottom)
{
    bottom = bottom;
}
Node *Node::clone()
{
    Node *newNode = new Node(this->getVertex(), this->getNext(), this->getBottom());
}
