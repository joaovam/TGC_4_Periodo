
#include <iostream>
#include <string>
using namespace std;
#include "AdjacencyMatrix.h"
#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"
#include "Graph.cpp"
int nVertex = 0;
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
    this->matrixVertexes = (Vertex *)malloc(lines * sizeof(int *));
}

AdjacencyMatrix ::~AdjacencyMatrix() {}

void AdjacencyMatrix ::addToMatrix(Edge edge)
{
    double weight = edge.getWeight();
    if (edge.getWeight() == 0)
    {
        weight = 1;
    }

    matrix[edge.getVSource()->getId()][edge.getVDest()->getId()] = weight;
    if (!edge.getIsDirected())
    {
        matrix[edge.getVDest()->getId()][edge.getVSource()->getId()] = weight;
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
    if (this->graphRelated.getPondered())
    {
        cout << "Vertexes weights:" << endl;
        for (int j = 0; j < this->graphRelated.getNumberVertex(); j++)
        {
            if (this->graphRelated.getVertexes()[j].getWeight() != 0)
            {
                cout << " -> " << graphRelated.getVertexes()[j].getLabel() << " : " << graphRelated.getVertexes()[j].getWeight() << endl;
            }
        }
    }
}
void AdjacencyMatrix ::showGraph()
{
    this->graphRelated.showGraph();
}
int AdjacencyMatrix ::getNumberLines()
{
    return this->lines;
}
int AdjacencyMatrix ::getNumberColumns()
{
    return this->columns;
}
void AdjacencyMatrix ::setLines(int lines)
{
    this->lines = lines;
}
void AdjacencyMatrix ::setColumns(int columns)
{
    this->columns = columns;
}
AdjacencyMatrix ::AdjacencyMatrix(Graph graph)
{
    nVertex = 0;
    this->graphRelated = graph;
    int L = graph.getNumberVertex();
    int C = graph.getNumberVertex();
    this->setColumns(graph.getNumberVertex());
    this->setLines(graph.getNumberVertex());
    this->matrix = (int **)malloc(L * sizeof(int *));
    for (int i = 0; i < L; i++)
        matrix[i] = (int *)malloc(C * sizeof(int));

    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            matrix[i][j] = 0;
        }
    }
    // cout << "lines = " << this -> getNumberLines ()  << endl;
    // cout << "columns" << this-> getNumberColumns() << endl;
    /// cout << "nE = " <<  graph.getNumberEdges();
    // cout << "nv = " << graph.getNumberVertex();
    for (int i = 0; i < graph.getNumberEdges(); i++)
    {
        addToMatrix(graph.getEdges()[i]);
    }
}
int **AdjacencyMatrix::GetMatrix()
{

    return matrix;
}