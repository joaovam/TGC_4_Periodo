#ifndef DISJOINT_PATH_H
#define DISJOINT_PATH_H
#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
#include <climits>
#define V 4 // representa o número de vértices do grafo
class disjoint_Path
{
private:
    int graph[V][V];

public:
    disjoint_Path()
    {
        memset(graph, 0, sizeof(graph));
    }

    bool buscaEmLargura(int rGraph[V][V], int s, int t, int parent[]);
    void procurarCaminhosDisjuntos(int **graph, int s, int t);
    int acharCaminhosDisjuntos(int **graph, int s, int t);
    void buscaEmProfundidade(int s, int t);
    void buscaEmProfundidadeREC(int, int);
};
#endif