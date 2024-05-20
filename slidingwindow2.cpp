#include <iostream>
using namespace std;

int maxSubarraySize(int arr[], int size, int targetSum)
{
    int maxSize = 0;    // Initialize maxSize to 0
    int windowSum = 0;  // Initialize the sum of the current window
    int left = 0;       // Initialize the left pointer of the window
    bool found = false; // Flag to indicate if a valid subarray with the target sum is found

    for (int right = 0; right < size; ++right)
    {
        windowSum += arr[right]; // Expand the window by adding the current element

        // Shrink the window from the left until the window sum is less than or equal to the target sum
        while (windowSum > targetSum && left <= right)
        {
            windowSum -= arr[left];

            ++left;
        }

        // Update maxSize if the current window size is greater
        if (windowSum == targetSum)
        {
            maxSize = max(maxSize, right - left + 1);
            found = true; // Set found flag to true
        }
    }

    return found ? maxSize : 0; // Return maxSize if a valid subarray is found, otherwise return 0
}

int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 5, 4};
    int size = sizeof(nums) / sizeof(nums[0]);
    int targetSum;

    cout << "Enter the target sum: ";
    cin >> targetSum;

    int maxSize = maxSubarraySize(nums, size, targetSum);

    if (maxSize > 0)
    {
        cout << "The size of the largest subarray with the target sum is: " << maxSize << endl;
    }
    else
    {
        cout << "No subarray found with the target sum." << endl;
    }

    return 0;
}
