#include <iostream>
#include <string>
using namespace std;
#include "Vertex.h"

Vertex ::Vertex()
{
    this->weight = 0;
    this->label = "";
}
Vertex ::Vertex(int weight, string label)
{
    this->weight = weight;
    this->label = label;
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