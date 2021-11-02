#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include "Node.h"
#include "Edge.h"
#include "Adjacency.h"
#include "Graph.h"

class AdjacencyList
{

private:
    Node *head;
    Node *tail;
    int V; //Number of Vertices
    int E; //Number of edges
    bool ponderated;

public:
    AdjacencyList();
    ~AdjacencyList();
    AdjacencyList(int V);
    AdjacencyList(int V, bool ponderated);
    AdjacencyList(Graph *graph);
    AdjacencyList(Node *head, Node *tail, int V, int E);
    AdjacencyList(Node *head, Node *tail, int V, int E, bool ponderated);

    Node *getHead() { return head; }
    Node *getTail() { return tail; }
    int getV() { return V; }
    int getE() { return E; }

    void add(Vertex *);
    void add();
    void addEdge(Node *node1, Node *node2, int weight);
    void addEdge(int ID1, int ID2);
    void addEdge(int ID1, int ID2, int weight1);
    void remove(Node *node);
    void print();
};

#endif