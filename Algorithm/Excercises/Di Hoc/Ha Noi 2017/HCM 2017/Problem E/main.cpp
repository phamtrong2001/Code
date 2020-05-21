#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 2005
#define MM 3000005
#define maxc 1ll*4000000000000000007

using namespace std;

ll m, n, k, s, t, flow[N], tr[N], maxflow, cnt;
ll d[N], mincost, weightMax;
vector<ll> a[N];

struct edge
{
    ll u, v, c, f, w;
    edge(ll u=0, ll v=0, ll c=0, ll f=0, ll w=0) : u(u), v(v), c(c), f(f), w(w) {}
}e[MM], ee[MM];

void add_edge(ll u, ll v, ll c, ll w)
{
    a[u].PB(cnt);
    e[cnt++] = edge(u, v, c, 0, w);
    a[v].PB(cnt);
    e[cnt++] = edge(v, u, 0, 0, -w);
}
bool IJK()
{
    priority_queue<pair<long long, ll> > q;
    for (ll i = 1; i <= m+n+2; i++) d[i] = maxc;
    d[s] = 0;
    flow[s] = maxc;
    q.push(mp(0, s));
    while (!q.empty())
    {
        ll u = q.top().S;
        ll l = -q.top().F;
        q.pop();
        if (d[u] < l || flow[u] == 0) continue;
        for (auto id : a[u])
        {
            ll v = e[id].v;
            ll c = e[id].c;
            ll f = e[id].f;
            ll w = e[id].w;
            if (c == f) continue;
            if (d[v] > l + w)
            {
                d[v] = l + w;
                flow[v] = min(flow[u], c - f);
                q.push(mp(-d[v], v));
                tr[v] = id;
            }
        }
    }
    return (flow[t] > 0 && d[t] != maxc);
}
void tang()
{
    ll v = t, delta = flow[t];
    while (v != s)
    {
        ll id = tr[v];
        e[id].f += delta;
        e[id^1].f -= delta;
        v = e[id].u;
    }
}

void setup()
{
    cin >> m >> n >> k;
    s = m+n+1; t = m+n+2;
    for (ll i = 1; i <= k; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        swap(u, v);
        v += m;
        ee[i] = edge(u, v, 0, 0, w);
        weightMax = max(weightMax, 1ll*w);
    }
    for (ll i = 1; i <= k; i++)
    {
        ll u = ee[i].u;
        ll v = ee[i].v;
        ll w = weightMax - ee[i].w;
        add_edge(u, v, 1, w);
    }
    for (ll i = 1; i <= m; i++) add_edge(s, i, 1, 0);
    for (ll i = 1; i <= n; i++) add_edge(i+m, t, 1, 0);

}

void solve()
{
    while (IJK())
    {
        mincost += flow[t]*d[t];
        maxflow += flow[t];
        tang();
    }
    cout <<-mincost + 1ll*weightMax*maxflow <<endl<<maxflow<<endl;
    for (ll i = 0; i <= 2*k-2; i+=2)
        if (e[i].f > 0) cout <<e[i].v-m<<" "<<e[i].u<<endl;
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    setup();
    solve();
}
