
#include <iostream>
#include <cstring>
#include "Graph.h"
using namespace std;
int E;
int V;

Graph:: Graph(){
     this -> numberVertex = 0;
    this -> numberEdges = 0;
    this -> edges = (Edge *)malloc(numberEdges * sizeof(int *));
    this -> vertexes = (Vertex *)malloc(numberVertex * sizeof(int *)); 
    E = 0;
    V = 0;

}
Graph:: Graph(int numberVertex, int numberEdges){
    this ->numberVertex = numberVertex;
    this -> numberEdges = numberEdges;
    this -> edges = (Edge *)malloc(numberEdges * sizeof(int *));
    this -> vertexes = (Vertex *)malloc(numberVertex * sizeof(int *)); 
    V = numberVertex;
    E = numberEdges;
}
Graph :: ~Graph(){}
void Graph :: addRelationship(double weight, string label, bool directed, Vertex *v1, Vertex *v2) {
    this-> edges[E] = Edge(weight, label, directed, v1, v2);
    E++;
    this -> setNumberEdges(this -> getNumberEdges()+1);
}
void Graph ::addVertex(Vertex vertex){
     V++;
     Vertex *auxVertex = new Vertex[V];
     for (int i = 0; i < V - 1; i++){
         auxVertex[i] = this -> vertexes[i];
     }
     auxVertex[V] = vertex;
     this -> vertexes = auxVertex;
     int nVertexes = (this -> getNumberVertex());
     this -> setNumberVertex(nVertexes ++);
}
void Graph :: setNumberEdges(int n){
    this -> numberEdges = n;
}
void Graph :: setNumberVertex(int n){
    this -> numberVertex = n;
}
int Graph :: getNumberEdges(){
    return this -> numberEdges;
}
int Graph :: getNumberVertex(){
    return this -> numberVertex;
}
Edge * Graph :: getEdges(){
    return this -> edges;
}
Vertex * Graph :: getVertexes(){
    return this -> vertexes;
}
void Graph :: showGraph(){
    for (int i =  0; i < this -> getNumberEdges() ; i++ ){
        this -> edges[i].showEdge();
    }
}