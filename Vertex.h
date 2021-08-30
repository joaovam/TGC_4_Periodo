
#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <string>
using namespace std;

class Vertex
{
private:
  double weight;
  string label;
  int id;

public:
  Vertex();
  Vertex(double weitght, string label, int number);
  ~Vertex();
  void setWeight(double weight);
  void setLabel(string label);
  void setId(int number);
  void setVertex(Vertex vertex);
  double getWeight();
  int getId();
  string getLabel();
  void showVertex();
};

#endif