#ifndef GRAPH_H
#define GRAPH_H
#include <stdbool.h>
#include <sys/types.h>
typedef struct Graph{
    unsigned int len;
    int **table;

}Graph;



Graph createGraph(unsigned int len);
void freeGraph(Graph *g);


void addEdge(Graph *g, unsigned int from, unsigned int to,int weight);
void addDirectedEdge(Graph *g, unsigned int from, unsigned int to, int weight);

bool hasEdge(Graph *g, unsigned int from, unsigned int to);
int * getneighbours(Graph *g, unsigned int node, int* retsize);


void printGraph(Graph *g);
#endif
