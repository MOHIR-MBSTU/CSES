#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string a, b;
ll dp[20][2][2][2][10];
ll func(int pos, int boro, int choto, int isst, int lastd)
{
    if (pos >= b.size())
        return 1;
    if (dp[pos][boro][choto][isst][lastd] != -1)
        return dp[pos][boro][choto][isst][lastd];
 
    int hi = 9, low = 0;
    if (!boro)low = a[pos] - '0';
    if (!choto) hi = b[pos] - '0';
 
    ll ans = 0;
    for (int i = low; i <= hi; i++)
    {
        if (isst and i == lastd)continue;
        ans += func(pos + 1, boro | (i > low), choto | (i < hi), isst | (i > 0), i);
    }
    return dp[pos][boro][choto][isst][lastd] = ans;
 
}
 
int main()
{
    ll num, num2;
    cin >> num;
    cin >> num2;
    if (num > num2)swap(num, num2);
    ll value = num;
    a = to_string(num);
    b = to_string(num2);
    while (a.size() < b.size())
        a = '0' + a;
    memset(dp, -1, sizeof dp);
    cout << func(0, 0, 0, 0, 0) << endl;
    return 0;
}