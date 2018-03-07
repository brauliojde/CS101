//
//  pa2.h
//  pa2
//
//  Created by Braulio De La Torre on 1/21/17.
//
//

#ifndef __pa2__pa2__
#define __pa2__pa2__

#include <stdio.h>

// Access functions -----------------------------------------------------------

int length(List L);
int index(List L);
int front(List L);
int back(List L);
int get(List L);
int equals(List A, List B);

// Manipulation procedures ----------------------------------------------------
void clear(List L);
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

#endif /* defined(__pa2__pa2__) */
