

#include <iostream>
#include <string>
using namespace std;
#include "Vertex.h"

Vertex ::Vertex()
{
    this->weight = 0;
    this->label = "";
}
Vertex ::Vertex(int weight, string label, int number)
{
    this->weight = weight;
    this->label = label;
    this->id = number;
}
Vertex::~Vertex() {}

void Vertex::setWeight(int weight)
{
    this->weight = weight;
}
void Vertex::setLabel(string label)
{
    this->label = label;
}
void Vertex ::setId(int number)
{
    this->id = number;
}

void Vertex::setVertex(Vertex vertex)
{
    this->weight = vertex.getWeight();
    this->label = vertex.getLabel();
};

int Vertex ::getWeight()
{
    return this->weight;
}

string Vertex ::getLabel()
{
    return this->label;
}
int Vertex ::getId()
{
    return this->id;
}
void Vertex::showVertex()
{
    cout << "weight: " << weight << "\nlabel: " << label << endl;
}
/*
int main()
{
    Vertex vertex(2, "3");
    vertex.showVertex();
    return 0;
}*/
