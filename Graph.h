
#ifndef GRAPH_H
#define GRAPH_H
#include "Vertex.h"
#include "Edge.h"
class Graph
{
private:
    Vertex *vertexes;
    Edge *edges;
    int numberVertex;
    int numberEdges;

public:
    Graph ();
    Graph(int numberVertex, int numberEdges);
    ~Graph();
    void addVertex(Vertex vertex);
    //double weight, string label, bool isDirected, Vertex *vSource, Vertex *vDest
    void addRelationship(double weight, string label, bool directed, Vertex *v1, Vertex *v2);
    void setNumberVertex(int number);
    void setNumberEdges(int number);
    int getNumberVertex();
    int getNumberEdges();
    Edge * getEdges();
    Vertex * getVertexes();
    void showGraph();




   
};

#endif