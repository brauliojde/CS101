//  Braulio De La Torre
//  CS101
//  id:1496697
//  List.h
//  pa4
//
//  Created by Braulio De La Torre on 2/21/17.
//  Copyright (c) 2017 Braulio. All rights reserved.
//

#ifndef __pa4__List__
#define __pa4__List__

#include <stdio.h>
#include <string.h>

typedef struct ListObj* List;

// Access functions -----------------------------------------------------------
List newList(void);
void freeList(List* pS);
int length(List L);
int getColor(List L);
void chColor(List L, int x);
int getDistance(List L);
void chDistance(List L, int x);
int getlistParent(List L);
void chlistParent(List L, int x);
int getRecent(List L);
void chRecent(List L, int x);
int index1(List L);
int front(List L);
int back(List L);
int get(List L);
int equals(List A, List B);

// Manipulation procedures ----------------------------------------------------
void clear1(List L);
void moveFront(List L);
void moveBack(List L);
void movePrev(List L);
void moveNext(List L);
void prepend(List L, int data);
void append(List L, int data);
void insertBefore(List L, int data);
void insertAfter(List L, int data);
void deleteFront(List L);
void deleteBack(List L);
void delete(List L);
List copyList(List L);

void printList(FILE* out, List L);

#endif /* defined(__pa2__pa2__) */

