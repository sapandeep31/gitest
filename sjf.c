#include <stdio.h>

int main()
{
    int n, bt[10], wt[10], tat[10], ct[10], p[10], sum = 0, i, j, temp;
    float totaltat = 0, totalwt = 0;

    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the process numbers:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("\nEnter the Process Burst Time\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter Burst time of process[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Apply Bubble sort to sort according to burst time and process number
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                // Swap burst time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap process number
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Calculate completion time of processes
    sum = 0;
    for (j = 0; j < n; j++)
    {
        sum = sum + bt[j];
        ct[j] = sum;
    }

    // Calculate Turnaround time
    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i];
        totaltat = totaltat + tat[i];
    }

    // Calculate Waiting time
    for (i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
        totalwt = totalwt + wt[i];
    }

    printf("\nProcess\tBT\tCT\tTAT\tWT\n\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f\n", totaltat / n);
    printf("Average Waiting Time: %.2f\n", totalwt / n);

    return 0;
}