
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

class Solution
{

public:
    string reverseWords(string s)
    {
        stack<string> st;
        string p;

        stringstream ss(s);

        while (ss >> p)
        {
            st.push(p);
        }

        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }

        // stack <string> ans;
        string ans;
        while (!st.empty())
        {

            // if (!st.empty())

            ans += st.top();
            st.pop();
            ans += " ";

            //  cout << ans << endl;
        }

        return ans;
    }
};
int main()
{

    string s = "i love coding";
    Solution obj;
    cout << obj.reverseWords(s) << endl;
    return 0;
}