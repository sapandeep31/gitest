#include <stdio.h>

#define MAX_FRAMES 3

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames[MAX_FRAMES];
    int page_faults = 0;
    int page_hits = 0;

    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1; 
    }

    int front = 0; 

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int page_found = 0;

        
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                page_found = 1;
                page_hits++;
                break;
            }
        }

        
        if (!page_found) {
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
