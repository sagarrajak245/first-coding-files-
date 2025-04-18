#include <iostream>
#include <algorithm>
using namespace std;
// it is unstable algorithm
// it is inplace algorithm

int desbubble_short(int arr[], int size)
{
    int cnt = 0;
    for (int i = 1; i < size; i++)
    {

        for (int j = 0; j < size - i; j++)
        {

            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                cnt++;
            }
        }
    }
    return cnt;
}

int Asbubble_short(int arr[], int size)
{
    int cnt = 0;
    for (int i = 1; i < size; i++)
    {

        for (int j = 0; j < size - i; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                cnt++;
            }
        }
    }
    return cnt;
}

void printarray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {

        cout << arr[i] << " ";
    }
}
int main()
{

    int arr[] = {1, 5, 99, 88, 77};

    int ascending = Asbubble_short(arr, 5);
    int descending = desbubble_short(arr, 5);

    int ans = -1;
    ans = min(ascending, descending);

    cout << "Ascending order: " << ascending << endl;
    cout << "Descending order: " << descending << endl;
    cout << "Minimum number of swaps: " << ans << endl;

    return 0;
}