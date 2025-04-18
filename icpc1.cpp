#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N, K;
    cin >> N >> K;

    vector<int> L(K), R(K), m(K);
    for (int i = 0; i < K; i++)
    {
        cin >> L[i] >> R[i] >> m[i];
        // No need to convert indices as they are already 1-based
    }

    // Create array with 1-based indexing (using N+1 size)
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++)
    {
        A[i] = N - i + 1; // Fill with N, N-1, N-2, ... 1
    }

    // Check each constraint
    for (int i = 0; i < K; i++)
    {
        // Find minimum in range [L[i], R[i]]
        int minInRange = *min_element(A.begin() + L[i], A.begin() + R[i] + 1);

        if (minInRange == m[i])
        {
            // If constraint is violated, try modifying array
            bool fixed = false;
            // Try adjusting values in the range to avoid mi being minimum
            for (int j = L[i]; j <= R[i] && !fixed; j++)
            {
                if (A[j] == m[i])
                {
                    // Try putting a smaller value
                    for (int newVal = 1; newVal < m[i]; newVal++)
                    {
                        A[j] = newVal;
                        // Check if this fixes all previous constraints
                        bool validForAll = true;
                        for (int k = 0; k <= i; k++)
                        {
                            int newMin = *min_element(A.begin() + L[k], A.begin() + R[k] + 1);
                            if (newMin == m[k])
                            {
                                validForAll = false;
                                break;
                            }
                        }
                        if (validForAll)
                        {
                            fixed = true;
                            break;
                        }
                    }
                    if (!fixed)
                        A[j] = N - j + 1; // Restore if couldn't fix
                }
            }
            if (!fixed)
            {
                cout << "-1\n";
                return;
            }
        }
    }

    // Print the valid array (1-based indices)
    for (int i = 1; i <= N; i++)
    {
        cout << A[i] << (i < N ? " " : "\n");
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}