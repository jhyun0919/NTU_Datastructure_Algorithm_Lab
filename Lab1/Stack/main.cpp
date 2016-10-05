#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

int t, i, var, result, iter;
char checker;
int data[SIZE];

void stack_init();

bool empty();

void push(int val);

void pop();

int top();

int function_select(int item);

int main() {

    do {
        // make the stack empty
        stack_init();
        // return true if the stack is empty. Return false if the stack is not empty
        empty();
        printf("put number of iterations : ");
        scanf("%d", &iter);

        // test your program
        for (i = 1; i <= iter; i++) {
            printf("\nInput value %d => ", i);
            scanf("%d", &var);

            result = function_select(var);

            if (result > 0) {
                printf("%d\n", result);
            }
        }

        while (1) {
            fflush(stdin);
            printf("Do you want to test again? [y/n]");
            scanf("%c", &checker);

            if (checker == 'y' | checker == 'Y' | checker == 'n' | checker == 'N')
                break;
            else
                printf("wrong input.\n");
        }
    } while (checker == 'y' | checker == 'Y');

    return 0;
}


void stack_init() {
    t = -1;
}

bool empty() {
    return t == -1;
}

void push(int val) {
    t = t + 1;
    data[t] = val;
}

void pop() {
    t = t - 1;
}

int top() {
    return data[t];
}

int function_select(int item) {
    if (item < 0) {
        if (empty()) {
            printf("Error - Stack is empty.\n");
            return -1;
        }
        return top();
    }
    else if (item == 0) {
        if (empty())
            printf("Error - Stack is empty.\n");
        pop();
    }
    else {
        push(item);
    }

    return -1;
}
