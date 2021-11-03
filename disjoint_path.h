#ifndef DISJOINT_PATH_H
#define DISJOINT_PATH_H
#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
#define V 6
class disjoint_Path
{
private:
    int graph[V][V];

public:
    disjoint_Path()
    {
        cout << "teste" << endl;
        memset(graph, 0, sizeof(graph));
        cout << "teste2" << endl;
    }

    bool bfs(int rGraph[V][V], int s, int t, int parent[]);
    int findDisjointPaths(int **graph, int s, int t);
};
#endif