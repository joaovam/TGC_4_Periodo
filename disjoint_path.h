#ifndef DISJOINT_PATH_H
#define DISJOINT_PATH_H
#include <iostream>
#include <queue>
#include <stack>
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

        memset(graph, 0, sizeof(graph));
    }

    bool bfs(int rGraph[V][V], int s, int t, int parent[]);
    void Run(int **graph, int s, int t);
    int findDisjointPaths(int **graph, int s, int t);
    void dfs(int s, int t);
    void dfsREC(int, int);
};
#endif