#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[2][1000002];
 
int main()
{
    ll N, X;
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> N >> X;
    ll ar[101];
    for (int i = 1; i <= N; i++)
    {
        cin >> ar[i];
    }
    for (int i = X; i >= 0; i--)
        dp[(N + 1) % 2][i] = 1000002;
    dp[(N + 1) % 2][0] = 0;
    for (int i = N; i >= 1; i--)
    {
        for (int j = 0; j <= X; j++)
            dp[i % 2][j] = dp[(i + 1) % 2][j];
 
        for (int j = 1; j <= X; j++)
        {
            if (j - ar[i] >= 0)
            {
                dp[i % 2][j] = min(dp[i % 2][j], dp[i % 2][j - ar[i]] + 1);
            }
        }
    }
    if (dp[1][X] >= 1000002)
        dp[1][X] = -1;
    cout << dp[1][X] << endl;
    return 0;
}
