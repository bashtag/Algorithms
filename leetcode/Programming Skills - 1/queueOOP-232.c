#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_LENGHT 100

typedef struct {
    int values[STACK_LENGHT];
    int top;
	int bot;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *obj = (MyQueue *)calloc(1, sizeof(MyQueue));
    obj->top = 0;
    obj->bot = 0;

    return (obj);
}

void myQueuePush(MyQueue* obj, int x) {
    if (obj->top + 1 >= STACK_LENGHT) return;
    
    obj->values[(obj->top)++] = x;
}

int myQueuePop(MyQueue* obj) {
    return obj->values[(obj->bot)++];
}

int myQueuePeek(MyQueue* obj) {
    return obj->values[(obj->bot)];
}

bool myQueueEmpty(MyQueue* obj) {
	return (obj->bot == obj->top);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/