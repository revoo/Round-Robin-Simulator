#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process.h"

/* FIFO data structure. Pushes at head and pops off at tail. */

void push(queue* q, process new_pr) {
	// new process will be the head node, pr stores address new_pr is pointing to.
	// first time node init
	if (q->head_node == NULL) {
		q->head_node       = malloc(sizeof q->head_node); 
		//memcpy(&new_pr, &q->head_node->pr, sizeof new_pr);
		q->head_node->pr = new_pr;
		//memcpy(&q->head_node->pr, &new_pr, sizeof q->head_node->pr);
		q->head_node->next = NULL;
	//printf("First node: storing process: %s with PID %d\n", q->head_node->pr.processName, q->head_node->pr.processID);
		return;
	}
	// remember old node, allocate a new node, insert it at the head_node
	// Perform deep copy
	//malloc fails here
	node* temp_node = malloc(sizeof *temp_node);
	//node* temp_node    = q->head_node;
	//memcpy(temp_node, q->head_node, sizeof *temp_node);
	temp_node          = q->head_node;
	node* new_node     = malloc(sizeof *new_node);
	q->head_node       = new_node;
	q->head_node->pr   = new_pr;
//	memcpy(&q->head_node->pr, &new_pr, sizeof new_pr);
	q->head_node->next = temp_node;
//	printf("storing process: %s with PID %d\n", q->head_node->pr.processName, q->head_node->pr.processID);
}

void pop(queue* q) {
	node* iterator = q->head_node;
	// queue empty case
	if (iterator == NULL) return;
	// single element in queue case
	if (iterator->next == NULL) {
		q->head_node = NULL;
		return;
	}
	// multiple elements in queue case
	while (iterator->next->next != NULL) iterator = iterator->next;
	//free(iterator->next);
	iterator->next = NULL;	
}

node* head(queue* q) {
	if (q->head_node != NULL) return q->head_node;
	printf("Error: head(queue*): queue empty\n");
	return NULL;
}

node* tail(queue* q) {
	// queue empty case
	if (q->head_node == NULL) {
		printf("Tail: failed to retrieve head_node. Head_node is null.\n");
		return NULL; 
	}	
	node* iterator = q->head_node;
	while (iterator->next != NULL) iterator = iterator->next;
	return iterator;
}

int empty(queue* q) {
//	printf(q->head_node->pr->processName);
	return (q->head_node == NULL);
}

int size(queue* q) {
//	if (q->head_node == NULL) return 0;
	int size = 0;
	node* iterator = q->head_node;
	while (iterator != NULL) {
		iterator = iterator->next;
		size++;
	}
	return size;
}

void print(queue* q) {
	if (q->head_node == NULL) {
		printf("Nothing to print, queue empty.\n");
		return;
	}
	printf("Printing from start of queue... (Last in line)\n\n");
	node* iterator = q->head_node;
	while (iterator != NULL) {
		printf("Process name of this node: %s\n", iterator->pr.processName);
		printf("process PID: %d\n", iterator->pr.processID);
		iterator = iterator->next;
		printf("The next process: %s\n\n", iterator->pr.processName);
	}
	printf("\n\n");
}
