#include <stdio.h>

int main()
{
    int n, MAX_FRAMES;
    printf("\nEnter the number of pages");
    scanf("%d", &n);
    int pages[n];
    printf("\nEnter the sequence of pages");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }
    printf("\nEnter the number of frames");
    scanf("%d", &MAX_FRAMES);
    int frames[MAX_FRAMES];


    
    int page_faults = 0; // Counter for page faults
    int page_hits = 0;   // Counter for page hits

    for (int i = 0; i < MAX_FRAMES; i++)
    {
        frames[i] = -1; // Initialize frames as empty
    }

    int front = 0; // Front of the FIFO queue

    for (int i = 0; i < n; i++)
    {
        int page = pages[i];
        int page_found = 0;

        // Check if the page is already in a frame
        for (int j = 0; j < MAX_FRAMES; j++)
        {
            if (frames[j] == page)
            {
                page_found = 1;
                page_hits++; // Increment page hits if found
                break;
            }
        }

        // If not found, replace the oldest page (FIFO)
        if (!page_found)
        {
            frames[front] = page;
            front = (front + 1) % MAX_FRAMES;
            page_faults++;
        }
    }

    double fault_ratio = (double)page_faults / n;
    double hit_ratio = (double)page_hits / n;

    printf("Total page faults: %d\n", page_faults);
    printf("Total page hits: %d\n", page_hits);
    printf("Fault ratio: %.2f\n", fault_ratio);
    printf("Hit ratio: %.2f\n", hit_ratio);

    return 0;
}