#include <stdio.h>
#include <stdlib.h>

int comparator(const void* a, const void* b) {
    return ((int*)a)[2] - ((int*)b)[2];
}

void makeSet(int parent[], int rank[], int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int component) {
    if (parent[component] == component)
        return component;
    return parent[component] = findParent(parent, parent[component]);
}

void unionSet(int u, int v, int parent[], int rank[]) {
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (u == v) return;
    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

int kruskalAlgo(int nodes, int edges, int edge[edges][3]) {
    qsort(edge, edges, sizeof(edge[0]), comparator);
    int parent[nodes];
    int rank[nodes];
    makeSet(parent, rank, nodes);
    int minCost = 0;
    for (int i = 0; i < edges; i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];
        if (findParent(parent, u) != findParent(parent, v)) {
            unionSet(u, v, parent, rank);
            minCost += wt;
        }
    }
    return minCost;
}

int main() {
    int edge[5][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    int nodes = 4;
    int edges = 5;
    printf("%d\n", kruskalAlgo(nodes, edges, edge));
    return 0;
}
