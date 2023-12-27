#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
int main()
{
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    cout << "list is\n";
    for (auto i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    l.pop_back();
    cout << "list after pop_back\n";
    for (auto i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    l.push_front(0);
    cout << "list after push_front\n";
    for (auto i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    l.pop_front();
    cout << "list after pop_front\n";
    for (auto i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "list size is " << l.size() << endl;
    cout << "list max_size is " << l.max_size() << endl;
    cout << "list empty or not " << l.empty() << endl;
    cout << "list front element is " << l.front() << endl;
    cout << "list back element is " << l.back() << endl;
    cout << "list after reverse\n";
    l.reverse();
    for (auto i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "list after sort\n";

    l.sort();
    for (auto i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "list after clear\n";
    l.clear();
    for (auto i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
