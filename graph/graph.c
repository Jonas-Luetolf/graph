#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>

Graph createGraph(unsigned int len){
    Graph mygraph;

    mygraph.len = len;
    mygraph.table = malloc(sizeof(int *)*len);
    if (mygraph.table == NULL){
        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < len; i++) {
        mygraph.table[i] = malloc(sizeof(int) * len);
        if (mygraph.table[i] == NULL){
            exit(EXIT_FAILURE);
        }

    }

        return mygraph;
}

void freeGraph(Graph *g){
    free(g->table);
}

void addDirectedEdge(Graph *g, unsigned int from, unsigned int to){
    if (from < g->len && to < g->len){    
    g->table[from][to] = 1;
    }
}

void addEdge(Graph *g, unsigned int from, unsigned int to){
    addDirectedEdge(g, from, to);
    addDirectedEdge(g, to, from);
}

bool hasEdge(Graph *g, unsigned int from, unsigned int to){
    if (from < g->len && to < g->len) {
        return g->table[from][to] != 0;
    }

    else {
        return false;
    }
}



void printGraph(Graph *g){
    for (unsigned int i=0; i<g->len;i++){
        for (unsigned int j=0; j<g->len;j++){
            if (g->table[i][j] != 0){
                printf("%d -> %d \n", i, j);
            }
        }
    }
}
