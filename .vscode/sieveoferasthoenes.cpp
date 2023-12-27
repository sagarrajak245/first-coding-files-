// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;

void Sieve(int n)
{
    // Create a boolean array sieve of size n
    // Intialise all entries as true.
    bool sieve[n + 1];
    memset(sieve, true, sizeof(sieve));

    for (int i = 2; i * i <= n; i++)
    {
        // If sieve[i] is not changed, then it is a prime
        if (sieve[i] == true)
        {
            // If sieve[i] is true make
            // the multiples of i as false in the sieve array less than or equal to n
            for (int j = i * i; j <= n; j += i)
                sieve[j] = false;
        }
    }

    // Print all prime numbers
    for (int prime = 2; prime <= n; prime++)
    {
        // A value in
        //  sieve[i] will finally be false if i is not a
        //  prime, else true.
        if (sieve[prime])
            cout << prime << " ";
    }
}

// Driver Code
int main()
{
    // input number
    int n;
    cout << "enter the number";
    cin >> n;
    // calling the Sieve function to print all prime numbers
    Sieve(n);
    return 0;
}
