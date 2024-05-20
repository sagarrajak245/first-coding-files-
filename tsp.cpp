#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring> // Include the cstring header for memset
using namespace std;

#define V 4

int dp[1 << V][V];

int tsp(vector<vector<int>> &graph, int mask, int pos)
{
    if (mask == (1 << V) - 1)
    {
        return graph[pos][0];
    }
    if (dp[mask][pos] != -1)
    {
        return dp[mask][pos];
    }
    int minCost = INT_MAX;
    for (int i = 0; i < V; i++)
    {
        if ((mask & (1 << i)) == 0)
        {
            int newCost = graph[pos][i] + tsp(graph, mask | (1 << i), i);
            minCost = min(minCost, newCost);
        }
    }
    dp[mask][pos] = minCost;
    return minCost;
}

int main()
{
    vector<vector<int>> graph = {{0, 10, 15, 20},
                                 {10, 0, 35, 25},
                                 {15, 35, 0, 30},
                                 {20, 25, 30, 0}};

    // Use memset to initialize the DP table with -1
    memset(dp, -1, sizeof(dp));

    int minDistance = tsp(graph, 1, 0);

    cout << "The minimum cost of the Travelling Salesman Problem is: " << minDistance << endl;

    return 0;
}
