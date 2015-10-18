#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process.h"
#include "queue.h" 

int processInput(const char*, int, queue*);
void loadReadyQueue(queue*, queue*, int);

int main() {
        const char INPUT_FILE[] = "/home/turing/t90hch1/csci480/Assign4/data4.txt";
	const int MAX_TIME      = 500;
	const int TIME_SLICE    = 5;
	const int IN_USE        = 5;
	const int QUEUE_SIZE    = 20;
	const int HOW_OFTEN     = 6;
	const int ARRAY_SIZE    = 12;
	queue entry_queue = { .head_node = NULL };
	queue ready_queue = { .head_node = NULL };
	processInput(INPUT_FILE, ARRAY_SIZE, &entry_queue);
	loadReadyQueue(&ready_queue, &entry_queue, IN_USE);
	loadReadyQueue(&ready_queue, &entry_queue, IN_USE);

	//node* tailn = tail(&entry_queue);
	//node* headn = head(&entry_queue);
	//printf("tail node : %d\n", tailn->pr.processID);	
	//printf("head node : %d\n\n\n", headn->pr.processID);	
	//print(&ready_queue);
	//printf("size of entry_queue: %d\n", size(&ready_queue));
	/*print(&entry_queue);
	pop(&entry_queue);
	pop(&entry_queue);
	pop(&entry_queue);
	pop(&entry_queue);
	pop(&entry_queue);
	pop(&entry_queue);
	pop(&entry_queue);
	pop(&entry_queue);
	pop(&entry_queue);
	pop(&entry_queue);
	pop(&entry_queue);
	pop(&entry_queue);
	pop(&entry_queue);
	pop(&entry_queue);
	pop(&entry_queue);
	printf("size of entry_queue: %d\n", size(&entry_queue));
	if (empty(&entry_queue)) printf("queue is empty\n");*/

	//Debug
 	/*process pr;	
	process pr2;
	process pr3;
	process pr4;
	process pr5;
	process pr6;
	process pr7;
	process pr8;
	queue q = { .head_node = NULL };
	strcpy(pr.processName, "first  process");
	strcpy(pr2.processName, "second process");
	strcpy(pr3.processName, "third process");
	strcpy(pr4.processName, "fourthprocess");
	strcpy(pr5.processName, "fifth process");
	strcpy(pr6.processName, "sixth process");
	strcpy(pr7.processName, "seven process");
	strcpy(pr8.processName, "eigth process");
	push(&q, pr);
	push(&q, pr2);
	push(&q, pr3);
	push(&q, pr4);
	push(&q, pr5);
	push(&q, pr6);
	push(&q, pr7);
	push(&q, pr8);
	int qsize = size(&q);
	printf("size of queue: %d\n", qsize);
	char pname[100] = "   ";
	node* headnode = head(&q);
        node* tailnode = tail(&q);
 	if (headnode == NULL) printf("head_node null\n");
 	if (tailnode == NULL) printf("tail_node null\n");
	strcpy(pname, headnode->pr.processName);
	printf("here is headnode prName: %s \n", headnode->pr.processName); 
	printf("here is tailnode: %s\n", tailnode->pr.processName);
	printf("\n\n");
	print(&q);
	if (empty(&q)) printf("queue empty. this should not display!\n"); */

	return 0;
}

// PROCESS INPUT
int processInput(const char filePath[], int ARRAY_SIZE, queue* entryQueue) {
	static int freePID  = 0;
	char processData[8] = "";
	FILE  *inFile;
	inFile = fopen(filePath, "r");
	// Null-check 
	if (!inFile) 
		return -1;
 	// Process input file for process data	
	while (1) {
		process pr;
		for(int i = 0; i < ARRAY_SIZE + 1; i++) { 
			fscanf(inFile, "%s", processData);
			if (i == 0) { 
				if (!strcmp(processData, "STOPHERE")) return 0;			
				strcpy(pr.processName, processData); 
				//printf("process name: %s\n", processData);
				continue;
			}
			pr.processData[i] = atoi(processData);
			//printf("found data: %d\n", pr.processData[i]);
		}
		// Data read in now, assign process ID from available ID pool
		pr.processID = freePID;
		freePID++;
		// Push onto entry queue
		push(entryQueue, pr);
	}

	return 0;
}

// Pop proccesses off entry queue and load onto ready queue
void loadReadyQueue(queue* readyQueue, queue* entryQueue, int max) {
	node* temp_node = malloc(sizeof *temp_node);
//	for (int i = 0; i < max; i++) {
		temp_node = tail(entryQueue);
		//memcpy(temp_node, tail(entryQueue), sizeof *temp_node);		
		printf("loading %s with PID %d onto ready queue\n", temp_node->pr.processName, temp_node->pr.processID);
		push(readyQueue, temp_node->pr);
		pop(entryQueue);
	//}
/*	//node* temp_node = tail(entryQueue);
	temp_node = tail(entryQueue);
	printf("loading %s with PID %d onto ready queue\n", temp_node->pr.processName, temp_node->pr.processID);
	if (temp_node == NULL) printf("TEMP_NODE NULL\n");
	process pn = temp_node->pr;
	process pc;
	push(readyQueue, temp_node->pr);
	pop(entryQueue);*/
}
