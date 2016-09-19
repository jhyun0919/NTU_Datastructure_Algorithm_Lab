#include <stdio.h>

#define MAX 5

int t, var, i;
int marks[MAX + 1];

void marks_array_init(void);

void insert_marks(int);

int main() {
    marks_array_init();

    for (i = 0; i <= 5; i++) {
        printf("\nInput marks for Student %d ==>", i);
        scanf("%d", &var);
        insert_marks(var);
    }

    for (i = 0; i <= 5; i++) {
        if (marks[i] > 50) {
            printf("Student %d : Pass\n", i);
        }
        else {
            printf("Student %d : Fail\n", i);
        }
    }

    return 0;
}

void marks_array_init(void) {
    t = -1;
}

void insert_marks(int x) {
    t = t + 1;
    marks[t] = x;
}