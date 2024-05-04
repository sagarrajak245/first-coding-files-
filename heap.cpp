#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// time complexity of heap is O(logn) for insertion and deletion
class heap
{

public:
    int arr[100];
    int size = 0;
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    void display()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteRoot()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }
        arr[1] = arr[size];   // root se swap kiya last node
        size--;               // size kam kari array ki
        int index = 1;        // one based indexing hai
        while (index <= size) // prpogate kiya root ko sahi jagaha pe
        {
            int left = 2 * index;
            int right = 2 * index + 1;

            if (left < size && arr[index] < arr[left])
            {
                swap(arr[index], arr[left]);
                index = left;
            }
            else if (right < size && arr[index] < arr[right])
            {
                swap(arr[index], arr[right]);
                index = right;
            }
            else
            {
                break;
            }
        }
    }
};

int main()
{

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.display();
    h.deleteRoot();
    cout << "the heap after deletion" << endl;
    h.display();
    return 0;
}
