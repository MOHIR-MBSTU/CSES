#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int n;
vector<ll>adj[200003];
vector<bool> visited(200003);
vector<int> parent(200003);
int cycle_start, cycle_end;
 
bool dfs(int v, int par) { // passing vertex and its parent vertex
    visited[v] = true;
    for (int u : adj[v]) {
        if (u == par) continue; // skipping edge to parent vertex
        if (visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
}
 
int main()
{
    ll m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)parent[i] = i;
    for (int i = 1; i <= m; i++)
    {
        ll ai, bi; cin >> ai >> bi;
        adj[bi].push_back(ai);
        adj[ai].push_back(bi);
    }
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0 and dfs(i, i))
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
 
        cout << cycle.size() << endl;
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
 
    }
    return 0;
}