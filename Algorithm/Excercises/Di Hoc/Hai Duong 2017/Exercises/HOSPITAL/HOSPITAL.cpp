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

ll n, val[N], sz[N], S, res = maxc, ans;
vector<ll> a[N];

void DFS(ll u, ll p)
{
    ll curAns = 0;
    for (auto v : a[u])
    {
        if (v == p) continue;
        DFS(v, u);
        sz[u] += sz[v];
        curAns = max(curAns, sz[v]);
    }
    curAns = max(curAns, S - sz[u] - val[u]);
    if (curAns < res)
    {
        res = curAns;
        ans = u;
    }
    sz[u] += val[u];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("HOSPITAL.INP", "r", stdin);
    freopen("HOSPITAL.OUT", "w", stdout);
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> val[i], S += val[i];
    for (ll i = 1; i < n; i++)
    {
        ll u, v; cin >> u >> v;
        a[u].PB(v);
        a[v].PB(u);
    }
    DFS(1, -1);
    cout <<ans;
}
