#include <stdio.h>

#define maxV 10

int V, E, x, y;
int a[maxV][maxV];
int visit[maxV];
int visit_cntr; // to assign visiting order to each nodes
int component[maxV]; // to count components of the graph
int component_cntr;
int parent[maxV] = {0}; // parent of each each vertex


void read_graph(void);

void print_graph(void);

void DFS(int G[maxV][maxV]);

void dfs(int v);

void search_cycle();

int cycle(int x);

int main() {
    int i;

    read_graph();
    print_graph();
    DFS(a);

    printf("visiting sequence: ");
    for (i = 1; i <= V; i++) {
        printf("[%d]", visit[i]);
    }
    printf("\n");

    printf("component: ");
    for (i = 1; i <= V; i++) {
        printf("[%d]", component[i]);
    }
    printf("\n");

    printf("parent: ");
    for (i = 1; i <= V; i++) {
        printf("[%d]", parent[i]);
    }
    printf("\n");

    printf("tree_edge -> 2, back_edge -> 1\n");
    print_graph();

    search_cycle();
}


void DFS(int G[maxV][maxV]) {
    int i;

    // initialize counter variables
    visit_cntr = 0;
    component_cntr = 0;


    // initialize arrays
    for (i = 1; i <= V; i++) {
        visit[i] = 0; // mark each vertex with 0(unvisited)
        component[i] = 0;
    }

    for (i = 1; i <= V; i++) {
        if (visit[i] == 0) { // if v is marked with  0,
            component_cntr = component_cntr + 1;
            dfs(i);
        }
    }
}

void dfs(int v) {
    int w;
    component[v] = component_cntr;
    visit_cntr = visit_cntr + 1;
    visit[v] = visit_cntr;  // mark v with visit_cntr

    for (w = 1; w <= V; w++) {
        if (a[v][w] != 0) {   // adjacent
            if (visit[w] == 0) {

                a[v][w] = 2;
                a[w][v] = 2;

                parent[w] = v;
                dfs(w);
            }
        }
    }

}

void read_graph(void) {
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
            printf("%d ", a[x][y]);
        }
        printf("\n");
    }
}

void search_cycle() {
    int i, j, checker;
    int number_of_component = component[V];

    j = 0;
    for (i = 1; i <= number_of_component; i++) {
        printf("component %d: ", i);

        while (1) {
            j = j + 1;
            checker = cycle(j);
            if (checker == 1) {
                printf("True\n");
                break;
            }
            if (checker != 1) {
                printf("False\n");
                break;
            }
        }
    }
}

int cycle(int x) {
    int i;
    for (i = 1; i <= V; i++) {
        if (a[x][i] == 1) {
            return 1;
        }
    }
    return 0;
}
