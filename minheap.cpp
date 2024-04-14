#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int i, int size)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] < arr[smallest])
        smallest = left;

    if (right < size && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(arr, smallest, size);
    }
}

void buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }
}

int main()
{
    vector<int> arr = {9, 4, 7, 1, 2, 8, 6};
    cout << "Original array:" << endl;
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    buildMinHeap(arr);

    cout << "Min heap:" << endl;
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
