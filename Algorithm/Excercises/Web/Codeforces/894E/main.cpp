#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1000005
#define maxc 1000000007
#define ll long long

using namespace std;

ll n, m, low[N], indexx[N], dp[N], s[N], s1[N], tt, scc, belong[N], dd[N];
ll in[N], b[N];
stack<ll> st;
vector<pii> a[N], g[N];

ll calc(ll x)
{
    ll p = upper_bound(s, s+N, x) - s;
    return p*x - s1[p-1];
}

void visit(ll u)
{
    low[u] = indexx[u] = ++tt;
    st.push(u);
    for (auto z : a[u])
    {
        ll v = z.F;
        if (indexx[v]) low[u] = min(low[u], indexx[v]);
        else
        {
            visit(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == indexx[u])
    {
        scc++; ll v = 0;
        while (v != u)
        {
            v = st.top(); st.pop();
            low[v] = indexx[v] = maxc;
            belong[v] = scc;
        }
    }
}

ll DFS(ll u)
{
    if (dd[u]) return dp[u];
    dd[u] = 1;
    ll ans = b[u];
    for (auto z : g[u])
    {
        ll v = z.F;
        ll w = z.S;
        ans = max(ans, b[u] + w + DFS(v));
    }
    return dp[u] = ans;
}
void solve()
{
    for (ll u = 1; u <= n; u++)
        if (indexx[u] == 0) visit(u);
    for (ll u = 1; u <= n; u++)
        for (auto z : a[u])
        {
            ll v = z.F;
            ll w = z.S;
            if (belong[u] == belong[v]) b[belong[u]] += calc(w);
            else
            {
                g[belong[u]].PB(mp(belong[v], w));
                in[belong[v]]++;
            }
        }
    ll st; cin >> st;
    cout <<DFS(belong[st]);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    cin >> n >> m;
    for (ll i = 1; i < N; i++)
    {
        s[i] = s[i-1] + i;
        s1[i] = s1[i-1] + s[i];
    }
    for (ll i = 1; i <= m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        a[u].PB(mp(v, w));
    }
    solve();
}
