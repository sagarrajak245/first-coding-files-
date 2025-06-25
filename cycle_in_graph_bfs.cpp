#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool bfs_cycle(int src, vector<int> &visited, vector<int> &parent, vector<vector<int>> &adj)
    {
        queue<pair<int, int>> q;
        q.push({src, -1});
        visited[src] = 1;
        while (!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = 1;
                    parent[it] = node;
                    q.push({it, node});
                }
                else if (it != par)
                {
                    return true; // cycle detected
                }
            }
        }
        return false; // no cycle detected
    }

    int main()
    {
        int n, m;
        cout << "Enter number of nodes and edges: ";
        cin >> n >> m;

        vector<vector<int>> adj(n);
        cout << "Enter edges (u v):" << endl;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected graph
        }

        vector<int> visited(n, 0);
        vector<int> parent(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (bfs_cycle(i, visited, parent, adj))
                {
                    cout << "Cycle detected in the graph." << endl;
                    return 0;
                }
            }
        }

        cout << "No cycle detected in the graph." << endl;
        return 0;
    }