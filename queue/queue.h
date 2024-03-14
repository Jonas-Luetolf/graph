#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue{
    int *items;
    unsigned int len;
    int *first;
    int *last;
} Queue;

Queue initQueue(unsigned int len);
void freeQueue(Queue *q);
void pushright(Queue *q, int element);

int popleft(Queue *q);
int popright(Queue *q);


#endif
