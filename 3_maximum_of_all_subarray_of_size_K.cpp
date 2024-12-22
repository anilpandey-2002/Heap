#include <iostream>
#include <queue>
using namespace std;

void printKMax(int arr[], int n, int k)
{
    priority_queue<pair<int, int>> maxHeap;

    for (int i = 0; i < k; i++)
        maxHeap.push({arr[i], i});

    for (int i = k; i <= n; i++)
    {
        while (!maxHeap.empty() && maxHeap.top().second <= i - k)
            maxHeap.pop();

        cout << maxHeap.top().first << " ";

        if (i < n)
            maxHeap.push({arr[i], i});
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}
