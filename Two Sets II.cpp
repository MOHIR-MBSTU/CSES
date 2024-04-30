#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 62505
#define mod 1000000007
 
 
ll dp[505][mx];
ll value = 0;
ll val = 0;
ll n;
ll func(ll pos, ll sum)
{
  if (pos > n)return 0;
  if (value - sum == sum)return 1;
  if (value - sum < sum)return 0;
  if (dp[pos][sum] != -1)
    return dp[pos][sum];
  ll ans =  0;
  ans += func(pos + 1, sum + pos);
  ans += func(pos + 1, sum);
  return dp[pos][sum] = ans % mod;
 
}
int main()
{
  cin >> n;
  memset(dp, -1, sizeof dp);
  value = (n * (n + 1)) / 2;
  ll ans = func(1, 0);
  cout << ans << endl;
 
 
}
