
#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node()
{
    this->setNext(NULL);
    this->setBottom(NULL);
}

Node::~Node()
{
}

Node::Node(Vertex *vertex)
{
    setVertex(vertex);
    this->setNext(NULL);
    this->setBottom(NULL);
}
Node::Node(string label)
{

    this->setVertex(new Vertex(-1, label, -1));
    this->setNext(NULL);
    this->setBottom(NULL);
}
Node::Node(Vertex *vertex, Adjacency *next, Node *bottom)
{
    setVertex(vertex);
    setNext(next);
    setBottom(bottom);
}

Vertex *Node::getVertex()
{
    return vertex;
}
Adjacency *Node::getNext()
{
    return next;
}
Node *Node::getBottom()
{
    return bottom;
}
void Node::setVertex(Vertex *vertex)
{
    this->vertex = vertex;
}
void Node::setNext(Adjacency *next)
{
    this->next = next;
}
void Node::setBottom(Node *bottom)
{
    this->bottom = bottom;
}
Node *Node::clone()
{
    return new Node(this->getVertex(), this->getNext(), this->getBottom());
}
