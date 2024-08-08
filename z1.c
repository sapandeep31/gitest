#include <stdio.h>

int main() {
    int at[10], wt[10], bt[10], ct[10], tat[10], n, i;
    float total_tat = 0, total_wt = 0;

    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter arrival time of process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Calculate completion time for each process
    if (at[0] > 0) {
        ct[0] = at[0] + bt[0];
    } else {
        ct[0] = bt[0];
    }

    for (i = 1; i < n; i++) {
        if (ct[i-1] < at[i]) {
            ct[i] = at[i] + bt[i]; // CPU waits for the next process to arrive
        } else {
            ct[i] = ct[i-1] + bt[i]; // CPU executes the next process immediately
        }
    }

    // Calculate turnaround time and waiting time for each process
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("Proc\tArr\tBurst\tComp\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("Average Turnaround Time: %.2f\n", total_tat / n);
    printf("Average Waiting Time: %.2f\n", total_wt / n);

    return 0;
}
