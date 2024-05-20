#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// heapify _Algorithm

class heap
{
public:
    vector<int> arr;

    void heapify(int i)
    {
        int size = arr.size();
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }
};

int main()
{
    heap h;
    h.arr = {54, 53, 55, 52, 50};
    int n = h.arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        h.heapify(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << h.arr[i] << " ";
    }

    return 0;
}