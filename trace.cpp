#include <iostream>
#include <math.h>
using namespace std;

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
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ' ';
    }

    return pivotindex;
}

int main()
{

    int arr[10] = {5, 4, 38, 6, 8, 4, 45, 2, 1, 3};

    /* cout << "enter the array\n";
     for (int i = 0; i < 5; i++)
     {
         cin >> arr[i];
     }*/
    //  printarray(arr, 5);

    // quicksort(arr, 0, 4);

    /* cout << "after sorting array is " << endl;
     for(int i=0;i<5;i++){
         cout<<arr[i]<<' ';
     }*/

    int p = partition(arr, 0, 9);
    cout << "the pivot index is" << p;

    return 0;
}