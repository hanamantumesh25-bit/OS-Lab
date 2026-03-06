#include <stdio.h>

void sort(int arrival[], int burst[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arrival[j] > arrival[j+1]){

                int temp = arrival[j];
                arrival[j] = arrival[j+1];
                arrival[j+1] = temp;

                temp = burst[j];
                burst[j] = burst[j+1];
                burst[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;

    printf("Enter number of processes :");
    scanf("%d", &n);

    int arrival[n], burst[n], waiting[n], turnaround[n], compliation[n];

    printf("Enter arrival time: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &arrival[i]);
    }

    printf("Enter burst time: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &burst[i]);
    }

    sort(arrival, burst, n);

    int currTime = 0;

    for (int i = 0; i < n; i++){
        if (currTime < arrival[i]){
            currTime = arrival[i];
        }

        compliation[i] = currTime + burst[i];
        turnaround[i] = compliation[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];

        currTime = compliation[i];

    }

    float sumofWT = 0;
    for (int i = 0; i < n; i++){
        sumofWT = sumofWT + waiting[i];
    }
    

    float sumofTAT = 0;
    for (int i = 0; i < n; i++){
        sumofTAT = sumofTAT + turnaround[i];
    }
    
    printf("Processes\tAT\tBT\tCT\tTT\tWT\n");

    for(int i = 0; i < n; i++){
        printf("P%d\t\t\t%d\t%d\t%d\t%d\t%d\n",
            i+1,
            arrival[i],
            burst[i],
            compliation[i],
            turnaround[i],
            waiting[i]);
    }

    printf("\nAverage waiting time: %.2f", sumofWT/n);
    printf("\nAverage turn around time: %.2f", sumofTAT/n);

    return 0;
}