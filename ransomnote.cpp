#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        // Count occurrences of each character in magazine
        unordered_map<char, int> charCount;
        for (auto ch : magazine)
        {
            charCount[ch]++;
        }

        // Check if characters in ransomNote can be constructed from magazine
        for (auto ch : ransomNote)
        {
            if (charCount.find(ch) == charCount.end() || charCount[ch] == 0)
            {
                return false; // Character not found or used up
            }
            charCount[ch]--; // Decrement count as the character is used
        }

        return true;
    }
};

int main()
{
    Solution sol;
    string ransomNote = "aa", magazine = "aab";
    cout << sol.canConstruct(ransomNote, magazine) << endl; // Output: true

    ransomNote = "a", magazine = "b";
    cout << sol.canConstruct(ransomNote, magazine) << endl; // Output: false

    return 0;
}
