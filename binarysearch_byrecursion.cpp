#include <iostream>
using namespace std;

void printarray(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {

        cout << arr[i] << " ";
    }
    cout << endl;
}

bool binarysearch(int *arr, int start, int end, int key)
{
    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
        return true;
    if (start > end)
        return false;
    if (arr[mid] < key)
    {
        return binarysearch(arr, mid + 1, end, key);
    }
    else
    {
        return binarysearch(arr, start, mid - 1, key);
    }
}

int main()
{

    int arr[5];
    int key;
    cout << "enter the array\n";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    printarray(arr, 5);
    cout << endl;
    cout << "search the key" << endl;
    cin >> key;

    if (binarysearch(arr, 0, 5, key))
    {
        cout << "The key is present";
    }

    else
    {
        cout << "The key is absent";
    }

    return 0;
}