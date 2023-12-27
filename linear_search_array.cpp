
#include <iostream>
using namespace std;

bool search(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (key == arr[i])
        {
            return 1;
        }
    }
    return 0;
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

    cout << "enter the key u want \n";
    cin >> key;

    bool found = search(arr, 5, key);
    if (found)
    {
        cout << "key is present";
    }
    else
    {
        cout << "key is absent";
    }

    return 0;
}