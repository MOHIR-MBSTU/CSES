#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 200003
vector<set<int>>tree(mx * 4);
vector<int>ar(mx);
void build(int node, int b, int e)
{
    if (b == e)
    {
        tree[node].insert(ar[b]);
        return;
    }
    int mid = (b + e) / 2;
    build(2 * node, b, mid);
    build(2 * node + 1, mid + 1, e);
    tree[node].insert(tree[2 * node].begin(), tree[2 * node].end());
    tree[node].insert(tree[2 * node + 1].begin(), tree[2 * node + 1].end());
}
 
// Query in an range a to b
set<int> query(int node, int l, int r, int a, int b)
{
    set<int> left, right, result;
 
    // If the range is out of the bounds
    // of this segment
    if (b < l || a > r)
        return result;
 
    // If the range lies in this segment
    if (a <= l && r <= b)
        return tree[node];
 
    // Else query for the right and left
    // leaf node of this subtree
    // and insert them into the set
    left = query(2 * node, l, (l + r) / 2, a, b);
    result.insert(left.begin(), left.end());
 
    right = query(1 + 2 * node, 1 + (l + r) / 2, r, a, b);
    result.insert(right.begin(), right.end());
 
    // Return the result
    return result;
}
int main()
{
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> ar[i];
    }
    int st = 1;
    int ed = 0;
    int cnt = 0;
    map<int, int>mp;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        while (cnt <= k and ed <= n)
        {
            ed++;
            mp[ar[ed]]++;
            if (mp[ar[ed]] == 1)
                cnt++;
        }
        ans += ed - i;
        mp[ar[i]]--;
        if (mp[ar[i]] == 0)cnt--;
    }
    cout << ans << endl;
    return 0;
}
