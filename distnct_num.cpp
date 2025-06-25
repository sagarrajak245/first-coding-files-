#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 5, 4};
    int distinctCount = 0;
    cout << "Distinct numbers in the array: ";
    unordered_set<int> distinctSet;
    for (auto it : nums)
    {
        if (distinctSet.find(it) == distinctSet.end())
        {
            cout << it << " ";
            distinctSet.insert(it);
            distinctCount++;
        }
    }

    cout << "\nTotal distinct numbers: " << distinctCount << endl;
    // using set
    set<int> distinctSet2;
    for (auto it : nums)
    {
        distinctSet2.insert(it);
    }
    cout << "Distinct numbers using set: ";
    for (auto it : distinctSet2)
    {
        cout << it << " ";
    }
    cout << "\nTotal distinct numbers using set: " << distinctSet2.size() << endl;
    // using map
    map<int, int> distinctMap;
    for (auto it : nums)
    {
        distinctMap[it]++;
    }
    cout << "Distinct numbers using map: ";
    for (auto it : distinctMap)
    {
        cout << it.first << " ";
    }
    cout << "\nTotal distinct numbers using map: " << distinctMap.size() << endl;
    

    return 0;
}