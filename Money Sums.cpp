#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastread  ios_base::sync_with_stdio(false),cin.tie(NULL)
#define pb push_back
#define ha cout<<"YES\n"
#define na cout<<"NO\n"
#define endl "\n"
#define co(x) cout<<x<<'\n'
#define co2(x,y) cout<<x<<' '<<y<<'\n'
#define f(n) for(int i=0;i<n;i++)
#define srt(v) sort(v.begin(),v.end())
#define mod 1000000007
#define INF 1e18
ll bigmod(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
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
vector<ll>v;
ll n, k;
bool ans[100002];
 
void testcase()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll val; cin >> val;
        v.pb(val);
    }
    ans[0] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 100000; j >= 0; j--)
        {
            if (ans[j])
                ans[j + v[i]] = 1;
        }
    }
    vector<int>v;
    for (int i = 1; i <= 100000; i++)
    {
        if (ans[i])v.pb(i);
    }
    cout << v.size() << endl;
    for (auto x : v)
        cout << x << ' ';
    cout << endl;
}
int main()
{
    fastread;
    ll test = 1;
    while (test--)testcase();
    return 0;
}
