
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
using namespace std;

int main(int argc, char *argv[])
{
    try
    {

        AdjacencyList *listDirectedNotPonder = new AdjacencyList();
        cout << "Creating directed not ponderated Graph";
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
        cout << "Creating directed ponderated Graph";
        listDirectedPonder->add(new Vertex(10, "1", -1));
        listDirectedPonder->add(new Vertex(0, "2", -1));
        listDirectedPonder->add(new Vertex(0, "3", -1));
        listDirectedPonder->add(new Vertex(2, "4", -1));
        listDirectedPonder->addEdge(0, 1, 5);
        listDirectedPonder->addEdge(1, 2, 2);
        listDirectedPonder->addEdge(2, 3, 0);
        listDirectedPonder->addEdge(3, 0, 0);
        listDirectedPonder->print();

        AdjacencyMatrix *matrix = new AdjacencyMatrix(4, 4);
        cout << "Creating matrix Graph";
        Vertex *v1 = new Vertex(1, "1", 0);
        Vertex *v2 = new Vertex(1, "2", 1);
        Vertex *v3 = new Vertex(1, "3", 2);
        Vertex *v4 = new Vertex(1, "4", 3);

        matrix->addToMatrix(Edge(5, "->", false, v1, v2));
        matrix->addToMatrix(Edge(1, "->", false, v1, v4));
        matrix->addToMatrix(Edge(1, "->", false, v1, v3));
        matrix->addToMatrix(Edge(2, "->", false, v3, v4));
        matrix->addToMatrix(Edge(1, "->", false, v4, v1));
        matrix->addToMatrix(Edge(1, "->", false, v2, v3));
        matrix->showMatrix();
    }
    catch (exception &e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}