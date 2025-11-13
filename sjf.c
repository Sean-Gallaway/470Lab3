#include "util.h"

void shortestRemainingTime (Process p[], int size) {
    int time = 0;
    int ind = 0;
    int lastPid = 0;
    for (int a = 0; a < size; a++) {
        p[a].remaining = p[a].burst;
    }
    sortProcessByJobTime(p, size);
    while (p[0].remaining != 0) {
        ind = 0;
        if (time < p[ind].arrival) {
            while (time < p[ind].arrival) {
                fflush(stdout);
                ind++;
            }
        }

        if (lastPid != p[ind].pid) {
            printf("processing: %d @ %d\n", p[ind].pid, time);
        }
        lastPid = p[ind].pid;
        p[ind].remaining--;
        if (p[ind].remaining == 0) {
            p[ind].turnaround = p[ind].waiting + p[ind].burst;
        }
        for (int a = 0; a < size; a++) {
            if (a != ind && p[a].arrival <= time && p[a].remaining != 0) {
                p[a].waiting++;
            }
        }
        sortProcessByJobTime(p, size);
        time++;

    }
}


int main () {
    Process proc[] = {
        {1, 0, 8},
        {2, 1, 4},
        {3, 2, 9},
        {4, 3, 5}
    };
    int n = sizeof(proc) / sizeof(proc[0]);
    shortestRemainingTime(proc, n);
    printProcesses(proc, n);
    return 0;
}
