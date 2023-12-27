#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;

bool ismatch(char ch, char popped)
{
    if (ch == ')' && popped == '(')
    {
        return true;
    }
    else if (ch == '}' && popped == '{')
    {
        return true;
    }
    else if (ch == ']' && popped == '[')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool valid(string s)
{
    stack<char> st;
    char ch;
    char popped;
    int i;
    while (i < s.length())
    {
        ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            else
            {
                popped = st.top();
                st.pop();
                if (!ismatch(ch, popped))
                {
                    return false;
                }
            }
        }
        i++;
    }
    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    string s = "()[]{}";

    if (valid(s))
    {
        cout << "it is balanced";
    }
    else
    {
        cout << "it is not balanced";
    }

    return 0;
}