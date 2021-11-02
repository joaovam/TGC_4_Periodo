#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include "Edge.h"
#include "Graph.h"
#include "Vertex.h"

class AdjacencyMatrix
{
private:
    int lines;
    int columns;
    int **matrix;
    Graph graphRelated;
    Vertex *matrixVertexes;

public:
    AdjacencyMatrix(int lines, int columns);
    ~AdjacencyMatrix();
    AdjacencyMatrix(Graph graph);
    void addToMatrix(Edge edge);
    void showMatrix();
    void showGraph();
    int getNumberLines();
    int getNumberColumns();
    void setLines(int lines);
    void setColumns(int columns);
    int **GetMatrix();
};

#endif
