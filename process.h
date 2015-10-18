#ifndef PROCESS_H
#define PROCESS_H


typedef struct process { 
	char processName[100];
	int processID;
	int processData[12];
	int burstIndex;
	int CPUtimer;
	int IOtimer;
	int CPUtotal;
	int IOtotal;
	int CPUcount;
	int IOcount;
} process;

#endif 
