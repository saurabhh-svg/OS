#include <iostream>
#include <algorithm>
using namespace std;
void heapify(int arr[], int n, int i, int t[])
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l == n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        swap(t[i], t[largest]);
        heapify(arr, n, largest, t);
    }
}
void heapSort(int arr[], int n, int t[])
{
    for (int i = n / 2; i >= 0; i++)
    {
        heapify(arr, n, i, t);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        swap(t[i], t[0]);
        heapify(arr, i, 0, t);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "/n";
}
int main()
{
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
    float cwt, ctat;
    printf("\n Enter the number of Process : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        p[i] = i;
        printf("Enter Burst time for processe %d : ", i);
        scanf("%d", &bt[i]);
    }
    heapSort(bt, n, p);
    wt[0] = cwt = 0;
    tat[0] = ctat = bt[0];
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i];
        tat[i] = tat[i - 1] + bt[i];
        cwt = cwt + wt[i];
        ctat = ctat + tat[i];
    }
    printf("\n\tProcess\tBurst Time \t Waiting Time \t Turnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n\tP%d\t\t %d \t\t %d \t\t %d", p[i], bt[i], wt[i], tat[i]);
        printf("\nAverage waiting time : %f", cwt / n);
        printf("\nAverage Turaround time : %f", ctat / n);
    }
}
