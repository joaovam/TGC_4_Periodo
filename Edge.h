
#ifndef EDGE_H
#define EDGE_H
#include "Vertex.h"
class Edge
{
private:
    Vertex *vSource;
    Vertex *vDest;

    double weight;

    string label;

    bool isDirected;

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
    void showEdgeComplete();
};

#endif