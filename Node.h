/**
 * Node class for the linked list.
 * In this project called AdjacencyList.
 * 
 * **/
#ifndef NODE_H
#define NODE_H
class Node
{
private:
    Vertix vertix;
    Node *next;

public:
    Node();
    ~Node();
    Node(Vertix vertix);
    Node(Vertix vertix, Node *next);
    Vertix getVertix();
    Node *getNext();
    void setVertix(Vertix vertix);
    void setNext(Node *next);
};

#endif