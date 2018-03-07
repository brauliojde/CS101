//  Braulio De La Torre
//  CS101
//  id:1496697
//  List.c
//  pa5
//
//  Created by Braulio De La Torre on 2/21/17.
//  Copyright (c) 2017 Braulio. All rights reserved.
//

#include "List.h"
#include <stdlib.h>
#include <string.h>

// structs --------------------------------------------------------------------

// private NodeObj type
typedef struct NodeObj{
    int info;
    struct NodeObj* next;
    struct NodeObj* prev;
} NodeObj;

// private Node type
typedef NodeObj* Node;

// private StackObj type
typedef struct ListObj{
    Node front;
    Node back;
    Node cursor;
    int length;
    int parent;
    int color;
    int dtime;
    int ftime;
    
    int distance;
} ListObj;



// Constructors-Destructors ---------------------------------------------------

// newNode()
// Returns reference to new Node object. Initializes next and data fields.
// Private.
Node newNode(int node_data){
    Node N = malloc(sizeof(NodeObj));
    N->info = node_data;
    N->next = NULL;
    return(N);
}

// freeNode()
// Frees heap memory pointed to by *pN, sets *pN to NULL.
// Private.
void freeNode(Node* pN){
    if( pN!=NULL && *pN!=NULL ){
        free(*pN);
        *pN = NULL;
    }
}

// newList()
// Returns reference to new empty List object.
List newList(void){
    List L;
    L = malloc(sizeof(ListObj));
    L->back = NULL;
    L->front= NULL;
    L->parent = NULL;
    L->color = 0;
    L->distance = NULL;
    L->length=0;
    L->dtime=0;
    L->ftime = 0;
    return(L);
}

// freeList()
// Frees all heap memory associated with List *pS, and sets *pS to NULL.
void freeList(List* pS){
    if(pS!=NULL && *pS!=NULL){
        while( length(*pS)>0 ) {
            deleteFront(*pS);
            
        }
        free(*pS);
        *pS = NULL;
    }
}



//Access Functions
int length(List L){
    return L->length;
}
int getColor(List L){
    return L->color;
    
}
void chColor(List L, int x){
    L->color = x;
}
int getDistance(List L){
    return L->distance;
}
void chDistance(List L, int x){
    L->distance=x;
}
int getlistParent(List L){
    return L->parent;
}

void chlistParent(List L, int x){
    L->parent=x;
}
int getDtime(List L){
    return L->dtime;
}
void chDtime(List L, int x){
    L->dtime = x;
}
int getFtime(List L){
    return L->ftime;
}
void chFtime(List L, int x){
    L->ftime = x;
}
int front(List L){
    if(length>0){
        return L->front->info;
    }else return -1;
};

int index1(List L){
    if(L->cursor!=NULL){
        Node temp0 = L->front;
        int b=0;
        while(temp0!=L->cursor){
            b++;
            temp0=temp0->next;
        }
        return b;
    }else return -1;
    
    
}

int back(List L){
    if(length>0){
        return L->back->info;
    }else return -1;
};
int get(List L){
    if(length>0 && index1(L)>=0){
        return L->cursor->info;
    }else return -1;
};
int equals(List A, List B){
    Node a = A->front;
    Node b = B->front;
    while(a!=NULL && b!=NULL){
        if(a->info!=b->info){
            return 0;
        }
        a=a->next;
        b=b->next;
    }
    return 1;
};

