#include <stdio.h>

int main() {
    int n = 5, m = 3; // Number of processes and resources
    int i, j, k;
    int alloc[5][3] = { {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2} };
    int max[5][3] = { {7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3} };
    int avail[3] = { 3, 3, 2 }; // Available resources
    int f[5], ans[5], ind = 0;

    for (k = 0; k < n; k++) {
        f[k] = 0;
    }

    int need[5][3];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) { // This should be 'm' instead of 'n'
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int y = 0;
    for (k = 0; k < n; k++) { // Loop should iterate 'n' times instead of 5 times
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++) {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;
    for (i = 0; i < n; i++) {
        if (f[i] == 0) {
            flag = 0;
            printf("The system is not in a safe state.\n");
            break;
        }
    }

    if (flag == 1) {
        printf("The system is in a safe state.\nSafe sequence is: ");
        for (i = 0; i < n - 1; i++) {
            printf("P%d -> ", ans[i]);
        }
        printf("P%d\n", ans[n - 1]);
    }

    return 0;
}
