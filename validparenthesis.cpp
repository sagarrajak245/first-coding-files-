#include <iostream>
#include <stack>
using namespace std;

bool validparenthesis(stack<char> &s1)
{

    stack<char> s2;
    while (!s1.empty())
    {

        if (s1.top() == '(' || s1.top() == '{' || s1.top() == '[')
        {
            s2.push(s1.top());
            s1.pop();
        }
        else if (s1.top() == ')' || s1.top() == '}' || s1.top() == ']')
        {
            if (s2.empty())
            {
                return false;
            }
            else if (s1.top() == ')' && s2.top() == '(')
            {
                s1.pop();
                s2.pop();
            }
            else if (s1.top() == '}' && s2.top() == '{')
            {
                s1.pop();
                s2.pop();
            }
            else if (s1.top() == ']' && s2.top() == '[')
            {
                s1.pop();
                s2.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (s2.empty())
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

    stack<char> s1;
    s1.push('{');
    s1.push('[');
    s1.push('(');
    s1.push('}');
    s1.push(']');
    s1.push(')');

    cout << endl
         << s1.top() << endl;
    cout << endl;
    if (validparenthesis(s1))
    {
        cout << "valid parenthesis";
    }
    else
    {
        cout << "invalid parenthesis";
    }
    return 0;
}
