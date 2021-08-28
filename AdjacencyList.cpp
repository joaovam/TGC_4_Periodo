
#include "AdjacencyList.h"
#include <iostream>
using namespace std;
AdjacencyList::AdjacencyList()
{
    this->head = new Node("HEAD");
    this->tail = head;
    this->V = 0;
    this->E = 0;
    this->edge = NULL;

    cout << "\nCreated null graph\n"
         << endl;
}
AdjacencyList::AdjacencyList(Node *head, Node *tail, int V, int E)
{
    this->head = head;
    this->tail = head;
    this->V = V;
    this->E = E;
    this->edge = NULL;
    cout << "\nCreated Graph from the data inserted\n"
         << endl;
}
AdjacencyList::AdjacencyList(Node *head, Node *tail, int V, int E, Edge *edge)
{
    this->head = head;
    this->tail = head;
    this->V = V;
    this->E = E;
    this->edge = edge;
    cout << "\nCreated Graph from the data inserted\n"
         << endl;
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

    cout << "\nCreated a graph with " << v << " nodes\n"
         << endl;
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
    cout << "\nAdjacency List destructed\n"
         << endl;
}
void AdjacencyList::add(Vertex *v)
{ //adds a vertex to the graph

    tail->setBottom(new Node(v));

    tail = tail->getBottom();
    tail->getVertex()->setId(V++);
}

void AdjacencyList::add()
{ //adds an anonymous vertex to the graph

    tail->setBottom(new Node("" + this->V)); //creates a new node and sets its id
    tail = tail->getBottom();
    tail->getVertex()->setId(V++);
    cout << "\nAdded an anonymous vertex to the graph\n";
}

void AdjacencyList::addEdge(Node *node1, Node *node2, int weight)
{ //adds a non-ponderated edge between two nodes
    if (node1 == NULL || node2 == NULL)
        cout << "\nError: Node is NULL\n"
             << endl;
    else
    {
        Node *tmp = node1;
        for (; tmp->getNext() != NULL; tmp = tmp->getNext())
            ;
        tmp->setNext(new Node(node2->getVertex()));
        E++;

        Edge *tempEdge = new Edge[E];

        if (this->edge == NULL)
        {
            tempEdge[E - 1] = Edge(weight, " ", true, node1->getVertex(), node2->getVertex());
            this->edge = tempEdge;
        }
        else
        {

            for (int i = 0; i < E - 1; i++)
            {
                tempEdge[i] = edge[i];
            }
            tempEdge[E - 1] = Edge(weight, " ", true, node1->getVertex(), node2->getVertex());
            this->edge = tempEdge;
        }
    }
}

void AdjacencyList::addEdge(int ID1, int ID2)
{ //adds a non-ponderated edge between two nodes
    Node *tmp1 = this->head;
    Node *tmp2 = this->head;

    for (int i = 0; i <= ID1 && tmp1 != NULL; i++)
        tmp1 = tmp1->getBottom();

    for (int i = 0; i <= ID2 && tmp2 != NULL; i++)
        tmp2 = tmp2->getBottom();

    if (tmp1->getVertex()->getId() != ID1 || tmp2->getVertex()->getId() != ID2 || tmp1 == NULL || tmp2 == NULL)
    {
        cerr << "Error: Node not found" << endl;
    }
    else
    {
        addEdge(tmp1, tmp2, -1);
        cout << "\nAdded an edge between " << tmp1->getVertex()->getLabel() << " and " << tmp2->getVertex()->getLabel() << endl;
    }
}

void AdjacencyList::addEdge(int ID1, int ID2, int weight)
{ //adds a ponderated edge between two nodes
    Node *tmp1 = this->head;
    Node *tmp2 = this->head;

    for (int i = 0; i <= ID1 && tmp1 != NULL; i++)
        tmp1 = tmp1->getBottom();

    for (int i = 0; i <= ID2 && tmp2 != NULL; i++)
        tmp2 = tmp2->getBottom();

    if (tmp1->getVertex()->getId() != ID1 || tmp2->getVertex()->getId() != ID2 || tmp1 == NULL || tmp2 == NULL)
    {
        cerr << "Error: Node not found" << endl;
    }
    else
    {

        addEdge(tmp1, tmp2, weight);
        cout << "\nAdded an edge between " << tmp1->getVertex()->getLabel() << " and " << tmp2->getVertex()->getLabel() << endl;
    }
}

void AdjacencyList::remove(Node *node)
{
}
void AdjacencyList::print()
{
    cout << "\nPrinting Adjacency List\n"
         << endl;
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
                if (line->getVertex()->getWeight() != -1)
                    cout << " " + line->getVertex()->getLabel() << " Weight: (" << line->getVertex()->getWeight() << ") -> ";
                else
                    cout << " " + line->getVertex()->getLabel() << " -> ";
            }
            cout << endl;
            cout << " | "
                 << endl;
        }
        if (edge != NULL)
        {
            cout << "\nEdges: \n"
                 << endl;
            for (int i = 0; i < E; i++)
            {
                if (edge[i].getWeight() != -1)
                    cout << " " << edge[i].getVSource()->getLabel() << " -> " << edge[i].getVDest()->getLabel() << "  Weight: [ " << edge[i].getWeight() << " ]"
                         << endl;
                else
                    cout << " " << edge[i].getVSource()->getLabel() << " -> " << edge[i].getVDest()->getLabel() << ""
                         << endl;
            }
        }
        cout << "\nEnd of Adjacency List\n"
             << endl;
    }
}
