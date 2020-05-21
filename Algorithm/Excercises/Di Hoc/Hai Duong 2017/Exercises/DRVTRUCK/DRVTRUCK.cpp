#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 500005

using namespace std;

ll n, k, d1[N], d2[N], f1[N], f2[N], f1a[N], wpa[N], dd[N], res[N];
vector<pii> a[N];

void DFS1(ll u, ll p)
{
    for (auto z : a[u])
    {
        ll v = z.F;
        ll w = z.S;
        if (v == p) continue;
        DFS1(v, u);
        wpa[v] = w;
        dd[u] += dd[v];
        if (dd[v])
        {
            d1[u] += d1[v] + w;
            if (f1[u] <= f1[v] + w)
            {
                f1a[u] = f1[u];
                f1[u] = f1[v] + w;
            }
            else if (f1a[u] < f1[v] + w) f1a[u] = f1[v] + w;
        }
    }
}
void DFS2(ll u, ll p)
{
    if (p != -1 && dd[u] != k)
    {
        ll w = wpa[u];
        if (dd[u]) d2[u] = d2[p] + d1[p] - d1[u];
        else d2[u] = d2[p] + d1[p] - d1[u] + w;
        f2[u] = f2[p] + w;
        if (f1[p] == f1[u] + w) f2[u] = max(f2[u], f1a[p] + w);
        else f2[u] = max(f2[u], f1[p] + w);
    }
    for (auto z : a[u])
    {
        ll v = z.F;
        if (v == p) continue;
        DFS2(v, u);
    }
    res[u] = 2*(d1[u] + d2[u]) - max(f1[u], f2[u]);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("DRVTRUCK.INP", "r", stdin);
    freopen("DRVTRUCK.OUT", "w", stdout);
    cin >> n >> k;
    for (ll i = 1; i < n; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        a[u].PB(mp(v, w));
        a[v].PB(mp(u, w));
    }
    for (ll i = 1; i <= k; i++)
    {
        ll u; cin >> u;
        dd[u] = 1;
        //f1[u] = 1;
    }
    DFS1(1, -1);
    DFS2(1, -1);
    for (ll i = 1; i <= n; i++) cout <<res[i]<<'\n';
}
