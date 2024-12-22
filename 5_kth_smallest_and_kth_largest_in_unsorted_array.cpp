#include <iostream>
#include <algorithm>
using namespace std;

int kthSmallestSort(int arr[], int n, int k)
{
    sort(arr, arr + n); // Sort the array
    return arr[k - 1];  // Return k'th element
}

int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]), k = 3;
    cout << "K'th smallest element (Sorting): " << kthSmallestSort(arr, n, k) << endl;
    return 0;
}
