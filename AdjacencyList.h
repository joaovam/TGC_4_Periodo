#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include "Node.h"

class AdjacencyList
{

private:
    Node *head;
    Node *tail;
    int V; //Number of Vertices
    int E; //Number of edges

public:
    AdjacencyList();
    ~AdjacencyList();
    AdjacencyList(int V);
    AdjacencyList(Node *head, Node *tail, int V, int E);
    Node *getHead() { return head; }
    Node *getTail() { return tail; }
    int getV() { return V; }
    int getE() { return E; }

    void add(Vertex *);
    void add();
    void addEdge(Node *node1, Node *node2);
    void addEdge(int ID1, int ID2);
    void remove(Node *node);
    void print();
};

#endif