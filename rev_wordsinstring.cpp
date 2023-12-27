#include <iostream>
#include <vector>
using namespace std;

// reverse words in given string
int main()
{
    string s = "i love coding";
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
    cout << s << endl;
    int start = 0;
    int end = 0;
    while (end < s.length())
    {
        if (s[end] == ' ')
        {
            i = start;
            j = end - 1;
            while (i < j)
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            start = end + 1;
        }
        end++;
    }
    i = start;
    j = end - 1;
    while (i < j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
    cout << s << endl;
    return 0;
}
