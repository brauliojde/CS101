//  Braulio De La Torre
//  CS101
//  id:1496697
//  pa5
//  Graph.c
//
//  Created by Braulio De La Torre on 2/21/17.
//  Copyright (c) 2017 Braulio. All rights reserved.
//
#include<stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "List.h"
#include<assert.h>
#define INF -1
#define NIL 0




typedef struct GraphObj{
    int verticies;//also called order
    int size; //number of edges in graph
    int source; //initiated when BFS is called
    int parent; //also initiated when BFS is called
    int time;
    
    List* array;
} GraphObj;

Graph newGraph(int n){
    
    Graph G = malloc(sizeof(GraphObj));
    assert( G!= NULL);
    G->source = NIL;
    G->parent = NIL;
    G->verticies = n;
    G->size=0;
    G->time=0;
    G->array = malloc((n+1)*sizeof(List));
    
    for(int i =1;i<=n;i++){
        G->array[i] = newList();
        
    }
    return(G);
}

void freeGraph(Graph* pG){
    Graph G = *pG;
    if(pG!=NULL && *pG != NULL){
        for(int i = 1;i<=G->verticies; i++){
            freeList(&(G->array[i]));
        }
        free(G->array);
        free(*pG);
        *pG = NULL;
    }
}


//BFScall is used to check when BFS has been called, if 0, then function BFS has not been called
//if 1, then BFS has been called
int DFScall = 0;


/**** Access Functions ****/

int getOrder(Graph G ){
    return G->verticies;
}
//size of a graph is the number of edges it has
int getSize(Graph G){
    return G->size;
}
//getSource() returns the source vertex most recently used in function BFS(), or NIL if BFS() has not yet been called.
int getSource(Graph G){
    
    if(DFScall==0){
        return NIL;
    } else{
        return G->source;
    }
    
}
//getParent() will return the parent of vertex u in the BreadthFirst tree created by BFS(), or NIL if DFS() has not yet been called.
int getParent(Graph G, int u){
    if(u<1 || u>getOrder(G)){
        fprintf(stderr, "getParent must satisfy the condition 1 <= u <= getOrder(G)");
    }
    if(DFScall==0){
        return NIL;
    } else{
     return getlistParent(G->array[u]);
    }
    
    
}

int getDiscover(Graph G, int u){
    return getDtime(G->array[u]);
} /* Pre: 1<=u<=n=getOrder(G) */
int getFinish(Graph G, int u){
    return getFtime(G->array[u]);

}





/*** ---------------------- ***/


//COLORS: white=1, grey=2, black=3

/*** Manipulation procedures ***/

//Function makeNull() deletes all edges of G, restoring it to its original (no edge) state
void makeNull(Graph G){
    for(int i = 1; i<getOrder(G); i++){
        clear1(G->array[i]);
    }
}

//addEdge() inserts a new edge joining u to v, i.e. u is added to the adjacency List of v, and v to the adjacency List of u
void addEdge(Graph G, int u, int v){
    
    if(u> getOrder(G) || v> getOrder(G) || u<1 || v<1 ){
        fprintf(stderr, "addEdge, the arguments u and v must be within the bounds of 1 <= u,v <= getOrder(G) ");
        exit(EXIT_FAILURE);
    }
    
    int check = 0;
    int prev;
    int temp = prev = 0;
    int next = 0;
    moveFront(G->array[u]);
    moveFront(G->array[v]);
    
    
    
    
        
        while(check==0){
            
            temp = get(G->array[u]);
            
            if(temp == v ){
                check = 1;
            } else if(v<temp){
                insertBefore(G->array[u], v);
                G->size++;
                check = 1 ;
            } else if(v>temp){
                moveNext(G->array[u]);
            }
            
            if(get(G->array[u])==-1){
                append(G->array[u],v);
                G->size++;
                check = 1;
            }
            
            next  = temp;
            
        }
        
        check = 0;
        
        
        while(check ==0){
            temp = get(G->array[v]);
            
            if(temp == u ){
                check = 1;
            } else if(u<temp){
                insertBefore(G->array[v], u);
                
                G->size++;
                check = 1 ;
            } else if(u>temp){
                moveNext(G->array[v]);
            }
            
            if(get(G->array[v])==-1){
                append(G->array[v],u);
                G->size++;
                check = 1;
            }
            
            next  = temp;
        }
        
        
    
    
    
    
    
}

