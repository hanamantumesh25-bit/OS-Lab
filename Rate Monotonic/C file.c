#include <stdio.h>

struct Task {
    int id, burst, period;
};

int main() {
    int n, i, j;
    struct Task t[10], temp;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Task %d Burst Time and Period: ", i + 1);
        scanf("%d %d", &t[i].burst, &t[i].period);
        t[i].id = i + 1;
    }

    // Sort by smallest period (highest priority)
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(t[i].period > t[j].period) {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }

    printf("\nExecution Order (Rate Monotonic):\n");

    for(i = 0; i < n; i++) {
        printf("Task %d -> ", t[i].id);
    }

    printf("END\n");

    return 0;
}
