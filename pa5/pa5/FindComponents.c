//  Braulio De La Torre
//  CS101
//  id:1496697
//  FindComponents.c
//  pa5
//
//  Created by Braulio De La Torre on 3/11/17.
//  Copyright (c) 2017 Braulio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include"List.h"
#include"Graph.h"

FILE *fp;
FILE *fin;
int main(int argc, char* argv[]){
    if(argc>3){
        fprintf(stderr, "too many arguments, input and output file are only needed");
    }
    if(argc<3){
        fprintf(stderr, "not enough arguments, input and output file are needed");
    }
    
    fin = fopen(argv[1], "r");
    fp = fopen(argv[2], "w");
    if(fin == NULL){
        
        exit(EXIT_FAILURE);
    }
    
    
    int n = 0;
    int check = 0;
    int source = 0;
    int destination = 0;
    
    fscanf(fin, "%d", &n);
    List L = newList();
    for(int i=1;i<=n;i++ ){
        append(L, i);
    }
    Graph T=NULL, C=NULL;
    Graph G =  newGraph(n);
    while(check!=1){
        fscanf(fin, "%d", &source);
        fscanf(fin, "%d", &destination);
        if(source==0){
            check=1;
            
        }else{
            addArc(G, source, destination);
            
        }
        
        
    }
    //printGraph(stdout, G);
    DFS(G, L);
    for(int i=1; i<=n; i++){
        fprintf(fp, "%d: %2d %2d %2d\n", i, getDiscover(G, i), getFinish(G, i), getParent(G, i));
    }
    printList(fp, L);
    T = transpose(G);
    C = copyGraph(G);
//    fprintf(stdout, "\n");
//    printGraph(stdout, C);
//    fprintf(stdout, "\n");
//    printGraph(stdout, T);
//    fprintf(stdout, "\n");
//    
    
    DFS(T, L);
    fprintf(fp, "\n");
    fprintf(fp, "x:  d  f  p\n");
    for(int i=1; i<=n; i++){
        fprintf(fp, "%d: %2d %2d %2d\n", i, getDiscover(T, i), getFinish(T, i), getParent(T, i));
    }
    printList(fp, L);
    int scc = 0;
    //gets number of SCC's
    moveFront(L);
    //gets number of strongly connected components
    for(int i =1;i<=length(L);i++){
        
        int a = get(L);
        if(getParent(T, a)==0){
            scc++;
        }
        moveNext(L);
    }
    //printf("%d\n", scc);
    
    
    Graph test = newGraph(scc);
    moveBack(L);
    //creates a graph of strongly connected components
    for(int i =1;i<=scc;i++){
        
        int a = get(L);
        while(getParent(T, a)!=0){
            prepend2Graph(test, i, a);
            
            movePrev(L);
            a = get(L);
        }
        if(getParent(T, a)==0){
            prepend2Graph(test, i, a);
        }
        movePrev(L);
    }
    fprintf(fp,"Adjacency list representation of G:\n");
    printGraph(fp, G);
    fprintf(fp,"\n");
    
    fprintf(fp, "G contains %d strongly connected components:\n", scc);
    printGraphssc(fp, test);
    
    fclose(fin);
    fclose(fp);
    
    freeList(&L);
    freeGraph(&G);
    freeGraph(&T);
    freeGraph(&test);
    freeGraph(&C);
    return(0);

   



}
