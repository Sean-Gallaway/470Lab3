#include "util.h"

// comparator to be used with quicksort
int arriveComp (const void* a, const void* b) {
    // sort by arrival value
    const int val = ((Process*)a)->arrival - ((Process*)b)->arrival;

    // if arrival value is zero, sort by pid
    return val == 0 ? ((Process*)a)->pid - ((Process*)b)->pid : val;
}
// comparator to be used with quicksort
int shortComp (const void* a, const void* b) {
    if (((Process*)a)->remaining == 0) {
        return 1;
    }
    if (((Process*)b)->remaining == 0) {
        return -1;
    }

    // sort by arrival value
    const int val = ((Process*)a)->remaining - ((Process*)b)->remaining;

    // if arrival value is zero, sort by pid
    return val == 0 ? ((Process*)a)->pid - ((Process*)b)->pid : val;
}
// comparator to be used with quicksort
int procComp (const void* a, const void* b) {
    return ((Process*)a)->pid - ((Process*)b)->pid;
}


// Wrapper function for quick sort
void sortProcessByArrivalTime (Process p[], int size) {
    qsort(p, size, sizeof(Process), arriveComp);
}
// Wrapper function for quick sort
void sortProcessByJobTime (Process p[], int size) {
    qsort(p, size, sizeof(Process), shortComp);
}
// Wrapper function for quick sort
void sortProcessByID (Process p[], int size) {
    qsort(p, size, sizeof(Process), procComp);
}

// print out the processes
void printProcesses (Process p[], int size) {
    sortProcessByID(p, size);
    printf("PID\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int a = 0; a < size; a++) {
        printf("%d\t%d\t%d\t%d\t%d\n",
            p[a].pid, p[a].arrival, p[a].burst,
            p[a].waiting, p[a].turnaround);
    }
}