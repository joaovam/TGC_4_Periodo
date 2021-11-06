
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include "DisjointPath.cpp"
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
          // nondirectedNonPondered.showGraph();
        cout << "grafo 1:" << endl;
        Graph resid = nondirectedNonPondered.Residual();
        //resid.showGraph();
        AdjacencyMatrix teste = AdjacencyMatrix(nondirectedNonPondered);
        int list[11];

        disjoint_Path path = disjoint_Path();
        path.procurarCaminhosDisjuntos(teste.GetMatrix(), 0, 5);
    
       
        //==========================================================================================================================================================
        cout << "=============================================================================================" << endl;
        cout << "grafo 2:" << endl;
        Graph nondirectedNonPondered2 = Graph(false);
        nondirectedNonPondered2.addVertex(Vertex(0, "S", 0)); // 0
        nondirectedNonPondered2.addVertex(Vertex(0, "U", 1)); // 1
        nondirectedNonPondered2.addVertex(Vertex(0, "V", 2)); // 2
        nondirectedNonPondered2.addVertex(Vertex(0, "T", 3)); // 3        

        nondirectedNonPondered2.addRelationship(1, "S-U", true, &nondirectedNonPondered2.getVertexes()[0], &nondirectedNonPondered2.getVertexes()[1]);
        nondirectedNonPondered2.addRelationship(1, "S-V", true, &nondirectedNonPondered2.getVertexes()[0], &nondirectedNonPondered2.getVertexes()[2]);
        nondirectedNonPondered2.addRelationship(1, "U-V", true, &nondirectedNonPondered2.getVertexes()[1], &nondirectedNonPondered2.getVertexes()[2]);
        nondirectedNonPondered2.addRelationship(1, "U-T", true, &nondirectedNonPondered2.getVertexes()[1], &nondirectedNonPondered2.getVertexes()[3]);
        nondirectedNonPondered2.addRelationship(1, "V-T", true, &nondirectedNonPondered2.getVertexes()[2], &nondirectedNonPondered2.getVertexes()[3]);
       
        Graph residual2 = nondirectedNonPondered2.Residual();
        //residual2.showGraph();
        AdjacencyMatrix teste2 = AdjacencyMatrix(nondirectedNonPondered2);
        int lista[11];
        cout << "Grafo original: " << endl;
        teste2.showMatrix();

        disjoint_Path path2 = disjoint_Path();
        path2.procurarCaminhosDisjuntos(teste2.GetMatrix(), 0, 3);


    }





        //===========================================================================================================================================================    














      
    catch (exception &e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}