#include "util.h"
#include <stdbool.h>

// round robin
void roundRobin (Process p[], const int size, int const quantum) {
    // declare variables
    int count = 0;
    int index = 0;
    int time = 0;
    int ind = 0;
    int thisQuantum;

    // sort by arrival before processing
    sortProcessByArrivalTime(p, size);

    // set temp buffer to keep track of execution time left later on.
    for (int a = 0; a < size; a++) {
        p[a].remaining = p[a].burst;
    }

    printf("Execution Order: ");
    while (true) {
        // process first
        printf("P%d ", p[ind].pid);
        thisQuantum = quantum;
        p[ind].remaining -= quantum;
        time += quantum;

        // if stored value is zero or less then we've completed the job
        // and can set the turnaround time to the current time elapsed.
        // minus its arrival time.
        if (p[ind].remaining <= 0) {
            time += p[ind].remaining; // times[ind] could be negative
            thisQuantum += p[ind].remaining;

            // set turnaround time
            p[ind].turnaround = p[ind].burst + p[ind].waiting;

        }

        // all others add wait time
        for (int a = 0; a < size; a++ ) {
            if (a != ind && p[a].remaining > 0) {
                p[a].waiting += thisQuantum;
            }
        }

        // choose next, if count goes above size, then we've looped around
        // if we've looped, that means that all jobs are done.
        count = 0;
        while (count <= size) {
            count++;
            index = ind + count;
            index = index >= size ? index-size : index;
            if (p[index].remaining > 0) {
                ind = index;
                break;
            }
        }
        if (count > size) {
            break;
        }
    }

    printf("\nRound Robin:\n");
    printProcesses(p, size);
}

//
int main () {
    Process processes[] =  {{1, 0, 24,  0, 0},
                            {2, 0, 3, 0, 0},
                            {3, 0, 3,  0, 0}};
    roundRobin(processes, sizeof(processes)/sizeof(Process), 4);
    return 0;
}
