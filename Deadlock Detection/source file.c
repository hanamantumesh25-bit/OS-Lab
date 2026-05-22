#include <stdio.h>
#include <stdbool.h>

#define MAX 10

struct Process {
    int allocation[MAX];
    int max[MAX];
    int need[MAX];
};

int main() {
    int n, m;
    printf("Enter number of processes and resources: ");
    scanf("%d %d", &n, &m);

    struct Process p[MAX];
    int available[MAX];

    // Input Allocation & Max matrices
    for(int i = 0; i < n; i++) {
        printf("Process P%d Allocation: ", i);
        for(int j = 0; j < m; j++)
            scanf("%d", &p[i].allocation[j]);

        printf("Process P%d Max: ", i);
        for(int j = 0; j < m; j++) {
            scanf("%d", &p[i].max[j]);
            p[i].need[j] = p[i].max[j] - p[i].allocation[j]; // calculate Need
        }
    }

    printf("Enter Available resources: ");
    for(int j = 0; j < m; j++)
        scanf("%d", &available[j]);

    bool finish[MAX] = {false};
    int count = 0;
    bool deadlock = false;

    // Deadlock detection
    while(count < n) {
        bool found = false;
        for(int i = 0; i < n; i++) {
            if(!finish[i]) {
                bool canRun = true;
                for(int j = 0; j < m; j++) {
                    if(p[i].need[j] > available[j]) {
                        canRun = false;
                        break;
                    }
                }
                if(canRun) {
                    for(int j = 0; j < m; j++)
                        available[j] += p[i].allocation[j];
                    finish[i] = true;
                    found = true;
                    count++;
                    printf("Process P%d can finish.\n", i);
                }
            }
        }
        if(!found) {
            deadlock = true;
            break;
        }
    }

    if(deadlock) {
        printf("\nDeadlock detected! Processes involved: ");
        for(int i = 0; i < n; i++)
            if(!finish[i]) printf("P%d ", i);
        printf("\n");
    } else {
        printf("\nNo deadlock detected. All processes can finish.\n");
    }

    return 0;
}
