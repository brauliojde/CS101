//  Braulio De La Torre
//  CS101
//  id:1496697
//  Graph.c
//  pa4
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
    
    List* array;
} GraphObj;

Graph newGraph(int n){
    
    Graph G = malloc(sizeof(GraphObj));
    assert( G!= NULL);
    G->source = NIL;
    G->parent = NIL;
    G->verticies = n;
    G->size=0;
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
        
        free(*pG);
        *pG = NULL;
    }
}


//BFScall is used to check when BFS has been called, if 0, then function BFS has not been called
//if 1, then BFS has been called
int BFScall = 0;


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
    
    if(BFScall==0){
        return NIL;
    } else{
        return G->source;
    }
    
}
//getParent() will return the parent of vertex u in the BreadthFirst tree created by BFS(), or NIL if BFS() has not yet been called.
int getParent(Graph G, int u){
    if(u<1 || u>getOrder(G)){
        fprintf(stderr, "getParent must satisfy the condition 1 <= u <= getOrder(G)");
    }
    if(BFScall==0){
        return NIL;
    } else{
     return getlistParent(G->array[u]);
    }
    
    
}
//returns the distance from the most recent BFS source to vertex u, or INF if BFS() has not been called
int getDist(Graph G, int u){
    if(u<1 || u>getOrder(G)){
        fprintf(stderr, "getDist must satisfy the condition 1 <= u <= getOrder(G)");
    }
    if(BFScall==0){
        return INF;
    } else{
        return getDistance(G->array[u]);
    }
    
    
}




//getPath() has the precondition getSource(G)!=NIL, so BFS() must be called before getPath().
void getPath(List L, Graph G, int u){
    if(u<1 || u>getOrder(G)){
        fprintf(stderr, "getPath must satisfy the condition 1 <= u <= getOrder(G)");
    }
    
    if(getSource(G)==NIL){
        fprintf(stderr, "getPath can only be called after BFS() is called ");
    }
    
    List temp = newList();
    

    int x = INF;
    int parent = u;
    int count =0;
    
    
    if(getParent(G,u)!=NIL){
    while(x!=NIL){
        x = getParent(G,parent);
        if(x!=NIL){
            append(temp, x );
        }
        if(x==G->source){
            x=NIL;
        }
        parent = x;
        count++;
    }}
    prepend(temp, u);
    moveBack(temp);
    if(count!=0){
    while(length(temp)>0){
        append(L, get(temp));
        deleteBack(temp);
        moveBack(temp);
    }
    }else{
        append(L, NIL);
    }
    
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
    
    
    
    if(u == v){}else{
    
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
    
    
    

}

//addArc() inserts a new directed edge from u to v, i.e. v is added to the adjacency List of u (but not u to the adjacency List of v).
void addArc(Graph G, int u, int v){
    int check = 0;
    int prev;
    int temp = prev = 0;
    int next = 0;
    moveFront(G->array[u]);
    
    if(u == v){}else{
        
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
}


void BFS(Graph G, int s){
    BFScall = 1;
    G->source = s;
   // chRecent(L, s);
    List Q = newList();
    List temp;
    int x=0,y=0;
    for(int i =1;i<=getOrder(G);i++){
        chColor(G->array[i],1);
        chDistance(G->array[i],INF);
        chlistParent(G->array[i],NIL);
    }
    chColor(G->array[s],2);
    chDistance(G->array[s],0);
    chlistParent(G->array[s],NIL);
    append(Q,s);
    while (length(Q)!=0) {
        moveFront(Q);
        x = get(Q);
        deleteFront(Q);
        temp=G->array[x];
        moveFront(temp);
        for(int i =0; i<length(temp);i++){
            
            y = get(temp);
            if(getColor(G->array[y])==1){
                chColor(G->array[y],2);
                chDistance(G->array[y],getDistance(G->array[x])+1);   //////--CHECK!!!!--///////////////
                chlistParent(G->array[y],x);
                append(Q, y);
            }
            moveNext(temp);
        }
        chColor(G->array[x],3);
        
    }
    
    clear1(Q);
    freeList(&Q);
    
    //clear1(temp);
    //temp = NULL;
   //freeList(&temp);
   
    
    
}
/*** ---------------------- ***/



/*** ---------------------- ***/

/*** Other operations ***/
void printGraph(FILE* out, Graph G){
    for(int i = 1; i<=getOrder(G); i++){
        fprintf(out,"%d: ", i);
        printList(out, G->array[i]);
        fprintf(out,"\n");
    }

}







