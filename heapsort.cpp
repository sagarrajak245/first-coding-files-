#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(vector<int> &arr)
{
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    heapsort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    // priority queue is implemented using heap
    cout << "Priority Queue" << endl;
    priority_queue<int> pq;
    pq.push(10);
    pq.push(15);
    pq.push(5);
    pq.push(20);
    cout << "top elelment " << pq.top() << endl;

    return 0;
}
