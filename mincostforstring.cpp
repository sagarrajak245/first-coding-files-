

class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        vector<vector<long long>> minCost(26, vector<long long>(26, LLONG_MAX));

        // Initialize direct transformations
        for (int i = 0; i < original.size(); i++)
        {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            minCost[from][to] = min(minCost[from][to], (long long)cost[i]);
        }

        // Floyd-Warshall algorithm to find minimum cost between any two characters
        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (minCost[i][k] != LLONG_MAX && minCost[k][j] != LLONG_MAX)
                    {
                        minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                    }
                }
            }
        }

        long long totalCost = 0;
        for (int i = 0; i < source.length(); i++)
        {
            if (source[i] == target[i])
                continue;

            int from = source[i] - 'a';
            int to = target[i] - 'a';

            if (minCost[from][to] == LLONG_MAX)
                return -1;
            totalCost += minCost[from][to];
        }

        return totalCost;
    }
};