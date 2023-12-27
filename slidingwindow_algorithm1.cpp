#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int arr[50] = {
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        1,
        2,
        3,
        5,
        4,};
    int targetsum;

    cout << "enter the size of window";
    cin >> targetsum;

    int i = 0;
    int j = 0;
    int sum = 0;
    int size = sizeof(arr) / sizeof(arr[0]);

    while (j < size)
    {

        sum = sum + arr[j];
        j++;

        while (sum > targetsum && i < j)
        {

            sum = sum - arr[i];
            i++;
        }
        if (sum == targetsum)
        {
            cout << "the range of max sum is from indexes"
                 << " " << i << " " << j - 1 << endl;
        }
    }

    return 0;
}