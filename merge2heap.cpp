#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// merge two heaps

void heapify(vector<int> arr, int size, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, size, largest);
    }
}

void mergeHeaps(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        ans.push_back(arr2[i]);
    }
    int size = ans.size();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(ans, size, i);
    }
    for (int i = 0; i < size; i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    vector<int> arr1 = {10, 5, 6, 2};
    vector<int> arr2 = {12, 7, 9};
    int n = arr1.size();
    int m = arr2.size();
    mergeHeaps(arr1, arr2, n, m);
    return 0;
}