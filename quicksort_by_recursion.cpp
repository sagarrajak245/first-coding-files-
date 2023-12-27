#include <iostream>
#include <math.h>
using namespace std;
void printarray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {

        cout << arr[i] << " ";
    }
}

int partition(int arr[], int s, int e)
{
    int pivot = arr[s]; // pivot define kiya

    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    int pivotindex = s + count;

    swap(arr[pivotindex], arr[s]); // p ko sahi position pe dala

    int i = s;
    int j = e;

    while (i < pivotindex && j > pivotindex)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] >= pivot)
        {
            j--;
        }

        if (i < pivotindex && j > pivotindex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotindex;
}

void quicksort(int arr[], int s, int e)
{

    if (s >= e)
        return;
    // place p at right position
    int p = partition(arr, s, e);

    quicksort(arr, s, p - 1);

    quicksort(arr, p + 1, e);
}

int main()
{

    int arr[5] = {1, 2, 3, 4, 5};

    cout << "enter the array\n";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    printarray(arr, 5);

    quicksort(arr, 0, 4);

    cout << "after sorting array is " << endl;
    printarray(arr, 5);

    return 0;
}