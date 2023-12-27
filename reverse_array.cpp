
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void reverse(int arr[], int size)
{

    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void printarray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {

        cout << arr[i] << " ";
    }
}

int main()
{ /*
     int arr[5];
     int brr[6];
     cout << "enter the array odd\n";
     for (int i = 0; i < 5; i++)
     {
         cin >> arr[i];
     }

     cout << " enter the array even\n";
     for (int i = 0; i < 6; i++)
     {
         cin >> brr[i];
     }

     reverse(arr, 5);
     reverse(brr, 6);

     cout << "reverse odd array is\n";
     printarray(arr, 5);
     cout << "\n";

     cout << "reverse even array is\n";
     printarray(brr, 6);*/

    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    reverse(a.begin(), a.end());
    cout << "reverse vector is\n";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}