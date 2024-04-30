#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
int main()
{
    ll n, x;
    cin >> n >> x;
    vector<ll>v(n + 1, 0);
    vector<pair<ll, ll>>v_sum;
    vector<pair<ll, ll>>vp;
    ll cnt = 0;
    for (int i = 1; i <= n; i++)cin >> v[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            ll sum = v[i] + v[j];
            v_sum.push_back({sum, cnt});
            vp.push_back({i, j});
            cnt++;
        }
    }
    map<ll, ll>chker;
    sort(v_sum.begin(), v_sum.end());
    vector<ll>vv;
    for (auto x : v_sum)
        vv.pb(x.first);
    for (int i = 0; i < v_sum.size(); i++)
    {
        ll val = v_sum[i].first;
        ll id = v_sum[i].second;
        ll dorkar = x - val;
        if (dorkar > 0)
        {
            ll low  = lower_bound(vv.begin(), vv.end(), dorkar) - vv.begin();
            if (low < vv.size())
            {
                if (vv[low] == dorkar)
                {
                    ll id2 = v_sum[low].second;
                    ll ar[] = {vp[id].first, vp[id].second, vp[id2].first, vp[id2].second};
                    sort(ar, ar + 4);
                    bool flag = true;
                    for (int i = 1; i < 4; i++)
                    {
                        if (ar[i] == ar[i - 1])flag = false;
                    }
                    if (flag)
                    {
                        for (auto x : ar)
                        {
                            cout << x << ' ';
                        }
                        cout << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}