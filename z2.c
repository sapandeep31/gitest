#include <stdio.h>

int main() {
    int at[10], wt[10], bt[10], ct[10], tat[10], n, i, j, temp;
    float total_tat = 0, total_wt = 0;
    int completed[10] = {0}; // To keep track of completed processes

    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter arrival time of process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    int curr_time = 0, completed_processes = 0;
    
    while (completed_processes < n) {
        int shortest_job = -1;
        int min_bt = 9999;

       
        for (i = 0; i < n; i++) {
            if (at[i] <= curr_time && !completed[i] && bt[i] < min_bt) {
                min_bt = bt[i];
                shortest_job = i;
            }
        }

        if (shortest_job == -1) {
            curr_time++;
            continue;
        }

        
        curr_time += bt[shortest_job];
        ct[shortest_job] = curr_time;
        tat[shortest_job] = ct[shortest_job] - at[shortest_job];
        wt[shortest_job] = tat[shortest_job] - bt[shortest_job];
        total_tat += tat[shortest_job];
        total_wt += wt[shortest_job];
        completed[shortest_job] = 1;
        completed_processes++;
    }

    printf("Proc\tArr\tBurst\tComp\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("Average Turnaround Time: %.2f\n", total_tat / n);
    printf("Average Waiting Time: %.2f\n", total_wt / n);

    return 0;
}
