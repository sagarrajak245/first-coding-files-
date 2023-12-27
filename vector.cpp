#include <iostream>
#include <vector>

using namespace std;

float avg(const vector<float> &v)
{
  float sum = 0;
  for (const auto &n : v)
    sum += n;            // sum all values.
  return sum / v.size(); // divide by number of values.
}

int main()
{
  vector<float> v = {1, 2, 3, 4, 5};
  float avg_value = avg(v);
  cout << "The average value is: " << avg_value << endl;
  return 0;
}