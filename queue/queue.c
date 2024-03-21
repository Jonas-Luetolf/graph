#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
Queue initQueue(unsigned int len){
    Queue myqueue;
    myqueue.len = len;
    myqueue.n = 0;
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

int * movePointer(int *s, int *p, unsigned int len, int step){
    return s + (p-s+step)%len;
}

bool isempty(Queue *q){
    return q->n == 0;
}

bool isinqueue(Queue *q, int element){
    for (int *i = q->first; i!=q->last;){
        if (*i == element){
            return true;
        }

        i = movePointer(q->items, i, q->len, 1);

    }
    return false;
}


void pushright(Queue *q, int element){
    if (q->last == q->first && !isempty(q)){
        printf("queue full\n");
        exit(EXIT_FAILURE);    
    }
    q->n +=1;
    *q->last = element;
     q->last = movePointer(q->items, q->last, q->len, 1);
}

int popleft(Queue *q){
    int value = *q->first;
    q->first = movePointer(q->items, q->first, q->len, 1);
    q->n -=1;
    return value;
}

int popright(Queue *q){
    int value = *(q->last-1);
    q->last = movePointer(q->items,q->last,q->len, -1);
    q->n-=1;
    return value;
}
