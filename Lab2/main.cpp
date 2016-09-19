#include <stdio.h>

#define maxV 100

int V, E, x, y;
int a[maxV][maxV];
int count = 0;

void read_graph(void);

void print_graph(void);

void main() {
    read_graph();
    print_graph();

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
            for (y = 1; y <= V; y++){
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
            printf("a[ %d ][ %d ]= %d", x, y, a[x][y]);
        }
    }
}