// Manipulation procedures ----------------------------------------------------
void clear1(List L){
    
    while(L->front!=NULL){
        deleteFront(L);
    }
};
void moveFront(List L){
    if(length>0){
        L->cursor=L->front;
    }
};
void moveBack(List L){
    if(length>0){
        L->cursor=L->back;
    }
};
void movePrev(List L){
    if(L->cursor!=NULL&&L->cursor!=L->front){
        L->cursor=L->cursor->prev;
    } else if (L->cursor != NULL && L->cursor==L->front){
        L->cursor=NULL;
        
    }
    
};
void moveNext(List L){
    if(L->cursor!=NULL&&L->cursor!=L->back){
        L->cursor=L->cursor->next;
        
    } else if (L->cursor != NULL && L->cursor == L->back){
        L->cursor=NULL;
        
    }
};
void prepend(List L, int data){
    Node b = newNode(data);
    
    if(L->length>0){
        b->next=L->front;
        L->front->prev=b;
        L->front=b;
        L->cursor=b;
        L->length++;
    }
    if(L->length==0){
        L->front=L->back=L->cursor= b;
        L->length++;
    }
};
void append(List L, int data){
    Node a = newNode(data);
    
    if(L->length>0){
        a->prev=L->back;
        L->back->next=a;
        L->back=L->back->next;
        L->cursor=a;
        L->length++;
    }
    if(L->length==0){
        L->front=L->back=L->cursor= a;
        L->length++;
    }
    
    
    
};
void insertBefore(List L, int data){
    Node tempb = newNode(data);
    
    if(L->length>0&&index1(L)>=0){
        if(L->cursor==L->front){
            L->cursor->prev=tempb;
            tempb->next=L->cursor;
            L->front=tempb;
            L->length++;
        }else{
            Node p;
            p=L->cursor->prev;
            p->next=tempb;
            tempb->next=L->cursor;
            tempb->prev=p;
            L->cursor->prev=tempb;
            L->length++;
        }
        
        
    }
};
void insertAfter(List L, int data){
    Node a = newNode(data);
    
    if(L->length>0&&index1(L)>=0){
        if(L->cursor==L->back){
            L->cursor->next=a;
            a->prev=L->cursor;
            L->back=a;
            L->length++;
        }else{
            Node n;
            n=L->cursor->next;
            L->cursor->next=a;
            a->prev=L->cursor;
            a->next=n;
            n->prev=a;
            L->length++;
            
        }
        
    }
}
void deleteFront(List L){
    if(L->length>0){
        Node temp,temp1;
        temp1=L->front;
        if(L->length==1){
            L->front = L->back = L->cursor = NULL;
        } else if(L->length>1){
            if(L->cursor==L->front){
                L->cursor=NULL;
            }
            temp=L->front->next;
            L->front->next->prev=NULL;
            L->front->next=NULL;
            L->front=temp;
            
        }
        L->length--;
        freeNode(&temp1);
        
    }
};
void deleteBack(List L){
    if(L->length){
        Node temp,temp1;
        temp1 = L->back;
        if(L->length==1){
            L->front = L->back = L->cursor = NULL;
            
        }else if(L->length>1){
            if(L->cursor==L->back){
                L->cursor=NULL;
            }
            temp = L->back->prev;
            L->back->prev->next=NULL;
            L->back->prev=NULL;
            L->back=temp;
        }
        L->length--;
        freeNode(&temp1);
    }
};
void delete(List L){
    Node tempd;
    if(L->length>0 && index1(L)>=0){
        if(L->cursor==L->front){
            tempd = L->front;
            deleteFront(L);
            
        }else if(L->cursor==L->back){
            tempd = L->back;
            deleteBack(L);
          
        }else {
            tempd = L->cursor;
            Node n,p;
            n=L->cursor->next;
            p=L->cursor->prev;
            n->prev=p;
            p->next=n;
            L->cursor->next=NULL;
            L->cursor->prev=NULL;
            freeNode(&tempd);
            L->length--;
            
        }
        
        
    }
    
};
List copyList(List L){
    Node a = L->front;
    List temp = newList();
    while(a!=NULL){
        append(temp, a->info);
        a=a->next;
    }
    return temp;
    
}

void printList(FILE* out, List L){
    Node c=L->front;
    while(c!=NULL){
        fprintf(out,"%d ",c->info);
        
        c=c->next;
    }
    //printf("\n");
};
