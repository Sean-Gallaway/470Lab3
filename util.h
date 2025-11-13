#ifndef UTIL
#define UTIL

#include <stdlib.h>
#include <stdio.h>

// Define process structure
typedef struct {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int waiting;
    int turnaround;
} Process;

int arriveComp (const void* a, const void* b);
void sortProcessByArrivalTime (Process p[], int size);

int shortComp (const void* a, const void* b);
void sortProcessByJobTime (Process p[], int size);

int procComp (const void* a, const void* b);
void sortProcessByID (Process p[], int size);

void printProcesses (Process p[], int size);
#endif