#include <iostream>
#include <string>
using namespace std;
#include "AdjacencyMatrix.h"
#include "Edge.h"
#include "Vertex.h"
#include "Vertex.cpp"
#include "Edge.cpp"
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
void AdjacencyMatrix :: showGraph(){

}
int main()
{
    AdjacencyMatrix matrix(4, 4);
    Vertex vertex1(1, "1", 0);
    Vertex vertex2(1, "2", 1);
    Vertex vertex3(1, "3", 2);
    Vertex vertex4(1, "4", 3);
    Vertex *v1;
    Vertex *v2;
    Vertex *v3;
    Vertex *v4;
    v1 = &vertex1;
    v2 = &vertex2;
    v3 = &vertex3;
    v4 = &vertex4;
    //Edge array[5];
    Edge edge1(1, "->", true, v1, v2);
    Edge edge2(1, "->", true, v1, v4);
    Edge edge3(1, "->", true, v1, v3);
    Edge edge4(1, "->", true, v3, v4);
    Edge edge5(1, "->", true, v4, v1);
    Edge edge6(1, "->", true, v2, v3);
    /*array[0] = edge1;
   array[1] = edge2;
   array[2] = edge3;
   array[3] = edge4;
   array[4] = edge5;
   array[5] = edge6;*/

    matrix.addToMatrix(edge1);
    matrix.addToMatrix(edge2);
    matrix.addToMatrix(edge3);
    matrix.addToMatrix(edge4);
    matrix.addToMatrix(edge5);
    matrix.addToMatrix(edge6);
    matrix.showMatrix();
    cout << flush;

    /*
   
  for(int i = 0 ; i < 3; i++){
    string label1 =(array[i].getVSource() -> getLabel());
    string label2 = (array[i].getVDest() -> getLabel());
      cout << label1 << " "<< label2 << ";" << flush;
  }*/
}