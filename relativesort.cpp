
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        vector<int> remainingElements;

        // Create a frequency map for arr1
        for (int num : arr1)
        {
            mp[num]++;
        }

        // Add elements to result based on the order of arr2
        for (int num : arr2)
        {
            while (mp[num] > 0)
            {
                ans.push_back(num); // Add the element to the result
                mp[num]--;          // Decrement the frequency
            }
        }

        // Collect remaining elements that are not in arr2
        for (auto it : mp)
        {
            while (it.second > 0)
            {
                remainingElements.push_back(it.first);
                it.second--;
            }
        }

        // Sort the remaining elements
        sort(remainingElements.begin(), remainingElements.end());

        // Add the sorted remaining elements to the result
        ans.insert(ans.end(), remainingElements.begin(), remainingElements.end());

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};
    vector<int> result = s.relativeSortArray(arr1, arr2);
    for (auto num : result)
    {
        cout << num << " ";
    }
    return 0;
}
