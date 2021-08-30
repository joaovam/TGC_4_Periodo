
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
    E++;
    Edge edgeToAdd = Edge(weight, label, directed, v1, v2 );
    //cout << "E = " << E;
    Edge *auxEdge = new Edge[E];
     if (E > 1){
        for (int i = 0; i < E - 1; i++){
            auxEdge[i] = this -> edges[i];
        }
     }
     auxEdge[E - 1] = edgeToAdd;
    this-> edges = auxEdge;
    this -> setNumberEdges(this -> getNumberEdges()+1);
}
void Graph ::addVertex(Vertex vertex){
     V++;
     Vertex *auxVertex = new Vertex[V];
     if (V > 1){
        for (int i = 0; i < V - 1; i++){
            auxVertex[i] = this -> vertexes[i];
        }
     }
     auxVertex[V - 1] = vertex;
     
     this -> vertexes = auxVertex;
     this -> setNumberVertex(this -> getNumberVertex() + 1);
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
    /*cout << "\n N Edges =" << getNumberEdges();
    cout << "\n N Vertexes = \n" << getNumberVertex();*/
    cout << "G(V,E) = { ";
    for (int i =  0; i < this -> getNumberEdges() ; i++ ){
        this -> edges[i].showEdge();
        cout <<" , ";
    }
    cout << " }" << endl;
}