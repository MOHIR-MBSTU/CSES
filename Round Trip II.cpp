#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>v[200003];
vector<ll>par(200033, 0);
vector<ll>colour(200003, 0);
ll cycle_start = 0;
ll cycle_end = 0;
bool dfs(ll node)
{
    colour[node] = 1;
    for (auto x : v[node])
    {
        if (colour[x] == 0)
        {
            par[x] = node;
            if (dfs(x))
                return true;
        }
        else if (colour[x] == 1)
        {
            cycle_start = x;
            cycle_end  = node;
            return true;
        }
    }
    colour[node] = 2;
    return false;
}
int main()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        ll ai, bi; cin >> ai >> bi;
        v[ai].push_back(bi);
    }
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (colour[i] == 0 and dfs(i))
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
        for (int v = cycle_end; v != cycle_start; v = par[v])
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
