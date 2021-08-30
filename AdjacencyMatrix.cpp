
#include <iostream>
#include <string>
using namespace std;
#include "AdjacencyMatrix.h"
#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"
#include "Graph.cpp"

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
    cout << "\n";
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
 AdjacencyMatrix ::AdjacencyMatrix(Graph graph){
    AdjacencyMatrix(graph.getNumberVertex(), graph.getNumberVertex());
   /// cout << "nE = " <<  graph.getNumberEdges();
   //cout << "nv = " << graph.getNumberVertex();
   this -> addToMatrix(graph.getEdges()[0]);
    /*for(int i =0; i < graph.getNumberEdges(); i++){
        graph.getEdges()[i].showEdge();
        cout << "wee";
        addToMatrix(graph.getEdges()[i]);
    }*/
    
}