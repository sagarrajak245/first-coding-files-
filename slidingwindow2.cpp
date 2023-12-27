#include <iostream>
#include <vector>
using namespace std;

int slide(int arr[50], int t, int targetsum)
{

    int i = 0;
    int j = 0;
    int sum = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    int maxi = INT32_MIN;

    while (j < size)
    {

        sum = sum + arr[j];

        if (sum == targetsum)
        {
            maxi = max(maxi, j - i + 1);
            j++;
        }

        else if (sum > targetsum)
        {

            while (sum > targetsum && i < j)
            {

                sum = sum - arr[i];
                i++;
            }
            if (sum == targetsum)
            {
                maxi = max(maxi, j - i + 1);
            }

            j++;
        }
    }
    return maxi;
}

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
        4,
    };

    int ans;
    int targetsum;

    cout << "enter the target sum" << endl;
    cin >> targetsum;

    ans = slide(arr, 50, targetsum);

    cout << "the size of largest subarray is" << ans;

    return 0;
}