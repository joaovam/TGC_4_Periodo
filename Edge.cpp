#include <iostream>
#include <cstring>

using namespace std;

class Edge
{
private:
    Vertix VSource;
    Vertix VDest;

    double weight;

    string label;

public:
    Edge();
    ~Edge();
};

Edge::Edge()
{
}

Edge::~Edge()
{
}
