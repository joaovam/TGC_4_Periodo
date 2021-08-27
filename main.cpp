
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
using namespace std;

int main(int argc, char *argv[])
{
    try
    {

        AdjacencyList *listDirectedNotPonder = new AdjacencyList();

        listDirectedNotPonder->add(new Vertex(-1, "1", -1));
        listDirectedNotPonder->add(new Vertex(-1, "2", -1));
        listDirectedNotPonder->add(new Vertex(-1, "3", -1));
        listDirectedNotPonder->add(new Vertex(-1, "4", -1));

        listDirectedNotPonder->addEdge(0, 1);
        listDirectedNotPonder->addEdge(1, 2);
        listDirectedNotPonder->addEdge(2, 3);
        listDirectedNotPonder->addEdge(3, 0);

        listDirectedNotPonder->print();

        AdjacencyList *listDirectedPonder = new AdjacencyList();
        listDirectedPonder->add(new Vertex(10, "1", -1));
        listDirectedPonder->add(new Vertex(0, "2", -1));
        listDirectedPonder->add(new Vertex(0, "3", -1));
        listDirectedPonder->add(new Vertex(2, "4", -1));
        listDirectedPonder->addEdge(0, 1, 5);
        listDirectedPonder->addEdge(1, 2, 2);
        listDirectedPonder->addEdge(2, 3);
        listDirectedPonder->addEdge(3, 0);
        listDirectedPonder->print();

        /**
        AdjacencyMatrix matrix(4, 4);
        Vertex vertex1(1, "1", 0);
        Vertex vertex2(1, "2", 1);
        Vertex vertex3(1, "3", 2);
        Vertex vertex4(1, "4", 3);
        Vertex *v1;
        Vertex *v2;
        Vertex *v3;
        Vertex *v4;
        v1 = &vertex1;
        v2 = &vertex2;
        v3 = &vertex3;
        v4 = &vertex4;
        Edge edge1(5, "->", false, v1, v2);
        Edge edge2(1, "->", false, v1, v4);
        Edge edge3(1, "->", false, v1, v3);
        Edge edge4(2, "->", false, v3, v4);
        Edge edge5(1, "->", false, v4, v1);
        Edge edge6(1, "->", false, v2, v3);
        matrix.addToMatrix(edge1);
        matrix.addToMatrix(edge2);
        matrix.addToMatrix(edge3);
        matrix.addToMatrix(edge4);
        matrix.addToMatrix(edge5);
        matrix.addToMatrix(edge6);
        matrix.showMatrix();**/
    }
    catch (exception &e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}