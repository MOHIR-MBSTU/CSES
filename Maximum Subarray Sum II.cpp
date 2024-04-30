#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll>arr(n + 2, 0);
    vector<ll>pr(n + 3, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pr[i] = pr[i - 1] + arr[i];
    }
    multiset<pair<ll, ll>>st;
    ll ans = -1e18;
    for (int i = a; i <= n; i++)
    {
        if (i - a >= 0)
        {
            st.insert({pr[i - a], i - a});
        }
        pair<ll, ll> p;
        for (auto x : st)
        {
            p = x; break;
        }
        ans = max(ans, pr[i] - p.first);
        if (i - b >= 0)
        {
            if (st.find({pr[i - b], i - b}) != st.end())
                st.erase({pr[i - b], i - b});
        }
 
    }
    cout << ans << endl;
    return 0;
 
}