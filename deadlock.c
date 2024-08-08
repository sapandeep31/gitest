#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

void calculateNeed(int need[MAX_PROCESSES][MAX_RESOURCES], int max[MAX_PROCESSES][MAX_RESOURCES], int allocation[MAX_PROCESSES][MAX_RESOURCES], int processes, int resources)
{
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

int isSafe(int processes, int resources, int available[], int max[][MAX_RESOURCES], int allocation[][MAX_RESOURCES])
{
    int need[MAX_PROCESSES][MAX_RESOURCES];
    calculateNeed(need, max, allocation, processes, resources);

    int finish[MAX_PROCESSES] = {0};
    int safeSequence[MAX_PROCESSES];
    int work[MAX_RESOURCES];

    for (int i = 0; i < resources; i++)
    {
        work[i] = available[i];
    }

    int count = 0;
    while (count < processes)
    {
        int found = 0;
        for (int p = 0; p < processes; p++)
        {
            if (finish[p] == 0)
            {
                int j;
                for (j = 0; j < resources; j++)
                {
                    if (need[p][j] > work[j])
                    {
                        break;
                    }
                }

                if (j == resources)
                {
                    for (int k = 0; k < resources; k++)
                    {
                        work[k] += allocation[p][k];
                    }
                    safeSequence[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0)
        {
            printf("System is not in a safe state\n");
            return 0;
        }
    }

    printf("System is in a safe state\nSafe sequence is: ");
    for (int i = 0; i < processes; i++)
    {
        printf("%d ", safeSequence[i]);
    }
    printf("\n");
    return 1;
}

int main()
{
    int processes, resources;
    int allocation[MAX_PROCESSES][MAX_RESOURCES], max[MAX_PROCESSES][MAX_RESOURCES], available[MAX_RESOURCES];

    printf("Enter the number of processes: ");
    scanf("%d", &processes);
    printf("Enter the number of resources: ");
    scanf("%d", &resources);

    printf("Enter the Allocation Matrix:\n");
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the Max Matrix:\n");
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the Available Resources:\n");
    for (int i = 0; i < resources; i++)
    {
        scanf("%d", &available[i]);
    }

    isSafe(processes, resources, available, max, allocation);

    return 0;
}