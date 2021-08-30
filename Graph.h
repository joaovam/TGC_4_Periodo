
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
    bool pondered;

public:
    Graph();
    Graph (bool pondered);
    Graph(int numberVertex, int numberEdges, bool pondered);
    ~Graph();
    void addVertex(Vertex vertex);
    //double weight, string label, bool isDirected, Vertex *vSource, Vertex *vDest
    void addRelationship(double weight, string label, bool directed, Vertex *v1, Vertex *v2);
    void setNumberVertex(int number);
    void setNumberEdges(int number);
    void setPondered(bool pondered);
    bool getPondered();
    int getNumberVertex();
    int getNumberEdges();
    Edge * getEdges();
    Vertex * getVertexes();
    void showGraph();




   
};

#endif