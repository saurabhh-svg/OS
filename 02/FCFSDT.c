#include <stdio.h>
void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[])
{
    int service_time[n];
    service_time[0] = at[0];
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        service_time[i] = service_time[i - 1] + bt[i - 1];
        wt[i] = service_time[i] - at[i];
        if (wt[i] < 0)
            wt[i] = 0;
    }
}
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}
void findavgTime(int processes[], int n, int bt[], int at[]){
    int wt[n], tat[n];
    findWaitingTime(processes, n, bt, wt, at);
    findTurnAroundTime(processes, n, bt, wt, tat);
    printf("Processes\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\tCompletion Time \n");
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)  {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        int compl_time = tat[i] + at[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\n", 
        i + 1, bt[i], at[i], wt[i], tat[i], compl_time);
    }
    printf("Average waiting time = %f", (float)total_wt / (float)n);
    printf("\nAverage turn around time = %f", (float)total_tat / (float)n);
}
int main(){
        int n;
    printf("Enter no of processes: ");
    scanf("%d", &n);
    int processes[n];
    for (int i = 0; i < n; i++)
        processes[i] = i;
    int burst_time[n];
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d : ", i);
        scanf("%d", &burst_time[i]);
    }
    int arrival_time[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time for process %d : ", i);
        scanf("%d", &arrival_time[i]);
    }
    findavgTime(processes, n, burst_time, arrival_time);
    return 0;
}




