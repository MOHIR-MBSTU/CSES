#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastread  ios_base::sync_with_stdio(false),cin.tie(NULL)
#define pb push_back
#define ha cout<<"YES\n"
#define na cout<<"NO\n"
#define endl "\n"
#define co(x) cout<<x<<'\n'
#define f(n) for(int i=0;i<n;i++)
#define srt(v) sort(v.begin(),v.end())
#define mod 1000000007
#define INF 1e18
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef pair<int, int> pii;
tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> T;
ll bigmod(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
struct fun
{
    ll u, cst, chk;
    bool operator <(const fun &it)const
    {
        return cst > it.cst;
    }
};
ll power(ll a, ll b)
{
    ll c = 1;
    while (b--)c *= a;
    return c;
}
 
int fx[] = { +0, +0, +1, -1, -1, +1, -1, +1};
int fy[] = { -1, +1, +0, +0, +1, +1, -1, -1};
void testcase()
{
    int n;
    cin >> n;
    vector<ll>v(n);
 
    vector<ll>lis(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        lis[i] = INF;
    }
    for (int i = 0; i < n; i++)
    {
        ll up = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
        if (lis[up] > v[i])
            lis[up] = v[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (lis[i] != INF)
        {
            cout << i + 1 << endl;
            return;
        }
    }
}
int main()
{
    fastread;
    int test = 1;
    // cin >> test;
    while (test--)testcase();
    return 0;
}