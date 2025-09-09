#include <stdio.h>
#include <stdbool.h>

#define MAX 10000

int adj[MAX][MAX], visited[MAX], V, E;

bool dfs(int v, int parent) {
    visited[v] = 1;
    for (int u = 0; u < V; u++) {
        if (adj[v][u]) {
            if (!visited[u]) {
                if (dfs(u, v)) return true;
            } 
            else if (u != parent) return true;
        }
    }
    return false;
}

int main() {
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a][b] = adj[b][a] = 1;
    }
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dfs(i, -1)) {
            printf("true\n");
            return 0;
        }
    }
    printf("false\n");
    return 0;
}
