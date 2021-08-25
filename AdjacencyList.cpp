#include "AdjacencyList.h"

using namespace std;
AdjacencyList::AdjacencyList()
{
    this->head = NULL;
    this->tail = NULL;
    this->edges = NULL;
}
AdjacencyList::AdjacencyList(Node *head, Node *tail, int V, Edge *edges, int E)
{
    this->head = head;
    this->tail = head;
    this->edges = edges;
    this->V = V;
    this->E = E;
}
AdjacencyList::AdjacencyList(int V)
{
    this->head = new Node("0");

    Node *tmp = head;
    for (int i = 0; i < V; i++, tmp = tmp->getNext())
    {
        Node *temp = new Node("" + i);
        temp->setNext(NULL);
        tmp->setNext(temp);
    }
    this->tail = tmp->getNext();
}

AdjacencyList::~AdjacencyList()
{
    Node *temp2 = this->head;
    for (Node *tmp = head->getNext(); tmp != NULL; tmp = tmp->getNext())
    {
        delete temp2;
        temp2 = tmp;
    }
    delete temp2;
    delete this->tail;
    delete this->edges;
    cout << "Adjacency List destructed" << endl;
}
void AdjacencyList::add(Node *node)
{
}
void AdjacencyList::remove(Node *node)
{
}
void AdjacencyList::print()
{
}
