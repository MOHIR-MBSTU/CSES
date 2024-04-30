#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m;
ll dp[200002][102] ;
vector<ll>v(200003);
#define mod 1000000007
 
 
ll func(ll pos, ll num )
{
  if (pos >= n or  num > m or (num <= 0 and pos))
  {
    return (pos == n and num >= 1 and num <= m);
  }
  if (dp[pos][num] != -1)
    return dp[pos][num];
  ll ans = 0;
  if (v[pos] == 0)
  {
    if (pos == 0)
    {
      for (int j = 1; j <= m; j++)
      {
 
        ans += func(pos + 1, j);
 
      }
    }
    else
    {
 
      ans += func(pos + 1, num - 1);
 
 
      ans += func(pos + 1, num);
 
      ans += func(pos + 1, num + 1);
 
    }
  }
  else
  {
    if (pos == 0)
      ans += func(pos + 1, v[pos]);
    else if (abs( num - v[pos]) <= 1ll)
    {
      ans += func(pos + 1, v[pos]);
    }
 
  }
  return dp[pos][num] = ans % mod;
}
int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> v[i];
  memset(dp, -1, sizeof dp);
  cout << func(0, v[0]) << endl;
 
}
 
 
 
