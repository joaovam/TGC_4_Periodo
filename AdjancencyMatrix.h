#include "Edge.h"
class AdjacencyMatrix {
    private: 
        int lines;
        int columns;
    public:
        AdjacencyMatrix();
        ~AdjacencyMatrix();
        void addToMatrix(Edge edge);
        void showMatriz();
        void showGraph();

    
};