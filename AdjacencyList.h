#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H
#include "Node.h"
#include "Edge.h"
class AdjacencyList
{

private:
    Node *head;
    Node *tail;
    int V = 0;          //Number of Vertices
    int E = 0;          //Number of edges
    Edge *edges = NULL; //list of edges

public:
    AdjacencyList();
    ~AdjacencyList();
    AdjacencyList(int V);
    AdjacencyList(Node *head, Node *tail, int V, Edge *edges, int E);
    void add(Node *node);
    void addEdge(Node *node1, Node *node2);
    void remove(Node *node);
    void print();
};

#endif