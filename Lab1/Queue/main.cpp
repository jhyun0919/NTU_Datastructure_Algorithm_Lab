#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

int r, f, i, var, result;
int data[SIZE];

void queue_init();
bool empty();
void enqueue(int val);
void dequeue();
int front();
int function_select(int item);

int main() {
    // make the queue empty
    queue_init();
    // return true if the stack is empty. Return false if the stack is not empty
    empty();

    // test your program
    while(var != -999){

        printf("f = %d\nr = %d\n", f, r);
        for (i = 0; i<SIZE; i++){
            printf("%d ", data[i]);
        }

        printf("\nInput value %d [exit : -999]=> ", i);
        scanf("%d", &var);

        if(var != -999){
            result = function_select(var);

            if (result > 0){
                printf("%d\n", result );
            }
        }
    }
    return 0;
}

void queue_init() {
    r = -1;
    f = -1;
}

bool empty() {
    return (r==-1 && f==-1);
}

void enqueue(int val) {
    if (empty()) {
        r = 0;
        f = 0;
    }
    else {
        r = r + 1;

        if (r == SIZE){
            r = 0;
            if (r == f){
                printf("Error - Queue is full.\n");
                r = SIZE - 1;
                return;
            }
        }
        else{
            if(r == f){
                printf("Error - Queue is full.\n");
                r = r - 1;
                return;
            }
        }
    }

    data[r] = val;
}

void dequeue() {
    if (r == f) {
        r = -1;
        f = -1;
    }
    else {
        f = f + 1;
        if (f == SIZE) {
            f = 0;
        }
    }
}

int front() {
    return data[f];
}

int function_select(int item){
    if (item < 0) {
        if(empty()){
            printf("Error - Queue is empty.\n");
            return -1;
        }
        return front();
    }
    else if(item == 0){
        if(empty())
            printf("Error - Queue is empty.\n");
        dequeue();
    }
    else{
        enqueue(item);
    }

    return -1;
}
