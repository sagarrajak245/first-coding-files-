#include <iostream>
#include <string.h>
using namespace std;

void rev(string &s, int i, int j)
{

    if (i > j)
        return ; // base case

    swap(s[i], s[j]);
    i++;
    j--;
    // recursive call
    rev(s, i, j);
}

int main()
{

    string str;
    cout << "enter the string ";
    getline(cin, str);

    cout << "ur string is :" << str;
    rev(str, 0, str.length() - 1);

    cout << " reverse of ur string is :" << str;

    return 0;
}