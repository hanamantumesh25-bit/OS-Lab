#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int pr;
    int rt;
    int ct;
    int tat;
    int wt;
};

void non_preemptive(struct Process p[], int n)
{
    int time = 0, completed = 0;

    while(completed < n)
    {
        int idx = -1;
        int highest = 9999;

        for(int i = 0; i < n; i++)
        {
            if(p[i].at <= time && p[i].rt > 0)
            {
                if(p[i].pr < highest)
                {
                    highest = p[i].pr;
                    idx = i;
                }
            }
        }

        if(idx != -1)
        {
            time += p[idx].rt;
            p[idx].rt = 0;

            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;

            completed++;
        }
        else
        {
            time++;
        }
    }

    printf("\nNon-Preemptive Priority Scheduling\n");
    printf("PID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid,p[i].at,p[i].bt,p[i].pr,
        p[i].ct,p[i].tat,p[i].wt);
    }

    float avgTAT = 0;
    for (int i = 0; i < n; i++){
        avgTAT += p[i].tat;
    }

    float avgWT = 0;
    for (int i =0; i < n; i++){
        avgWT += p[i].wt;
    }

    printf("\nAverage Turn around time: %.2f", avgTAT / n);
    printf("\nAverage Wating time: %.2f", avgWT / n);
}

void preemptive(struct Process p[], int n)
{
    int time = 0, completed = 0;

    while(completed < n)
    {
        int idx = -1;
        int highest = 9999;

        for(int i = 0; i < n; i++)
        {
            if(p[i].at <= time && p[i].rt > 0)
            {
                if(p[i].pr < highest)
                {
                    highest = p[i].pr;
                    idx = i;
                }
            }
        }

        if(idx != -1)
        {
            p[idx].rt--;
            time++;

            if(p[idx].rt == 0)
            {
                completed++;

                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
            }
        }
        else
        {
            time++;
        }
    }

    printf("\nPreemptive Priority Scheduling\n");
    printf("PID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid,p[i].at,p[i].bt,p[i].pr,
        p[i].ct,p[i].tat,p[i].wt);
    }

    float avgTAT = 0;
    for (int i = 0; i < n; i++){
        avgTAT += p[i].tat;
    }

    float avgWT = 0;
    for (int i =0; i < n; i++){
        avgWT += p[i].wt;
    }

    printf("\nAverage Turn around time: %.2f", avgTAT / n);
    printf("\nAverage Wating time: %.2f", avgWT / n);
}

int main()
{
    int n, choice;
    struct Process p[10], temp[10];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(int i = 0; i < n; i++)
    {
        p[i].pid = i+1;

        printf("\nArrival Time of P%d: ",i+1);
        scanf("%d",&p[i].at);

        printf("Burst Time of P%d: ", i+1);
        scanf("%d",&p[i].bt);

        printf("Priority of P%d: ", i+1);
        scanf("%d",&p[i].pr);

        p[i].rt = p[i].bt;
    }

    printf("\n1. Non-Preemptive Priority\n");
    printf("2. Preemptive Priority\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    for(int i=0;i<n;i++)
        temp[i] = p[i];

    if(choice == 1)
        non_preemptive(temp,n);
    else if(choice == 2)
        preemptive(temp,n);
    else
        printf("Invalid Choice");

    return 0;
}
