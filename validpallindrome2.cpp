#include <iostream>
#include <algorithm>
// #include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string removeSpaces(string str)
    {
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        return str;
    }
    char lowercase(char ch)
    {
        char temp;
        if (ch >= 'a' && ch <= 'z' || ch >= 0 && ch <= 9)
        {
            return ch;
        }
        else
        {
            temp = ch - 'A' + 'a';
        }
        return temp;
    }

    bool validpallindrome(string temp)
    {

        int start = 0;
        int end = temp.length() - 1;
        while (start <= end)
        {

            if (temp[start] == temp[end])
            {
                start++;
                end--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

public:
    bool isPalindrome(string s)
    {
        string temp = removeSpaces(s);
        int i;
        for (int i = 0; i < temp.length(); i++)
        {
            temp[i] = lowercase(temp[i]);
        }

        bool ans = validpallindrome(temp);

        return ans;
    }
};

int main()
{

    string str = "A man, a plan, a canal: Panama";

    Solution s;
    cout << s.isPalindrome(str);

    return 0;
}