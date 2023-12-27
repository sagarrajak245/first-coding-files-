#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <list>
using namespace std;

void add_list(list<int> l1, list<int> l2)
{

    list<int> l3;
    int carry = 0;
    int sum = 0;
    while (!l1.empty() && !l2.empty())
    {
        sum = l1.front() + l2.front() + carry;
        carry = sum / 10;
        sum = sum % 10;
        l3.push_back(sum);
        l1.pop_front();
        l2.pop_front();
    }
    while (!l1.empty())
    {
        sum = l1.front() + carry;
        carry = sum / 10;
        sum = sum % 10;
        l3.push_back(sum);
        l1.pop_front();
    }
    while (!l2.empty())
    {
        sum = l2.front() + carry;
        carry = sum / 10;
        sum = sum % 10;
        l3.push_back(sum);
        l2.pop_front();
    }
    if (carry != 0)
    {
        l3.push_back(carry);
    }
    while (!l3.empty())
    {
        cout << l3.front() << " ";
        l3.pop_front();
    }
    cout << endl;
}

int main()
{

    list<int> l1, l2;

    l1.push_back(5);
    l1.push_back(6);
    // l1.push_back(7);

    l2.push_back(1);
    l2.push_back(2);
    l2.push_back(3);
    // add_list(l1, l2);

    for (auto it : l1)
    {

        cout << it << " ";
    }
    cout << endl;
    for (auto it : l2)
    {

        cout << it << " ";
    }

    return 0;
}