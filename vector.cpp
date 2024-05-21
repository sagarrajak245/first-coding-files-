#include <iostream>
#include <vector>

using namespace std;

// float avg(const vector<float> &v)
// {
//   float sum = 0;
//   for (const auto &n : v)
//     sum += n;            // sum all values.
//   return sum / v.size(); // divide by number of values.
// }

int main()
{
  vector<int> v = {1, 2, 3, 4, 5};

  int n = v.size();
  cout << "Size of vector is: " << n << endl;
  int cnt = 0;
  while (cnt < n)
  {
    cnt++;
  }
  cout << "cnt is: " << cnt << endl;

  return 0;
}