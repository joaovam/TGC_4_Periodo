
#ifndef EDGE
#define EDGE
#include "Vertix.h"
class Edge
{
private:
    Vertix vSource;
    Vertix vDest;

    double weight;

    string label;
    //boolean digraph ? 

public:
    Edge();
    ~Edge();
    Vertix getVSource();
    Vertix getVDest();
    void setVSource(Vertix v);
    void setVDest(Vertix v);
    void setEdge(Vertix v1, Vertix v2);
};

#endif