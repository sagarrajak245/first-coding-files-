
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

        // stack <string> ans;
        string ans;
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
            if (!st.empty())
            {
                ans += " ";
            }
        }

        return ans;
    }
};
int main()
{

    string s = "i love coding";
    Solution obj;
    cout << obj.reverseWords(s) << endl;
    /*for (auto x : obj.reverseWords(s))
     {
         s.erase(s.begin() + 1);
         cout << x << endl;
     }
 */
    return 0;
}