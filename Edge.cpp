
#include <iostream>
#include <cstring>
#include "Edge.h"

using namespace std;

Edge::Edge()
{
    this->weight = -1;
    this->label = "";
    this->isDirected = false;
    this->vSource = NULL;
    this->vDest = NULL;
}
Edge::Edge(Vertex *vSource, Vertex *vDest)
{
    this->vDest = vDest;
    this->vSource = vSource;
}

Edge::Edge(double weight, string label, bool isDirected, Vertex *vSource, Vertex *vDest)
{
    this->weight = weight;
    this->label = label;
    this->isDirected = isDirected;
    this->vSource = vSource;
    this->vDest = vDest;
}

Edge::~Edge()
{
}

Vertex *Edge::getVSource()
{
    return vSource;
}
Vertex *Edge::getVDest()
{
    return vDest;
}
double Edge::getWeight()
{
    return weight;
}
string Edge::getLabel()
{
    return label;
}
bool Edge::getIsDirected()
{
    return isDirected;
}

void Edge::setVSource(Vertex *v)
{
    vSource = v;
}
void Edge::setVDest(Vertex *v)
{
    vDest = v;
}
void Edge ::setEdge(Vertex *v1, Vertex *v2)
{
    this->vSource = v1;
    this->vDest = v2;
}

void Edge::setWeight(double w)
{
    weight = w;
}
void Edge::setLabel(string l)
{
    label = l;
}
void Edge::setIsDirected(bool b)
{
    isDirected = b;
}

void Edge::showEdgeComplete()
{
    cout << "Edge: " << this->label << " " << this-> weight << "From Vertex: " << vSource->getLabel()
         << "To Vertex: " << vDest->getLabel() << endl;
}

void Edge :: showEdge(){
   string separatorInit = this -> getIsDirected()  ? "(" : "{";
   string separatorEnd = this -> getIsDirected () ? ")" : "}";
   cout << separatorInit << " " << this -> getVSource() -> getLabel() << ", " << this -> getVDest() -> getLabel() << " " << separatorEnd;
}
