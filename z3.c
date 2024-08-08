#include <stdio.h>
#include <limits.h>

int main() {
    int at[10], wt[10], bt[10], ct[10], tat[10], pri[10], n, i;
    float total_tat = 0, total_wt = 0;
    int completed[10] = {0}; // To keep track of completed processes

    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter arrival time of process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter priority of process %d: ", i + 1);
        scanf("%d", &pri[i]);
    }

    int curr_time = 0, completed_processes = 0;
    
    while (completed_processes < n) {
        int highest_pri_idx = -1;
        int highest_pri = INT_MAX;

        // Find the process with the highest priority (lowest priority number) that has arrived and is not completed
        for (i = 0; i < n; i++) {
            if (at[i] <= curr_time && !completed[i] && pri[i] < highest_pri) {
                highest_pri = pri[i];
                highest_pri_idx = i;
            }
        }

        if (highest_pri_idx == -1) {
            curr_time++;
            continue;
        }

        // Process the highest priority job
        curr_time += bt[highest_pri_idx];
        ct[highest_pri_idx] = curr_time;
        tat[highest_pri_idx] = ct[highest_pri_idx] - at[highest_pri_idx];
        wt[highest_pri_idx] = tat[highest_pri_idx] - bt[highest_pri_idx];
        total_tat += tat[highest_pri_idx];
        total_wt += wt[highest_pri_idx];
        completed[highest_pri_idx] = 1;
        completed_processes++;
    }

    printf("Proc\tArr\tBurst\tPri\tComp\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], pri[i], ct[i], tat[i], wt[i]);
    }

    printf("Average Turnaround Time: %.2f\n", total_tat / n);
    printf("Average Waiting Time: %.2f\n", total_wt / n);

    return 0;
}
