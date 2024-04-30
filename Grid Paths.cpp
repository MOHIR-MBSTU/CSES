#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastread  ios_base::sync_with_stdio(false),cin.tie(NULL)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define pb push_back
#define ha cout<<"YES\n"
#define na cout<<"NO\n"
#define co(x) cout<<x<<'\n'
#define vi vector<ll>
#define in(v) for(auto &x : v) cin >> x
#define srt(v) sort(v.begin(),v.end())
#define mod 1000000007
#define INF 1e18
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef pair<int, int> pii;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> T;
int fx[] = { +0, +0, +1, -1, -1, +1, -1, +1};
int fy[] = { -1, +1, +0, +0, +1, +1, -1, -1};
 
 
void testcase()
{
     int n; cin >> n;
     int grid[n+2][n+3];
     memset(grid,0,sizeof grid);
     for(int i=1;i<=n;i++)
     {
        for(int j=1;j<=n;j++)
        {
            char c; cin >> c;
            if(c=='*')grid[i][j] = 1;
        }
     }
     long long dp[n+3][n+3];
     memset(dp,0,sizeof dp);
     if(grid[1][1]==0)
     dp[1][1]=1;
     for(int i=1;i<=n;i++)
     {
        for(int j=1;j<=n;j++)
        {
            if(!grid[i][j])
            {
                if(grid[i][j-1]==0 and dp[i][j-1])
                    dp[i][j] += dp[i][j-1];
                if(grid[i-1][j]==0 and dp[i-1][j])
                    dp[i][j] += dp[i-1][j];
                dp[i][j] %= mod;
            }
        }
     }
     cout<<dp[n][n]<<endl;
      
}
int main()
{
    fastread;
    int test = 1;  
    while (test--)testcase();
    return 0;
}
