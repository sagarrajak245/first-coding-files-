#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  // Initialize the vector of vectors
  vector<vector<int>> v = {{1, 3}, {8, 4}, {2, 5}};

  // Sort the vector of vectors based on the first element of each inner vector
  sort(v.begin(), v.end(), [](const vector<int> &a, const vector<int> &b)
       { return a[0] < b[0]; });

  // Print the sorted vector
  for (const auto &vec : v)
  {
    cout << vec[1];
  }
  // reverese the vector
  reverse(v.begin(), v.end());

  return 0;
}
