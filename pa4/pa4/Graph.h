//  Braulio De La Torre
//  CS101
//  id:1496697
//  Graph.h
//  pa4
//
//  Created by Braulio De La Torre on 2/21/17.
//  Copyright (c) 2017 Braulio. All rights reserved.
//

#ifndef __pa4__Graph__
#define __pa4__Graph__

#include"List.h"
#include <stdio.h>

typedef struct GraphObj* Graph;


/*** Constructors-Destructors ***/
Graph newGraph(int n);
void freeGraph(Graph* pG);
/*** ---------------------- ***/

/*** Access functions ***/
int getOrder(Graph G);
int getSize(Graph G);
int getSource(Graph G);
int getParent(Graph G, int u);
int getDist(Graph G, int u);
int dist(Graph G, int source, int vertex, int sum);
void getPath(List L, Graph G, int u);
/*** ---------------------- ***/

/*** Manipulation procedures ***/
void makeNull(Graph G);
void addEdge(Graph G, int u, int v);
void addArc(Graph G, int u, int v);
void BFS(Graph G, int s);
/*** ---------------------- ***/

/*** Other operations ***/
void printGraph(FILE* out, Graph G);
/*** ---------------------- ***/

#endif /* defined(__pa4__Graph__) */
