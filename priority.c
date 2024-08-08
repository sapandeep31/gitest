#include <stdio.h>

int main()
{
    int n, at[10], bt[10], wt[10], tat[10], ct[10], pr[10], sum, i, j, temp;
    float totaltat = 0, totalwt = 0;

    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    printf("\nEnter The Process Burst Time\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter Burst time of process[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }

    printf("\nEnter The Priority of each process \n");
    for (i = 0; i < n; i++)
    {
        printf("Enter priority of process[%d]: ", i + 1);
        scanf("%d", &pr[i]);
    }

    /* Apply Bubble Sort to sort according to priority */
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (pr[j] > pr[j + 1])
            {
                // Swap priority
                temp = pr[j];
                pr[j] = pr[j + 1];
                pr[j + 1] = temp;

                // Swap burst time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }

    /* Calculate completion time of processes */
    sum = 0;
    for (j = 0; j < n; j++)
    {
        sum += bt[j];
        ct[j] = sum;
    }

    /* Calculate Turn Around Time */
    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i];
        totaltat += tat[i];
    }

    /* Calculate Waiting Time */
    for (i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
        totalwt += wt[i];
    }

    printf("\nProcess\tBT\tPriority\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t\t%d\t%d\n", i + 1, bt[i], pr[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f\n", totaltat / n);
    printf("Average Waiting Time: %.2f\n", totalwt / n);

    return 0;
}