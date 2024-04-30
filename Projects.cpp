#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
vector< pair<ll, ll> > pr[400006];
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll n; cin >> n;
    set<ll>st;
    vector <  pair<pair<ll, ll>, ll> >vp;
    for (int i = 1; i <= n; i++)
    {
        ll l, r, p;
        cin >> l >> r >> p;
        vp.pb({{l, r}, p});
        st.insert(l);
        st.insert(r);
    }
    map<ll, ll>mp;
    ll id = 0;
    for (auto x : st)
    {
        mp[x] = ++id;
    }
    for (auto x : vp)
    {
        pr[mp[x.first.second]].pb({mp[x.first.first], x.second});
    }
    vector<ll>dp(id + 2, 0);
    for (int i = 1; i <= id; i++)
    {
        dp[i] = dp[i - 1];
        for (int j = 0; j < pr[i].size(); j++)
        {
            dp[i] = max(dp[i], dp[pr[i][j].first - 1] + pr[i][j].second);
        }
    }
    cout << dp[id] << endl;
    return 0;
 
}