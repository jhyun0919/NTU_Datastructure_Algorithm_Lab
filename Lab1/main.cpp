#include <studio.h>

#define MAX 5

int t, var, i;
int marks[MAX + 1];

void marks_array_init(void);

void insert_marks(int);

void main() {
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

    void marks_array_init(void) {
        t = -1;
    }

    void insert_marks(int) {
        t = t + 1;
        marks[t] = x;
    }
}