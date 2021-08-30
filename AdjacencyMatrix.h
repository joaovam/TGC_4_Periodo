#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include "Edge.h"
#include "Graph.h"

class AdjacencyMatrix
{
private:
    int lines;
    int columns;
    int **matrix;

public:
    AdjacencyMatrix(int lines, int columns);
    ~AdjacencyMatrix();
    void addGrah(Graph graph);
    void addToMatrix(Edge edge);
    void showMatrix();
    void showGraph();
};

#endif