//addArc() inserts a new directed edge from u to v, i.e. v is added to the adjacency List of u (but not u to the adjacency List of v).
void addArc(Graph G, int u, int v){
    int check = 0;
    int prev;
    int temp = prev = 0;
    int next = 0;
    moveFront(G->array[u]);
    
    
        
        while(check==0){
            
            temp = get(G->array[u]);
            
            if(temp == v ){
                check = 1;
            } else if(v<temp){
                insertBefore(G->array[u], v);
                G->size++;
                check = 1 ;
            } else if(v>temp){
                moveNext(G->array[u]);
            }
            
            if(get(G->array[u])==-1){
                append(G->array[u],v);
                G->size++;
                check = 1;
            }
            
            next  = temp;
            
        }
    
}

void DFS(Graph G, List S){
    DFScall=1;
    List Q = newList();
    if(length(S)!=getOrder(G)){
        printf(stderr,"DFS error, Length of list S does not coincide with order of G");
        exit(EXIT_FAILURE);
    }
    int valS=0;
    
    if(length(S)==0){
        return;
    }
    //initialize array colors and parents to white and no parent
    for(int i = 1; i<=getOrder(G);i++){
        chColor(G->array[i], 1);
        chlistParent(G->array[i], NIL);
    }
    moveFront(S);
    
    
    while(get(S)!=-1){
        valS = get(S);
        if(getColor(G->array[valS])==1){
            Visit(G,valS, Q);
        }
        moveNext(S);
    }
    clear1(S);
    moveFront(Q);
    while(get(Q)!=-1){
        prepend(S, get(Q));
        moveNext(Q);
    }
    clear1(Q);
    freeList(&Q);
    

}
//Visit needs entire Graph with indicie of first List that is going to be worked on
void Visit(Graph G, int list, List S){
    
    List temp = G->array[list];
    int tempint=0;
    
    chColor(G->array[list], 2);
    chDtime(G->array[list], ++G->time);
    moveFront(G->array[list]);
    while(get(temp)!=-1){
        tempint = get(temp);
        if (getColor(G->array[tempint])==1) {
            chlistParent(G->array[tempint], list);
            Visit(G,tempint,S);
            
            
        }
        moveNext(temp);
    }
    chColor(temp, 3);
    chFtime(temp, ++G->time);
    append(S, list);
}
/*** ---------------------- ***/

Graph transpose(Graph G){
    Graph Gt = newGraph(getOrder(G));
    int a =0;
    for(int j=1;j<=getOrder(G);j++){
    
        if(length(G->array[j])>0){
            moveFront(G->array[j]);
            while (get(G->array[j])!=-1) {
                a = get(G->array[j]);
                addArc(Gt, a, j);
                moveNext(G->array[j]);
            }
            
            
        }
    }
    return Gt;
    
}
Graph copyGraph(Graph G){
    Graph Gc = newGraph(getOrder(G));
    int a =0;
    for(int j=1;j<=getOrder(G);j++){
        
        if(length(G->array[j])>0){
            moveFront(G->array[j]);
            while (get(G->array[j])!=-1) {
                a = get(G->array[j]);
                addArc(Gc, j, a);
                moveNext(G->array[j]);
            }
            
            
        }
    }
    return Gc;
}


void prepend2Graph(Graph G, int u, int v){
    prepend(G->array[u], v);
}

/*** ---------------------- ***/

/*** Other operations ***/
void printGraph(FILE* out, Graph G){
    for(int i = 1; i<=getOrder(G); i++){
        fprintf(out,"%d: ", i);
        printList(out, G->array[i]);
        fprintf(out,"\n");
    }
  


}

void printGraphssc(FILE* out, Graph G){
    for(int i = 1; i<=getOrder(G); i++){
        fprintf(out,"Component %d: ", i);
        printList(out, G->array[i]);
        fprintf(out,"\n");
    }

}



