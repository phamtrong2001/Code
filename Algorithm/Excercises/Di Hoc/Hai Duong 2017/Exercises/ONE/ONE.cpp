#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

ll n, d1[N], d2[N], ROOT;
vector<pii> a[N];

void DFS(ll u, ll p)
{
    for (auto z : a[u])
    {
        ll v = z.F;
        ll w = z.S;
        if (v == p) continue;
        DFS(v, u);
        d1[u] = d1[u] + d1[v] + 2*w;
    }
    d2[u] = maxc;
    for (auto z : a[u])
    {
        ll v = z.F;
        ll w = z.S;
        if (v == p) continue;
        d2[u] = min(d2[u], d1[u] - d1[v] - 2*w + d2[v] + w);
    }
    if (d2[u] == maxc) d2[u] = 0;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("ONE.INP", "r", stdin);
    freopen("ONE.OUT", "w", stdout);
    cin >> n >> ROOT;
    for (ll i = 1; i < n; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        a[u].PB(mp(v, w));
        a[v].PB(mp(u, w));
    }
    DFS(ROOT, -1);
    cout <<d2[ROOT];
}
