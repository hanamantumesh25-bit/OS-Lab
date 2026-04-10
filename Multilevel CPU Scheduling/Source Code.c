#include <stdio.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int waiting;
    int turnaround;
};

void fcfs(struct Process p[], int n) {
    int i;

    // First process waiting time = 0
    p[0].waiting = 0;

    // Calculate waiting time
    for(i = 1; i < n; i++) {
        p[i].waiting = p[i-1].waiting + p[i-1].burst;
    }

    // Calculate turnaround time
    for(i = 0; i < n; i++) {
        p[i].turnaround = p[i].waiting + p[i].burst;
    }

    // Display results
    printf("\nPID\tBurst\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", p[i].pid, p[i].burst, p[i].waiting, p[i].turnaround);
    }
}

int main() {
    int i, n_sys, n_user;

    printf("Enter number of system processes: ");
    scanf("%d", &n_sys);

    struct Process sys[n_sys];

    for(i = 0; i < n_sys; i++) {
        printf("Enter burst time for System Process %d: ", i+1);
        sys[i].pid = i + 1;
        scanf("%d", &sys[i].burst);
    }

    printf("\nEnter number of user processes: ");
    scanf("%d", &n_user);

    struct Process user[n_user];

    for(i = 0; i < n_user; i++) {
        printf("Enter burst time for User Process %d: ", i+1);
        user[i].pid = i + 1;
        scanf("%d", &user[i].burst);
    }

    printf("\n--- Executing System Processes (Higher Priority) ---\n");
    fcfs(sys, n_sys);

    printf("\n--- Executing User Processes (Lower Priority) ---\n");
    fcfs(user, n_user);

    return 0;
}
