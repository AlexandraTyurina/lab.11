#include "list2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 60
/*------Functions for a linear doubly linked list------*/
// -------------------------------------------------------
Node2 *CreateNode2(FILE *df)
{
    Node2 *NewNode=NULL;
    int slen;
    char **s2=NULL;
    char *s1;
    char sep=';';
    NewNode = (Node2*)malloc(sizeof(Node2));
    s1 = (char*)malloc(MAXLEN*sizeof(char));
    if(NewNode&&s1)
    {
        NewNode->id = 1;
        fgets(s1,MAXLEN,df);
        slen=strlen(s1);
        s1[slen-1]='\0';
        slen=strlen(s1);
        s2=simple_split(s1,slen,sep);//память выделяется в функции
        if(s2!=NULL)
        {
            NewNode->comp=struct_fill(s2);
        }
        else puts("Error at data reading!");
        NewNode->comp=struct_fill(s2);
        NewNode->prev = NULL;
        NewNode->next = NULL;
    }
    free(s1);
    s1=NULL;
    return NewNode;
}
// -------------------------------------------------------
void AddFirst2(Head *MyHead, Node2 *NewNode)
{
    MyHead->first = NewNode;
    MyHead->last = NewNode;
    MyHead->cnt++;
}
// -------------------------------------------------------
void AddLast2(Head *MyHead, Node2 *NewNode, Node2 *PrevNode)
{
    int n;

    if(MyHead&&NewNode&&PrevNode)
    {
        n=MyHead->cnt+1;
        PrevNode->next=NewNode;
        NewNode->prev=PrevNode;
        MyHead->last=NewNode;
        NewNode->id=n;
        MyHead->cnt=n;
    }
}
// -------------------------------------------------------
void InsertAfter2(Head *MyHead, Node2 *NewNode, Node2 *CurrentNode)
{
    int n;
    if(MyHead&&NewNode&&CurrentNode)
    {
        n=MyHead->cnt+1;
        if(CurrentNode->next==NULL)
        {
            CurrentNode->next=NewNode;
            NewNode->prev=CurrentNode;
            MyHead->last=NewNode;
        }
        else
        {
            NewNode->next = CurrentNode->next;
            CurrentNode->next=NewNode;
            NewNode->prev=CurrentNode;
        }
        NewNode->id=n;
        MyHead->cnt=n;
    }
}
// -------------------------------------------------------
void InsertBefore2(Head *MyHead, Node2 *NewNode, Node2 *CurrentNode)
{
    Node2 *q=NULL;
    int n;

    if(MyHead&&NewNode&&CurrentNode)
    {
        if(MyHead->first==CurrentNode)
        {
            NewNode->next=CurrentNode;
            CurrentNode->prev=NewNode;
            MyHead->first=NewNode;

        }
        else
        {
            q=CurrentNode->prev;
            NewNode->next=CurrentNode;
            NewNode->prev=q;
            q->next=NewNode;
            CurrentNode->prev=NewNode;
        }
        n=MyHead->cnt+1;
        NewNode->id=n;
        MyHead->cnt=n;
    }
}
// -------------------------------------------------------
/*functions to get fields of sorting*/
float sRAM(Node2*q)
{
    return q->comp->RAM;
}
// ------------------------------------
float snucleus(Node2*q)
{
    return q->comp->nucleus;
}
// ------------------------------------
float srate(Node2*q)
{
    return q->comp->rate;
}
// ------------------------------------
float sweight(Node2*q)
{
    return q->comp->weight;
}
// ------------------------------------
float spar0(Node2*q)
{
    return q->comp->par[0];
}
// ------------------------------------
float spar1(Node2*q)
{
    return q->comp->par[1];
}
// ------------------------------------
float spar2(Node2*q)
{
    return q->comp->par[2];
}
/* -----------------------------------------------------*/

/*----------------The end of this part-----------------*/
