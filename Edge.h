
#ifndef EDGE_H
#define EDGE_H
#include "Vertex.h"
class Edge
{
private:
    Vertex *vSource = NULL;
    Vertex *vDest = NULL;

    double weight = -1;

    string label = "";

    bool isDirected = false;

public:
    Edge();
    ~Edge();
    Edge(Vertex *, Vertex *);
    Edge(double, string, bool, Vertex *, Vertex *);
    Vertex *getVSource();
    Vertex *getVDest();
    double getWeight();
    string getLabel();
    bool getIsDirected();
    void setVSource(Vertex *);
    void setVDest(Vertex *);
    void setEdge(Vertex *, Vertex *);
    void setWeight(double);
    void setLabel(string);
    void setIsDirected(bool);
    void showEdge();
};

#endif