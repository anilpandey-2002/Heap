// C++ program to finds out smallest range that includes elements from each of the given sorted lists.
#include <bits/stdc++.h>
using namespace std;

#define N 5

int ptr[501];

// This function takes k sorted lists in the form of a 2D array and finds the smallest range
void findSmallestRange(int arr[][N], int n, int k)
{
    int i, minval, maxval, minrange, minel, maxel, flag, minind;

    // initializing to 0 index;
    for (i = 0; i <= k; i++)
        ptr[i] = 0;

    minrange = INT_MAX;

    while (1)
    {
        minind = -1;
        minval = INT_MAX;
        maxval = INT_MIN;
        flag = 0;

        // iterating over all the lists
        for (i = 0; i < k; i++)
        {
            if (ptr[i] == n)
            {
                flag = 1;
                break;
            }
            if (ptr[i] < n && arr[i][ptr[i]] < minval)
            {
                minind = i;
                minval = arr[i][ptr[i]];
            }
            if (ptr[i] < n && arr[i][ptr[i]] > maxval)
            {
                maxval = arr[i][ptr[i]];
            }
        }

        if (flag)
            break;

        ptr[minind]++;

        if ((maxval - minval) < minrange)
        {
            minel = minval;
            maxel = maxval;
            minrange = maxel - minel;
        }
    }

    printf("The smallest range is [%d, %d]\n", minel, maxel);
}

int main()
{
    int arr[][N] = {
        {4, 7, 9, 12, 15},
        {0, 8, 10, 14, 20},
        {6, 12, 16, 30, 50}};

    int k = sizeof(arr) / sizeof(arr[0]);

    findSmallestRange(arr, N, k);

    return 0;
}

// Using minHeap for the solution
typedef pair<int, pair<int, int>> pii;

pair<int, int> findSmallestRange(int arr[][N], int n, int k)
{
    priority_queue<pii, vector<pii>, greater<pii>> minH;

    int mx = INT_MIN, range = INT_MAX, minEle, maxEle;

    for (int i = 0; i < k; i++)
    {
        minH.push({arr[i][0], {i, 0}});
        if (mx < arr[i][0])
        {
            mx = arr[i][0];
        }
    }

    while (!minH.empty())
    {
        pii curr = minH.top();
        minH.pop();

        if (range > mx - curr.first)
        {
            range = mx - curr.first;
            maxEle = mx;
            minEle = curr.first;
        }

        int row = curr.second.first;
        int col = curr.second.second;

        if (col < n)
        {
            mx = max(arr[row][col + 1], mx);
            minH.push({arr[row][col + 1], {row, col + 1}});
        }
        else
            break;
    }

    return {minEle, maxEle};
}
