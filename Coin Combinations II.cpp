 #include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastread  ios_base::sync_with_stdio(false),cin.tie(NULL)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
ll dp[1000009];
vector<ll>v;
ll n;
 
void testcase()
{
      cin >> n ;
      dp[0] = 1;
      ll x; cin >> x;
      vector<ll>v(n); for(auto &x : v) cin >> x;
      dp[0] = 1;
      for(int i=0;i<n;i++)
      {
      	  for(int j=0;j<=x-v[i];j++)
      	  {
      	  	  dp[j+v[i]] = (dp[j+v[i]] + dp[j])%mod;
      	  }
      	 
      }
      cout<<dp[x]<<endl;
     
     
     
 
 
}
int main()
{
    fastread;
    int test = 1; 
    while (test--)testcase();
    return 0;
}
