
#include <iostream>
#include <string>
using namespace std;
#include "AdjacencyMatrix.h"
#include "Edge.h"
#include "Vertex.h"

AdjacencyMatrix::AdjacencyMatrix(int lines, int columns)
{
    this->lines = lines;
    this->columns = columns;
    this->matrix = (int **)malloc(lines * sizeof(int *));
    for (int i = 0; i < lines; i++)
        matrix[i] = (int *)malloc(columns * sizeof(int));

    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

AdjacencyMatrix ::~AdjacencyMatrix() {}

void AdjacencyMatrix ::addToMatrix(Edge edge)
{
    matrix[edge.getVSource()->getId()][edge.getVDest()->getId()] = edge.getWeight();
    if (!edge.getIsDirected())
    {
        matrix[edge.getVDest()->getId()][edge.getVSource()->getId()] = edge.getWeight();
    }
}
void AdjacencyMatrix::showMatrix()
{
    for (int i = 0; i < this->lines; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            cout << this->matrix[i][j] << " ";
        }
        cout << "\n";
    }
}
void AdjacencyMatrix ::showGraph()
{
}
void AdjacencyMatrix ::addGrah(Graph graph){
    AdjacencyMatrix(graph.getNumberVertex(), graph.getNumberVertex());
    for(int i =0; i < graph.getNumberVertex(); i++){
        addToMatrix(graph.getEdges()[i]);
    }
    
}