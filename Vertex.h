#include <iostream>
#include <string>
using namespace std;
#ifndef VERTEX_H
#define VERTEX_H
class Vertex
{
private:
  int weight;
  string label;

public:
  Vertex();
  Vertex(int weitght, string label);
  ~Vertex();
  void setWeight(int weight);
  void setLabel(string label);
  void setVertex(Vertex vertex);
  int getWeight();
  string getLabel();
  void showVertex();
};

#endif