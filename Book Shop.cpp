#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
int dp[1005][100004];
vector<pair<int, int>>vp;
vector<int>v;
int main()
{
    int n, x;
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        int pr; cin >> pr;
        v.push_back(pr);
    }
    for (int i = 0; i < n; i++)
    {
        int pg; cin >>  pg;
        vp.push_back({v[i], pg});
    }
 //   sort(vp.begin(), vp.end());
    for (int i = 0; i < n; i++)
    {
        int pr = vp[i].first;
        int pg = vp[i].second;
        for (int j = 0; j <= x; j++)
        {
            if (j >= pr)
                dp[i + 1][j] = max(dp[i][j], dp[i][j - pr] + pg);
            else
                dp[i + 1][j] = dp[i][j];
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}
