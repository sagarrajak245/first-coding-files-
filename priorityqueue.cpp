
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// basic of priority queue min heap

int main()
{ // min heap
    priority_queue<pair<int, pair<int, pair<int, int>>>, vector<pair<int, pair<int, pair<int, int>>>>, greater<pair<int, pair<int, pair<int, int>>>>> pq;
    pq.push({1, {2, {3, 4}}});
    pq.push({5, {6, {7, 8}}});
    pq.push({9, {10, {11, 12}}});
    pq.push({13, {14, {15, 16}}});
    pq.push({17, {18, {19, 20}}});

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int val = top.first;
        int row = top.second.first;
        int col = top.second.second.first;
        int col2 = top.second.second.second;
        cout << val << " " << row << " " << col << " " << col2 << endl;
    }

    return 0;
}
