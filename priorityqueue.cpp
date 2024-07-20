
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// basic of priority queue min heap

int main()
{ // min heap
  // priority_queue<pair<int, pair<int, pair<int, int>>>, vector<pair<int, pair<int, pair<int, int>>>>, greater<pair<int, pair<int, pair<int, int>>>>> pq;
  // pq.push({1, {2, {3, 4}}});
  // pq.push({5, {6, {7, 8}}});
  // pq.push({9, {10, {11, 12}}});
  // pq.push({13, {14, {15, 16}}});
  // pq.push({17, {18, {19, 20}}});

  // while (!pq.empty())
  // {
  //     auto top = pq.top();
  //     pq.pop();
  //     int val = top.first;
  //     int row = top.second.first;
  //     int col = top.second.second.first;
  //     int col2 = top.second.second.second;
  //     cout << val << " " << row << " " << col << " " << col2 << endl;
  // }

  priority_queue<int, vector<int>, greater<int>> pq; // min heap

  pq.push(95);
  pq.push(25);
  pq.push(30);
  pq.push(40);
  pq.push(5);
  for (int i = 0; i < 5; i++)
  {
    cout << pq.top() << " ";
    pq.pop();
  }

  // max heap

  // // priority_queue<int> mq;
  // mq.push(95);
  // mq.push(25);
  // mq.push(30);
  // mq.push(40);
  // for (int i = 0; i < 4; i++)
  // {
  //   cout << mq.top() << " ";
  //   mq.pop();
  // }

  return 0;
}
