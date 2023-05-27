#include <bits/stdc++.h>

using namespace std;

void bfs(vector<int> adj[], vector<int> vis)
{

    queue<int> q;

    q.push(0);
    vis[0] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (auto x : adj[node])
        {
            if (!vis[x])
            {
                q.push(x);
                vis[x] = true;
            }
        }
    }
}

void dfs(int src, vector<int> adj[], vector<int> &vis)
{
    vis[src] = true;
    cout << src << " ";
    for (auto x : adj[src])
    {
        if (!vis[x])
        {
            dfs(x, adj, vis);
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);

    bfs(adj, vis);
    cout << endl;
    dfs(0, adj, vis);

    return 0;
}