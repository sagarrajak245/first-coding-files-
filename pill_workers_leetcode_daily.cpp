#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    bool canAssign(int mid, vector<int> &tasks, vector<int> &workers, int pills, int strength)
    {
        multiset<int> workerSet(workers.end() - mid, workers.end()); // take strongest mid workers

        for (int i = mid - 1; i >= 0; --i)
        { // hardest tasks first
            int task = tasks[i];

            auto it = workerSet.lower_bound(task); // direct match

            if (it != workerSet.end())
            {
                workerSet.erase(it); // assign task
            }
            else if (pills > 0)
            {
                // Find weakest worker who can do it with pill
                it = workerSet.lower_bound(task - strength);
                if (it == workerSet.end())
                    return false;
                workerSet.erase(it);
                pills--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }

    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
    {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0, right = min((int)tasks.size(), (int)workers.size());

        while (left < right)
        {
            int mid = (left + right + 1) / 2;
            if (canAssign(mid, tasks, workers, pills, strength))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left;
    }
};

int main()
{
    //     Input: tasks = [10,15,30], workers = [0,10,10,10,10], pills = 3, strength = 10
    // Output: 2
    // Explanation:
    // We can assign the magical pills and tasks as follows:
    // - Give the magical pill to worker 0 and worker 1.
    // - Assign worker 0 to task 0 (0 + 10 >= 10)
    // - Assign worker 1 to task 1 (10 + 10 >= 15)
    // The last pill is not given because it will not make any worker strong enough for the last task.
    vector<int> tasks = {10, 15, 30};
    vector<int> workers = {0, 10, 10, 10, 10};
    int pills = 3;
    int strength = 10;
    Solution solution;
    int result = solution.maxTaskAssign(tasks, workers, pills, strength);
    cout << "Maximum number of tasks that can be assigned: " << result << endl;

    return 0;
}