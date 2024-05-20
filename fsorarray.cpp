#include <iostream>
#include <algorithm>
using namespace std;
// sort with repeating chracters

void sort(int arr[], int n)
{
    int count[n] = {0};
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << count[i] << " ";
    }

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (count[i] > 0)
        {
            arr[j] = i;
            j++;
            count[i]--;
        }
    }
}

int main()
{

    int arr[] = {5,
                 5,
                 5,
                 4,
                 4,
                 2,
                 2,
                 2,
                 3,
                 3,
                 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, n);
    cout << "the array after sorting is : \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}