#include <iostream>
#include <cstring>

#include "Edge.h"

using namespace std;

Edge::Edge(){
    setVDest}

Edge::~Edge()
{
}

Vertix Edge::getVSource()
{
    return vSource;
}
Vertix Edge::getVDest()
{
    return vDest;
}

void Edge::setVSource(Vertix v)
{
    vSource = v;
}
void Edge::setVDest(Vertix v)
{
    vDest = v;
}
void Edge ::setEdge(Vertix v1, Vertix v2)
{
    this->vSource = v1;
    this->vDest = v2;
}