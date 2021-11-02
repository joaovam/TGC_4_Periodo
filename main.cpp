
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include "disjoint_paths.cpp"
using namespace std;

int main(int argc, char *argv[])
{
    try
    {

        Graph nondirectedNonPondered = Graph(false);
        nondirectedNonPondered.addVertex(Vertex(0, "A", 0)); // 0
        nondirectedNonPondered.addVertex(Vertex(0, "B", 1)); // 1
        nondirectedNonPondered.addVertex(Vertex(0, "C", 2)); // 2
        nondirectedNonPondered.addVertex(Vertex(0, "D", 3)); // 3
        nondirectedNonPondered.addVertex(Vertex(0, "E", 4)); // 4
        nondirectedNonPondered.addVertex(Vertex(0, "F", 5)); // 5

        nondirectedNonPondered.addRelationship(1, "A-B", true, &nondirectedNonPondered.getVertexes()[0], &nondirectedNonPondered.getVertexes()[1]);
        nondirectedNonPondered.addRelationship(1, "A-D", true, &nondirectedNonPondered.getVertexes()[0], &nondirectedNonPondered.getVertexes()[3]);
        nondirectedNonPondered.addRelationship(1, "A-E", true, &nondirectedNonPondered.getVertexes()[0], &nondirectedNonPondered.getVertexes()[4]);
        nondirectedNonPondered.addRelationship(1, "B-C", true, &nondirectedNonPondered.getVertexes()[1], &nondirectedNonPondered.getVertexes()[2]);
        nondirectedNonPondered.addRelationship(1, "B-D", true, &nondirectedNonPondered.getVertexes()[1], &nondirectedNonPondered.getVertexes()[3]);
        nondirectedNonPondered.addRelationship(1, "B-E", true, &nondirectedNonPondered.getVertexes()[1], &nondirectedNonPondered.getVertexes()[4]);
        nondirectedNonPondered.addRelationship(1, "E-C", true, &nondirectedNonPondered.getVertexes()[4], &nondirectedNonPondered.getVertexes()[2]);
        nondirectedNonPondered.addRelationship(1, "E-F", true, &nondirectedNonPondered.getVertexes()[4], &nondirectedNonPondered.getVertexes()[5]);
        nondirectedNonPondered.addRelationship(1, "C-F", true, &nondirectedNonPondered.getVertexes()[2], &nondirectedNonPondered.getVertexes()[5]);
        nondirectedNonPondered.addRelationship(1, "D-C", true, &nondirectedNonPondered.getVertexes()[3], &nondirectedNonPondered.getVertexes()[2]);
        nondirectedNonPondered.addRelationship(1, "D-F", true, &nondirectedNonPondered.getVertexes()[3], &nondirectedNonPondered.getVertexes()[5]);

        nondirectedNonPondered.showGraph();
        Graph resid = nondirectedNonPondered.Residual();
        resid.showGraph();
        AdjacencyMatrix teste = AdjacencyMatrix(nondirectedNonPondered);

        cout << "There can be maximum " << findDisjointPaths(teste.GetMatrix(), s, t)
             << " edge-disjoint paths from " << s << " to " << t;
    }
    catch (exception &e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}