//  Braulio De La Torre
//  CS101
//  id:1496697
//  Graph.h
//  pa5
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
int getParent(Graph G, int u); /* Pre: 1<=u<=n=getOrder(G) */
int getDiscover(Graph G, int u); /* Pre: 1<=u<=n=getOrder(G) */
int getFinish(Graph G, int u);
Graph transpose(Graph G);
Graph copyGraph(Graph G);

/*** ---------------------- ***/

/*** Manipulation procedures ***/
void makeNull(Graph G);
void addEdge(Graph G, int u, int v);
void addArc(Graph G, int u, int v);
void DFS(Graph G, List S);
void Visit(Graph G, int list, List S);
void prepend2Graph(Graph G, int u, int v);
/*** ---------------------- ***/

/*** Other operations ***/
void printGraph(FILE* out, Graph G);
void printGraphssc(FILE* out, Graph G);
/*** ---------------------- ***/

#endif /* defined(__pa4__Graph__) */
