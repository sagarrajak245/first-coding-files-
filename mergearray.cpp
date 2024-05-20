
#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeArrays(vector<int> arr1, vector<int> arr2)
{
    int len1 = arr1.size() - 1;
    int len2 = arr2.size() - 1;
    int i = 0, j = 0;
    vector<int> arr3;

    // Merge arrays while there are elements in both arrays
    while (i < len1 && j < len2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr3.push_back(arr1[i]);
            i++;
        }
        else
        {
            arr3.push_back(arr2[j]);
            j++;
        }
    }

    // If there are remaining elements in arr1, append them to arr3
    while (i <= len1)
    {
        arr3.push_back(arr1[i]);
        i++;
    }

    // If there are remaining elements in arr2, append them to arr3
    while (j <= len2)
    {
        arr3.push_back(arr2[j]);
        j++;
    }

    return arr3;
}

int main()
{
    vector<int> arr1 = {1, 3, 5, 7, 9};
    vector<int> arr2 = {2, 4, 6, 8, 10};

    vector<int> arr3 = mergeArrays(arr1, arr2);

    for (int i = 0; i < arr3.size(); i++)
    {
        cout << arr3[i] << " ";
    }

    return 0;
}
