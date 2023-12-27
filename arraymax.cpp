#include <iostream>
using namespace std;

int max(int arr[], int size)
{

    int maxi;

    for (int i = 0; i < size; i++)
    {
        int maxi = arr[0];
        if (maxi < arr[i])
        {
            maxi = arr[i];
        }
    }

    return maxi;
}

int main()
{
    int arr[5];

    cout << "enter the array" << endl;

    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << "\t";
    }
    int ans = max(arr, 5);
    cout << endl;
    cout << "The maximum of array is\n"
         << ans;

    return 0;
}
