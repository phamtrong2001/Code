#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 200005
#define LN 25
#define maxc 1000000007

using namespace std;

ll n, L, h[N], p[N][LN], s[N];
vector<pii> a[N];

void DFS(ll u, ll pa)
{
    for (auto z : a[u])
    {
        ll v = z.F;
        ll w = z.S;
        if (v == pa) continue;
        h[v] = h[u] + w;
        p[v][0] = u;
        for (ll i = 1; i < LN; i++) p[v][i] = p[p[v][i-1]][i-1];
        DFS(v, u);
    }
}
void solve()
{
    for (ll u = 1; u <= n; u++)
    {
        ll v = u;
        for (ll i = LN-1; i >= 0; i--)
            if (h[u] - h[p[v][i]] <= L && p[v][i] != 0) v = p[v][i];
        s[u]++;
        if (v != 1) s[p[v][0]]--;
    }
}
void DFS2(ll u, ll pa)
{
    for (auto z : a[u])
    {
        ll v = z.F;
        DFS2(v, u);
        s[u] += s[v];
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("RUNAWAY.INP", "r", stdin);
    freopen("RUNAWAY.OUT", "w", stdout);
    cin >> n >> L;
    for (ll v = 2; v <= n; v++)
    {
        ll u, w; cin >> u >> w;
        a[u].PB(mp(v, w));
    }
    DFS(1, -1);
    solve();
    DFS2(1, -1);
    for (ll i = 1; i <= n; i++) cout <<s[i]<<'\n';
}
