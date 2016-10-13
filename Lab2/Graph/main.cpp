#include <stdio.h>

#define maxV 20

int V = 1;
int x, y;
int Graph[maxV][maxV];
int TreeGraph[maxV][maxV];
int count = 0;
int component = 0;

void build_graph(void);

void print_graph(void);

void DFS(int G[maxV][maxV]);

void dfs(int x, int y);

int main() {
    build_graph();
    print_graph();

    return 0;
}


void DFS(int G[maxV][maxV]) {

    for (x = 1; x <= V; x++) {
        for (y = 1; y <= V; y++) {  // for each vertex

            if (0 == G[x][y]) {
                component = component + 1;
                dfs(x, y);
            }
        }
    }
}

void dfs(int x, int y) {
    int i;

    count = count + 1;
    Graph[x][y] = count;    // mark the vertex v with "count"

    for (i = 1; i <= 7; i++) {  //for each vertex w, adjacent with to v
        if (i != y) {
            if(Graph[x][i] == 0){
                dfs(x, i);
            }
        }
    }

}

void build_graph(void) {
    int edge, x;
    printf("\nInput number of vertices :");
    scanf("%d", &V);

    if (V > maxV) {
        printf("Exceed the maximum number of vertices permitted");
    }
    else {
        for (x = 1; x <= V; x++) {
            for (y = 1; y <= V; y++) {
                a[x][y] = 0;
            }
        }

        for (x = 1; x <= V; x++) {
            for (y = x; y <= V; y++) {
                printf("\na[ %d ][ %d ]=", x, y);
                scanf("%d", &edge);
                a[x][y] = edge;
                a[y][x] = edge;
            }
        }
    }
}

void print_graph(void) {
    int x, y;
    for (x = 1; x <= V; x++) {

        for (y = 1; y <= V; y++) {
            printf("a[ %d ][ %d ]= %d \n", x, y, a[x][y]);
        }
    }
}