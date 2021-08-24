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

Node::Node(Vertix vertix)
{
    setVertix(vertix);
}
Node::Node(Vertix vertix, Node *next)
{
    setVertix(vertix);
    setNext(next);
}
Vertix Node::getVertix()
{
    return vertix;
}
Node *Node::getNext()
{
    return next;
}
void Node::setVertix(Vertix vertix)
{
    vertix = vertix;
}
void Node::setNext(Node *next)
{
    next = next;
}
