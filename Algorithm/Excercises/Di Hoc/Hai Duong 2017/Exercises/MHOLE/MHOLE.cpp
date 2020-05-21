#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 300005
#define maxc 1000000007

using namespace std;

ll n, visit[N], dp1[N], dp2[N], dpp1[N], dpp2[N], h[N], res = maxc;
vector<ll> a[N], d1[N];

void nhap()
{
    cin >> n;
    for (ll i = 1; i < n; i++)
    {
        ll u, v; cin >> u >> v;
        a[u].PB(v);
        a[v].PB(u);
    }
    for (ll i = 1; i <= n; i++) d1[i].PB(0), d1[i].PB(0), d1[i].PB(0);
}
void calc1(ll u, ll p)
{
    for (auto v : a[u])
    {
        if (v == p) continue;
        h[v] = h[u] + 1;
        calc1(v, u);
        dpp1[u] = max(dpp1[u], dpp1[v]);
        d1[u].PB(dp1[v]+1);
    }
    sort(d1[u].begin(), d1[u].end());
    reverse(d1[u].begin(), d1[u].end());
    dpp1[u] = max(dpp1[u], d1[u][0] + d1[u][1]);
    dp1[u] = d1[u][0];
}
void calc2(ll u, ll p)
{
    if (p != -1)
    {
        dp2[u] = dp2[p] + 1;
        if (d1[u][0] + 1 == d1[p][0]) dp2[u] = max(dp2[u], d1[p][1] + 1);
        else dp2[u] = max(dp2[u], d1[p][0]+1);
        dpp2[u] = max(dpp2[p], dp2[p] + 1);
        if (d1[u][0] + 1 == d1[p][0]) dpp2[u] = max(dpp2[u], d1[p][1] + d1[p][2]);
        else if (d1[u][0] + 1 == d1[p][1]) dpp2[u] = max(dpp2[u], d1[p][0] + d1[p][2]);
        else dpp2[u] = max(dpp2[u], d1[p][0] + d1[p][1]);
        dpp2[u] = max(dpp2[u], dpp2[p]);
    }

    d1[u].PB(dp2[u]);
    sort(d1[u].begin(), d1[u].end());
    reverse(d1[u].begin(), d1[u].end());
    for (auto v : a[u])
    {
        if (v == p) continue;
        calc2(v, u);
    }
    if (p == -1) return;
    ll z1 = (dpp1[u] + 2)/2;
    ll z2 = (dpp2[p] + 2)/2;
    res = min(res, max(z1 + z2, max(dpp1[u], dpp2[u])));
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("MHOLE.INP", "r", stdin);
    freopen("MHOLE.OUT", "w", stdout);
    nhap();
    calc1(1, -1);
    calc2(1, -1);
    cout <<res;
}
