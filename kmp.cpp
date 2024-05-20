#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Compute the prefix function for the given pattern
vector<int> computePrefixFunction(const string &pattern)
{
    // Get the length of the pattern
    int n = pattern.size();

    // Create a vector to store the prefix function values, initialized with zeros
    vector<int> prefix(n, 0);

    // Initialize a variable k to keep track of the length of the longest proper prefix of the current substring
    int k = 0;

    // Loop through the pattern starting from the second character
    for (int i = 1; i < n; ++i)
    {
        // While there is a mismatch between the current character of the pattern and the character at index k
        while (k > 0 && pattern[k] != pattern[i])
        {
            // Move back in the pattern to find a shorter proper prefix that matches the current suffix
            k = prefix[k - 1];
        }

        // If the current character of the pattern matches the character at index k
        if (pattern[k] == pattern[i])
        {
            // Increment k to extend the current proper prefix
            ++k;
        }

        // Store the length of the longest proper prefix of the current substring
        prefix[i] = k;
    }

    // Return the computed prefix function values
    return prefix;
}

// KMP algorithm for pattern matching
void kmpSearch(const string &text, const string &pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> prefix = computePrefixFunction(pattern);
    int q = 0;
    for (int i = 0; i < n; ++i)
    {
        while (q > 0 && pattern[q] != text[i])
        {
            q = prefix[q - 1];
        }
        if (pattern[q] == text[i])
        {
            ++q;
        }
        if (q == m)
        {
            cout << "Pattern found at index " << i - m + 1 << endl;
            q = prefix[q - 1];
        }
    }
}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    cout << "Indices where pattern is found: " << endl;
    kmpSearch(text, pattern);
    return 0;
}
