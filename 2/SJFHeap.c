#include <stdio.h>
#include <string.h>
struct process
{
    int exe_time;
    int arr_time;
    int start;
    int finish;
    int wt;
    int ta_time;
    char pro_name[10];
    char t[10];
};
void swap(struct process *a, struct process *b)
{
    struct process c = *a;
    *a = *b;
    *b = c;
}

void heapify(struct process arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l].exe_time > arr[largest].exe_time)
        largest = l;
    if (r < n && arr[r].exe_time > arr[largest].exe_time)
        largest = r;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
// perform heap sort
void heapSort(struct process arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(&arr[0], &arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
int main()
{
    int n, i, j, temp;
    int tot_wt = 0, tot_ta = 0;
    float avg_wt, avg_ta;
    // char pro_name[10][10],t[10];
    printf("Enter the number of process:");
    scanf("%d", &n);
    struct process arr[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter process name, arrival time & burst time:");
        scanf("%s%d%d", arr[i].pro_name, &(arr[i].arr_time), &(arr[i].exe_time));
    }
    heapSort(arr, n);
    printf("%d", arr[0].exe_time);
    for (i = 0; i < n; i++)
    {
        if (i == 0)
            arr[i].start = arr[i].arr_time;

        else
            arr[i].start = arr[i - 1].finish;

        arr[i].wt = arr[i].start - arr[i].arr_time;
        arr[i].finish = arr[i].start + arr[i].exe_time;
        arr[i].ta_time = arr[i].finish - arr[i].arr_time;
        tot_wt += arr[i].wt;
        tot_ta += arr[i].ta_time;
    }
    avg_wt = (float)tot_wt / n;
    avg_ta = (float)tot_ta / n;
    printf("\nProcess\tArrival time\tBUrst time\tWaiting_time\tTAT");
    for (i = 0; i < n; i++)
    {
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d", arr[i].pro_name, arr[i].arr_time,
               arr[i].exe_time, arr[i].wt, arr[i].ta_time);
    }
    printf("\nAverage waiting time is:%f", avg_wt);
    printf("\nAverage turn around time is:%f\n", avg_ta);
    return 0;
}
