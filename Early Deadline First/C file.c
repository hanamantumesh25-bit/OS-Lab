#include <stdio.h>

struct Task {
    int id, burst, deadline;
};

int main() {
    int n, i, j;
    struct Task t[10], temp;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Task %d Burst Time and Deadline: ", i + 1);
        scanf("%d %d", &t[i].burst, &t[i].deadline);
        t[i].id = i + 1;
    }

    // Sort by earliest deadline
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(t[i].deadline > t[j].deadline) {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }

    printf("\nExecution Order (EDF):\n");

    for(i = 0; i < n; i++) {
        printf("Task %d -> ", t[i].id);
    }

    printf("END\n");

    return 0;
}
