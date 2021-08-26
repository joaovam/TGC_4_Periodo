#include "AdjacencyList.h"

using namespace std;
AdjacencyList::AdjacencyList()
{
    this->head = NULL;
    this->tail = NULL;
    this->edges = NULL;

    cout << "Created null graph" << endl;
}
AdjacencyList::AdjacencyList(Node *head, Node *tail, int V, Edge *edges, int E)
{
    this->head = head;
    this->tail = head;
    this->edges = edges;
    this->V = V;
    this->E = E;
    cout << "Created Graph from the data inserted" << endl;
}
AdjacencyList::AdjacencyList(int V)
{
    //The bottom is because of the way the array is allocated, we can go to the right or down
    this->head = new Node("0");

    Node *tmp = head;
    for (int i = 0; i < V; i++, tmp = tmp->getBottom())
    {
        Node *temp = new Node("" + i);
        temp->setBottom(NULL);
        tmp->setBottom(temp);
    }
    this->tail = tmp->getBottom();
    cout << "Created a graph with " << V << " nodes" << endl;
}

AdjacencyList::~AdjacencyList()
{
    Node *excludeGoingDown = this->head;                                     //excludes the node while going down
    for (Node *tmp = head->getBottom(); tmp != NULL; tmp = tmp->getBottom()) //Destruct nodes going down
    {
        Node *ExcludeGoingRight = tmp->getNext(); //excludes the node while going right

        for (Node *tmp2 = tmp->getNext()->getNext(); tmp2 != NULL; tmp2 = tmp2->getNext()) //Destruct nodes going right
        {
            delete ExcludeGoingRight;
            ExcludeGoingRight = tmp2;
        }
        delete ExcludeGoingRight;
        delete excludeGoingDown;
        excludeGoingDown = tmp;
    }
    delete excludeGoingDown;
    delete this->tail;
    delete this->edges;
    cout << "Adjacency List destructed" << endl;
}
void AdjacencyList::add(Node *node)
{
}
void AdjacencyList::addEdge(Node *node1, Node *node2)
{
    if (node1 == NULL || node2 == NULL)
        cout << "Error: Node is NULL" << endl;
    else
    {
        node1->setNext(node2->clone());
        E++; //figure a way to insert an edge in the list of edges

        Edge *newEdges = new Edge[E];
        for (int i = 0; i < E; i++)
        {
            newEdges[i].setVDest(edges[i].getVDest());
            newEdges[i].setVSource(edges[i].getVSource());
        }
        edges = newEdges;
    }
}
void AdjacencyList::remove(Node *node)
{
}
void AdjacencyList::print()
{
    for (Node *column = head->getBottom(); column->getNext() != NULL; column = column->getBottom())
    {
        for (Node *line = column; line->getNext() != NULL; line = line->getNext())
        {
            cout << line->getVertex()->getLabel() << " -> ";
        }
        cout << endl;
    }
}
