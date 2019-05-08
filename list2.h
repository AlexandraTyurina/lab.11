#ifndef LIST2_H_INCLUDED
#define LIST2_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#define MAXLEN 60

typedef struct LNode2 {
    int   id;
    laptops *comp;  /* data area */
    struct LNode  *prev;/* link to previous node */
    struct LNode  *next; /* link to next node */
}Node2;
/*------Functions for a linear doubly linked list------*/
Node2 *CreateNode2(FILE *df);
void AddFirst2(Head *MyHead, Node2 *NewNode);
void AddLast2(Head *MyHead, Node2 *NewNode, Node2 *PrevNode);
void InsertAfter2(Head *MyHead, Node2 *NewNode, Node2 *CurrentNode);
void InsertBefore2(Head *MyHead, Node2 *NewNode, Node2 *CurrentNode);
/* functions to get values for sorting */
float sRAM(Node2*q);
// ------------------------------------
float snucleus(Node2*q);
// ------------------------------------
float srate(Node2*q);
// ------------------------------------
float sweight(Node2*q);
// ------------------------------------
float spar0(Node2*q);
// ------------------------------------
float spar1(Node2*q);
// ------------------------------------
float spar2(Node2*q);
// ------------------------------------
#endif // LIST2_H_INCLUDED
