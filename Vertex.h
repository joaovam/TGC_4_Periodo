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
  int id;

public:
  Vertex();
  Vertex(int weitght, string label, int number);
  ~Vertex();
  void setWeight(int weight);
  void setLabel(string label);
  void setId(int number);
  void setVertex(Vertex vertex);
  int getWeight();
  int getId();
  string getLabel();
  void showVertex();
};

#endif