//
//  pa2.c
//  pa2
//
//  Created by Braulio De La Torre on 1/21/17.
//
//

#include "List.h"

// structs --------------------------------------------------------------------

// private NodeObj type
typedef struct NodeObj{
    int data;
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
    int index;
} ListObj;



// Constructors-Destructors ---------------------------------------------------

// newNode()
// Returns reference to new Node object. Initializes next and data fields.
// Private.
Node newNode(int node_data){
    Node N = malloc(sizeof(NodeObj));
    N->data = node_data;
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
    L = malloc(sizeof(StackObj));
    L->back = NULL;
    L->front= NULL;
    L->height = 0;
    L->index = NULL;
    return(L);
}

// freeList()
// Frees all heap memory associated with List *pS, and sets *pS to NULL.
void freeList(List* pS){
    if(pS!=NULL && *pS!=NULL){
        while( !isEmpty(*pS) ) {
            //pop(*pS);
        }
        free(*pS);
        *pS = NULL;
    }
}

//Access Functions
int length(List L){
    return L->length;
}

int index(List L){
    if(L->cursor!=NULL){
        Node a = L->Front;
        int b=0;
        while(a!=cursor){
            b++;
            a=a->next;
        }
        return b;
    }else return -1;
    

}
int front(List L){
    if(length>0){
        return front->data;
    }else return -1;
};
int back(List L){
    if(length>0){
        return back->data;
    }else return -1;
};
int get(List L){
    if(length>0 && index(L)>=0){
        return cursor->data;
    }else return -1;
};
int equals(List A, List B){
    Node a = front;
    Node b = B->front;
    while(a!=NULL){
        if(a->data!=b->data){
            return false;
        }
        a=a->next;
        b=b->next;
    }
    return true;
};

// Manipulation procedures ----------------------------------------------------
void clear(List L){
    freeList(L*);
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
    } else if (L->cursor != NULL && L->Cursor==L->front){
        L->cursor=NULL;
        
    }

};
void moveNext(List L){
    if(L->cursor!=NULL&&L->cursor!=L->back){
        L->cursor=L->cursor->next;
        
    } else if (L->cursor != NULL && L->Cursor == L->back){
        L->cursor=NULL;
        
    }
};
void prepend(List L, int data){
    Node a = Node(data);
};
void append(List L, int data);
void insertBefore(List L, int data);
void insertAfter(List L, int data);
void deleteFront(List L);
void deleteBack(List L);
void delete(List L);










