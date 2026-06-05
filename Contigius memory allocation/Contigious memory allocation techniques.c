#include <stdio.h>

struct Memory {
    int size;
};

void allocate(struct Memory b[], int m, int p[], int n, int type) {
    int a[n];

    for (int i = 0; i < n; i++) {
        a[i] = -1;
        int idx = -1;

        for (int j = 0; j < m; j++) {
            if (b[j].size >= p[i]) {
                if (type == 0) {           // First Fit
                    idx = j;
                    break;
                }
                if (idx == -1)
                    idx = j;
                else if ((type == 1 && b[j].size < b[idx].size) ||   // Best Fit
                         (type == 2 && b[j].size > b[idx].size))     // Worst Fit
                    idx = j;
            }
        }

        if (idx != -1) {
            a[i] = idx;
            b[idx].size -= p[i];
        }
    }

    printf("\nProcess\tSize\tBlock\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%s\n", i + 1, p[i],
               (a[i] == -1) ? "NA" : "");
}

int main() {
    int m, n;
    printf("Blocks: ");
    scanf("%d", &m);

    struct Memory b1[m], b2[m], b3[m];

    printf("Block sizes: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &b1[i].size);
        b2[i] = b3[i] = b1[i];
    }

    printf("Processes: ");
    scanf("%d", &n);

    int p[n];
    printf("Process sizes: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("\nFirst Fit");
    allocate(b1, m, p, n, 0);

    printf("\nBest Fit");
    allocate(b2, m, p, n, 1);

    printf("\nWorst Fit");
    allocate(b3, m, p, n, 2);

    return 0;
}
