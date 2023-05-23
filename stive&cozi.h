#ifndef __GUARD_STRUCTS__
#define __GUARD_STRUCTS__
#include <limits.h>
#include "echipe.h"
 typedef struct queue {
     Team *front , *rear;
 }Queue;
int top(Team *top);
void push(Team **top,Team *current);
int pop(Team**top);
int isEmpty(Team*top);
void deleteStack(Team**top);
Queue* createQueue();
void enQueue(Queue*q, Team *top);
int deQueue(Queue*q);
int isEmptyq(Queue*q);
void deleteQueue(Queue*q);
#endif