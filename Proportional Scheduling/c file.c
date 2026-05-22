#include <stdio.h>

int main() {
    int n, i;
    int totalWeight = 0;
    int totalCPUTime;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int weight[n];
    float cpuShare[n];

    // Input total CPU time
    printf("Enter total CPU time available (ms): ");
    scanf("%d", &totalCPUTime);

    // Input weights
    for(i = 0; i < n; i++) {
        printf("Enter weight for Process P%d: ", i + 1);
        scanf("%d", &weight[i]);

        totalWeight += weight[i];
    }

    // Calculate proportional share
    printf("\n--- Proportional Scheduling ---\n");

    printf("\nProcess\tWeight\tCPU Time Share\n");

    for(i = 0; i < n; i++) {
        cpuShare[i] = ((float)weight[i] / totalWeight) * totalCPUTime;

        printf("P%d\t%d\t%.2f ms\n",
               i + 1,
               weight[i],
               cpuShare[i]);
    }

    return 0;
}
