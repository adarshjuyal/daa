#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<int> &vis, vector<int> adj[], vector<int> &res)
{
    vis[u] = 1;
    res.push_back(u);
    for (auto it : adj[u])
    {
        if (!vis[it])
        {

            dfs(it, vis, adj, res);
        }
    }
}
bool Path(int n, int u, int v, vector<int> adj[])
{
    vector<int> vis(n, 0);
    vector<int> res;

    dfs(u, vis, adj, res);
    for (int i = 0; i < n; i++)
    {
        if (res[i] == v)
        {
            return true;
        }
    }
    return false;
}

void adjList(vector<vector<int>> matrix, vector<int> adj[])
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] = 1)
                adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
}

int main()
{
    int V, e;
    cout << "enter the number of vertex" << endl;
    cin >> V;
    cout << "enter the number of edges " << endl;
    cin >> e;
    vector<vector<int>> matrix(V, vector<int>(V, 0));
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cout << "Enter u " << endl;
        cin >> u;
        cout << "enter v" << endl;
        cin >> v;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }
    vector<int> adj[V];
    adjList(matrix, adj);
    cout << "enter the  start node and end node" << endl;
    int node, dest;
    cin >> node >> dest;
    bool h = Path(V, node, dest, adj);
    if (h == true)
        cout << "exits";
    else
        cout << "not exits";
}
