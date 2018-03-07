//  Braulio De La Torre
//  CS101
//  id:1496697
//  FindPath.c
//  pa4
//
//  Created by Braulio De La Torre on 2/28/17.
//  Copyright (c) 2017 Braulio. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include"List.h"
#include"Graph.h"

FILE *fp;
FILE *fin;
int main(int argc, char* argv[]){

    char line[256];
    char *linep[256];
    int lines =0;


   
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
    
    //fscanf(fin, "%d", &a);
    //printf("%d", n);
    Graph G =  newGraph(n);
    while(check!=1){
        fscanf(fin, "%d", &source);
        fscanf(fin, "%d", &destination);
        if(source==0){
            check=1;
            
        }else{
            addEdge(G, source, destination);
            BFS(G, source);
        }
            
            
    }
    
    //printGraph(stdout, G);
    printGraph(fp, G);
    fprintf(fp, "\n");
    List path  = newList();
    int length = 0;
    check = 0;
    if(!feof(fin)){
        while(check!=1){
            fscanf(fin, "%d", &source);
            fscanf(fin, "%d", &destination);
            if(source==0){
                check =1;
            }else{
                BFS(G, source);
                getPath(path, G, destination);
                length = getDist(G, destination);
                if(length==-1){
                    fprintf(fp,"The distance from %d to %d is infinity\n", source, destination);
                    
                }else{
                    fprintf(fp,"The distance from %d to %d is %d\n", source, destination, length);
                    fprintf(fp,"The shortest %d-%d path is:", source, destination);
                    
                }
                
                if(length==0){
                    fprintf(fp," %d\n",source);
                }else if(length==-1){fprintf(fp,"No %d-%d path exists\n",source,destination); }else{printList(fp, path);}
                clear1(path);
                fprintf(fp,"\n \n");
                
            }
            
        }
    
    }

    


    

    fclose(fin);
    fclose(fp);
    
    freeGraph(&G);
    freeList(&path);



    EXIT_SUCCESS;

}