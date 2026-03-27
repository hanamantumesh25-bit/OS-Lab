#include <stdio.h>

struct process
{
    int pid;
    int at;
    int bt;
    int rt;
    int wt;
    int tat;
    int ct;
};

void roundRobin(struct process p[], int n, int tq)
{
    int time = 0, done;

    while(1)
    {
        done = 1;

        for(int i = 0; i < n; i++)
        {
            if(p[i].rt > 0 && p[i].at <= time)
            {
                done = 0;

                if(p[i].rt <= tq)
                {
                    time += p[i].rt;
                    p[i].rt = 0;

                    p[i].ct = time;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;
                }
                else
                {
                    time += tq;
                    p[i].rt -= tq;
                }
            }
        }

        if(done == 1)
        {
            time++;
        }

        int finished = 1;
        for(int i = 0; i < n; i++)
        {
            if(p[i].rt > 0)
            {
                finished = 0;
                break;
            }
        }

        if(finished)
            break;
    }
}

void display(struct process p[], int n)
{
    float avg_wt = 0, avg_tat = 0;

    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");

    for(int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].wt, p[i].tat);

        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);
}

int main()
{
    struct process p[20];
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;

        printf("Enter Arrival Time for P%d: ", p[i].pid);
        scanf("%d", &p[i].at);

        printf("Enter Burst Time for P%d: ", p[i].pid);
        scanf("%d", &p[i].bt);

        p[i].rt = p[i].bt;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    roundRobin(p, n, tq);

    display(p, n);

    return 0;
}
