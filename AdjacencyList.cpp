
#include "AdjacencyList.h"
#include <iostream>
using namespace std;
AdjacencyList::AdjacencyList()
{
    this->head = new Node("HEAD");
    this->tail = head;
    this->V = 0;
    this->E = 0;

    cout << "Created null graph" << endl;
}
AdjacencyList::AdjacencyList(Node *head, Node *tail, int V, int E)
{
    this->head = head;
    this->tail = head;
    this->V = V;
    this->E = E;
    cout << "Created Graph from the data inserted" << endl;
}
AdjacencyList::AdjacencyList(int v)
{

    //The bottom is because of the way the array is allocated, we can go to the right or down
    this->head = new Node("0");

    Node *tmp = this->head;

    for (int i = 0; i < v; i++, tmp = tmp->getBottom())
    {
        Node *temp = new Node(to_string(this->V));

        temp->getVertex()->setId(this->V++);

        temp->setBottom(NULL);
        tmp->setBottom(temp);
    }
    this->tail = tmp->getBottom();

    cout << "Created a graph with " << v << " nodes" << endl;
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
    cout << "Adjacency List destructed" << endl;
}
void AdjacencyList::add(Vertex *v)
{
    cout << tail->getVertex()->getLabel() << endl;
    tail->setBottom(new Node(v));
    cout << tail->getBottom()->getVertex()->getLabel() << endl;
    tail = tail->getBottom();
    tail->getVertex()->setId(V++);
    cout << tail->getVertex()->getLabel() << endl;
}

void AdjacencyList::add()
{

    tail->setBottom(new Node("" + this->V)); //creates a new node and sets its id
    tail = tail->getBottom();
    tail->getVertex()->setId(V++);
}

void AdjacencyList::addEdge(Node *node1, Node *node2)
{
    if (node1 == NULL || node2 == NULL)
        cout << "Error: Node is NULL" << endl;
    else
    {
        Node *tmp = node1;
        for (; tmp->getNext() != NULL; tmp = tmp->getNext())
            ;
        tmp->setNext(new Node(node2->getVertex()));
        E++;
    }
}

void AdjacencyList::addEdge(int ID1, int ID2)
{
    Node *tmp1 = this->head;
    Node *tmp2 = this->head;
    for (int i = 0; i < ID1 || tmp1 == NULL; i++)
        tmp1 = tmp1->getBottom();

    for (int i = 0; i < ID2 || tmp2 == NULL; i++)
        tmp1 = tmp1->getBottom();
    if (tmp1->getVertex()->getId() != ID1 || tmp2->getVertex()->getId() != ID2 || tmp1 == NULL || tmp2 == NULL)
    {
        cerr << "Error: Node not found" << endl;
    }
}

void AdjacencyList::remove(Node *node)
{
}
void AdjacencyList::print()
{
    cout << "Printing Adjacency List" << endl;
    if (this->head == NULL)
    {
        cout << "Empty" << endl;
    }
    else
    {
        for (Node *column = head->getBottom(); column != NULL; column = column->getBottom())
        {

            for (Node *line = column; line != NULL; line = line->getNext())
            {
                cout << " " + line->getVertex()->getLabel() << " -> ";
            }
            cout << endl;
            cout << " | " << endl;
        }
        cout << "End of Adjacency List" << endl;
    }
}
