#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue initQueue(unsigned int len){
    Queue myqueue;
    myqueue.len = len;
    myqueue.items = malloc(sizeof(int)*len);
    if (myqueue.items == NULL){
        exit(EXIT_FAILURE);
    }
    myqueue.first = myqueue.items;
    myqueue.last = myqueue.items;
    return myqueue;
}


void freeQueue(Queue *q){
    free(q->items);
}

void pushright(Queue *q, int element){
    if (q->last-q->items >= q->len){
        exit(EXIT_FAILURE);    
    }
    *q->last = element;
    q->last++;
}

int popleft(Queue *q){
    int value = *q->first;
    q->first++;

    return value;
}

int popright(Queue *q){
    int value = *(q->last-1);
    q->last--;
    return value;
}
