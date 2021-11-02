#ifndef DISJOINT_H
#define DISJOINT_H
#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#define V 11
class Disjoint_Paths
{
    bool bfs(int rGraph[V][V], int s, int t, int parent[]);
    int findDisjointPaths(int graph[V][V], int s, int t);
};

#endif