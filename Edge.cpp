#include <iostream>
#include <cstring>

#include "Edge.h"

using namespace std;

Edge::Edge()
{
}

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