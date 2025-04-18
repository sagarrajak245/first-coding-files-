#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> strs = {"7868190130M7522", "5303914400F9211", "9273338290F4010"};

    // Extract and print the substring from each string
    for (int i = 0; i < strs.size(); i++)
    {
        // Extracting the substring from index 12 of length 4
        cout << strs[i].substr(11, 2) << endl;
    }

    return 0;
}
