#ifndef QUEUE_H
#define QUEUE_H

#include "process.h"

typedef struct node {
	process pr;
	struct node *next;
} node;

typedef struct queue {
	node *head_node;

} queue;


// Function prototypes
void push(queue*, process);
void pop(queue*);
node* head(queue*);
node* tail(queue*);
int empty(queue*);
int size(queue*);
void print(queue*);

#endif
