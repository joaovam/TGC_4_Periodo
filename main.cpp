
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
using namespace std;

int main(int argc, char *argv[])
{
    try
    {
        Graph nondirectedNonPondered =  Graph(false);
        nondirectedNonPondered.addVertex(Vertex(0, "1", 0));
        nondirectedNonPondered.addVertex(Vertex(0, "2", 1));
        nondirectedNonPondered.addVertex(Vertex(0, "3", 2));
        nondirectedNonPondered.addVertex(Vertex(0, "4", 3));
        nondirectedNonPondered.addRelationship(0, "1-2", false, &nondirectedNonPondered.getVertexes()[0],&nondirectedNonPondered.getVertexes()[1] );
        nondirectedNonPondered.addRelationship(0, "1-3", false, &nondirectedNonPondered.getVertexes()[0],&nondirectedNonPondered.getVertexes()[2] );
        nondirectedNonPondered.addRelationship(0, "1-4", false, &nondirectedNonPondered.getVertexes()[0],&nondirectedNonPondered.getVertexes()[3] );
        nondirectedNonPondered.addRelationship(0, "2-3", false, &nondirectedNonPondered.getVertexes()[1],&nondirectedNonPondered.getVertexes()[2] );
        nondirectedNonPondered.addRelationship(0, "3-4", false, &nondirectedNonPondered.getVertexes()[2],&nondirectedNonPondered.getVertexes()[3] );
        nondirectedNonPondered.addRelationship(0, "4-1", false, &nondirectedNonPondered.getVertexes()[3],&nondirectedNonPondered.getVertexes()[0] );
        nondirectedNonPondered.showGraph();
        cout << endl <<"Matrix from this non directed non pondered graph:";
        AdjacencyMatrix MNondirectedNonPondered= AdjacencyMatrix (nondirectedNonPondered);
        MNondirectedNonPondered.showMatrix();
        cout << endl;
        Graph nondirectedPondered =  Graph(true);
        nondirectedPondered.addVertex(Vertex(10, "1", 0));
        nondirectedPondered.addVertex(Vertex(0, "2", 1));
        nondirectedPondered.addVertex(Vertex(0, "3", 2));
        nondirectedPondered.addVertex(Vertex(2, "4", 3));
        nondirectedPondered.addRelationship(5, "1-2", false, &nondirectedPondered.getVertexes()[0],&nondirectedPondered.getVertexes()[1] );
        nondirectedPondered.addRelationship(0, "1-3", false, &nondirectedPondered.getVertexes()[0],&nondirectedPondered.getVertexes()[2] );
        nondirectedPondered.addRelationship(0, "1-4", false, &nondirectedPondered.getVertexes()[0],&nondirectedPondered.getVertexes()[3] );
        nondirectedPondered.addRelationship(2, "2-3", false, &nondirectedPondered.getVertexes()[1],&nondirectedPondered.getVertexes()[2] );
        nondirectedPondered.addRelationship(0, "3-4", false, &nondirectedPondered.getVertexes()[2],&nondirectedPondered.getVertexes()[3] );
        nondirectedPondered.addRelationship(0, "4-1", false, &nondirectedPondered.getVertexes()[3],&nondirectedPondered.getVertexes()[0] );
        nondirectedPondered.showGraph();
        cout <<endl << "Matrix from this non directed pondered graph:";
        AdjacencyMatrix MNondirectedPondered= AdjacencyMatrix (nondirectedPondered);
        MNondirectedPondered.showMatrix();
        cout << endl;        

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
        cout << "Creating directed ponderated Graph\n";
        listDirectedPonder->add(new Vertex(10, "1", -1));
        listDirectedPonder->add(new Vertex(0, "2", -1));
        listDirectedPonder->add(new Vertex(0, "3", -1));
        listDirectedPonder->add(new Vertex(2, "4", -1));
        listDirectedPonder->addEdge(0, 1, 5);
        listDirectedPonder->addEdge(1, 2, 2);
        listDirectedPonder->addEdge(2, 3, 0);
        listDirectedPonder->addEdge(3, 0, 0);
        listDirectedPonder->print();

       /* AdjacencyMatrix *matrix = new AdjacencyMatrix(4, 4);
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
        matrix->showMatrix();*/
    }
    catch (exception &e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}