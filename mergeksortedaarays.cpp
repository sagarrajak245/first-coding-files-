#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Merge k sorted arrays
// approach one
// vector<int> mergeKsortedArrays(vector<vector<int>> &arr)
// {
//     vector<int> ans;
//     priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

//     // Push the first element from each row into the priority queue
//     for (int i = 0; i < arr.size(); ++i)
//     {
//         pq.push({arr[i][0], {i, 0}});
//     }

//     // Merge step
//     while (!pq.empty())
//     {
//         auto top = pq.top();
//         pq.pop();
//         int val = top.first;
//         int row = top.second.first;
//         int col = top.second.second;
//         ans.push_back(val);
//         if (col + 1 < arr[row].size())
//         {
//             pq.push({arr[row][col + 1], {row, col + 1}});
//         }
//     }

//     return ans;
// }

// approach two

// Merge k sorted arrays using min heap
vector<int> mergeKsortedArrays(vector<vector<int>> &arr)
{
    vector<int> ans;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Push the first element from each row into the priority queue
    for (int i = 0; i < arr.size(); ++i)
    {
        if (!arr[i].empty())
        { // Check if row is not empty
            pq.push({arr[i][0], {i, 0}});
        }
    }

    // Merge step
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int val = top.first;
        int row = top.second.first;
        int col = top.second.second;
        ans.push_back(val);
        if (col + 1 < arr[row].size())
        {
            pq.push({arr[row][col + 1], {row, col + 1}});
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4},
                               {2, 3, 4, 5},
                               {5, 6, 7, 8},
                               {6, 7, 8, 9}};

    vector<int> ans = mergeKsortedArrays(arr);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
