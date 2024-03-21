#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>
typedef struct queue{
    int *items;
    unsigned int len;
    unsigned int n;
    int *first;
    int *last;
} Queue;

bool isempty(Queue *q);
bool isinqueue(Queue *q, int element);


Queue initQueue(unsigned int len);
void freeQueue(Queue *q);
void pushright(Queue *q, int element);

int popleft(Queue *q);
int popright(Queue *q);


#endif
