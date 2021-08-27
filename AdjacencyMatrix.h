#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include "Edge.h"

class AdjacencyMatrix
{
private:
    int lines;
    int columns;
    int **matrix;

public:
    AdjacencyMatrix(int lines, int columns);
    ~AdjacencyMatrix();
    void addToMatrix(Edge edge);
    void showMatrix();
    void showGraph();
};

#endif
