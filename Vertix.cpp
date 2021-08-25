#include <iostream>
#include <string>
using namespace std;
#include "Vertix.h"

Vertix ::Vertix()
{
    this->weight = 0;
    this->label = "";
}
Vertix ::Vertix(int weight, string label)
{
    this->weight = weight;
    this->label = label;
}
Vertix::~Vertix() {}

void Vertix::setWeight(int weight)
{
    this->weight = weight;
}
void Vertix::setLabel(string label)
{
    this->label = label;
}

void Vertix::setVertix(Vertix vertix)
{
    this->weight = vertix.getWeight();
    this->label = vertix.getLabel();
};

int Vertix ::getWeight()
{
    return this->weight;
}

string Vertix ::getLabel()
{
    return this->label;
}

void Vertix::showVertix()
{
    cout << "weight: " << weight << "\nlabel: " << label << endl;
}
/*
int main()
{
    Vertix vertix(2, "3");
    vertix.showVertix();
    return 0;
}*/