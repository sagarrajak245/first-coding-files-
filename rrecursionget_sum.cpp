#include <iostream>
using namespace std;

void printarray(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {

        cout << arr[i] << " ";
    }
}

int getsum(int *arr, int size)
{

    if (size == 0)
        return 0; // base cae 1
    if (size == 1)
        return arr[0];

    int rempart = getsum(arr + 1, size - 1);

    int sum = arr[0] + rempart;

    return sum;
}

int main()
{
    int arr[5];
    int sum;
    cout << "enter the array\n";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    printarray(arr, 5);
    cout << endl;
    sum = getsum(arr, 5);

    cout << "the sum of array by recursion is " << sum;

    return 0;
}