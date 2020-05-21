#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define ll long long
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1ll*1000000000000000007

using namespace std;

ll n, wpa[N], ds[N], s[N], sz[N], ds1[N], s1[N], sz1[N], res = maxc;
vector<pii> a[N];
vector<ll> ans;

void DFS1(ll u, ll p)
{
    sz[u] = 1;
    for (auto z : a[u])
    {
        ll v = z.F;
        ll w = z.S;
        if (v == p) continue;
        DFS1(v, u);
        wpa[v] = w;
        ds[u] = ds[u] + ds[v] + 2*w*s[v] + w*w*sz[v];
        s[u] = s[u] + s[v] + w*sz[v];
        sz[u] = sz[u] + sz[v];
    }
}
void DFS2(ll u, ll p)
{
    sz1[u] = n;
    if (p != -1)
    {

        ll w = wpa[u];
        ds1[u] = ds1[p] + ds[p] - ds[u] - 2*w*s[u] - w*w*sz[u] + 2*w*(s1[p]-s[u] - w*sz[u]) + w*w*(n-sz[u]);
        s1[u] = s[u] + (s1[p] - s[u] - w*sz[u]) + w*(n-sz[u]);;
    }
    else s1[u] = s[u];
    for (auto z : a[u])
    {
        ll v = z.F;
        ll w = z.S;
        if (v == p) continue;
        DFS2(v, u);
    }
    if (res > ds1[u] + ds[u])
    {
        ans.clear();
        res = ds1[u] + ds[u];
        ans.PB(u);
    }
    else if (res == ds1[u] + ds[u]) ans.PB(u);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("FAS.INP", "r", stdin);
    freopen("FAS.OUT", "w", stdout);
    cin >> n;
    for (ll i = 1; i < n; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        a[u].PB(mp(v, w));
        a[v].PB(mp(u, w));
    }
    DFS1(1, -1);
    DFS2(1, -1);
    cout <<ans.size()<<endl;
    sort(ans.begin(), ans.end());
    for (auto x : ans) cout <<x<<" ";
}
