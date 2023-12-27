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

bool linearsearch(int *arr, int size, int key)
{
    printarray(arr, 5);

    if (size == 0)
        return false; // base cae 1 when we run through an entire array and dont find the key then return false..
    if (arr[0] == key)
        return true;

    bool rempart = linearsearch(arr + 1, size - 1, key);

    return rempart;
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

    if (linearsearch(arr, 5, key))
    {
        cout << "The key is present";
    }

    else
    {
        cout << "The key is absent";
    }

    return 0;
}