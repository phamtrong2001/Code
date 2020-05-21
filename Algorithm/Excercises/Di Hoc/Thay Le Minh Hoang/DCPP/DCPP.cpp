#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1005
#define MM 40005
#define maxc 1ll*1000000000000000007
#define MOD 1000000007
using namespace std;

int n, m, s, t, deg[N], tr[N];
long long d[N], maxflow, mincost, flow[N];
vector<int> a[N];

struct edge
{
    int u, v, c, f, w;
    edge(int u=0, int v=0, int c=0, int f=0, int w=0) : u(u), v(v), c(c), f(f), w(w) {}
}e[MM];

int cnt;
void add_edge(int u, int v, int c, int w)
{
    a[u].PB(cnt);
    e[cnt++] = edge(u, v, c, 0, w);
    a[v].PB(cnt);
    e[cnt++] = edge(v, u, 0, 0, -w);
}
void nhap()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        mincost += w;
        add_edge(u, v, MOD, w);
        deg[u]++;
        deg[v]--;
    }
}
bool IJK()
{
    priority_queue<pair<long long, int> > q;
    for (int i = 1; i <= n+2; i++) d[i] = maxc;
    d[s] = 0;
    flow[s] = maxc;
    q.push(mp(0, s));
    while (!q.empty())
    {
        int u = q.top().S;
        ll l = -q.top().F;
        q.pop();
        if (d[u] < l || flow[u] == 0) continue;
        for (auto id : a[u])
        {
            int v = e[id].v;
            int c = e[id].c;
            int f = e[id].f;
            int w = e[id].w;
            if (c == f) continue;
            if (d[v] > l + w)
            {
                d[v] = l + w;
                flow[v] = min(flow[u], 1ll*c - f);
                q.push(mp(-d[v], v));
                tr[v] = id;
            }
        }
    }
    return (flow[t] > 0 && d[t] != maxc);
}
void tang()
{
    int v = t, delta = flow[t];
    while (v != s)
    {
        int id = tr[v];
        e[id].f += delta;
        e[id^1].f -= delta;
        v = e[id].u;
    }
}

void buildGraph()
{
    s = n+1;
    t = n+2;
    for (int i = 1; i <= n; i++)
        if (deg[i] < 0) add_edge(s, i, -deg[i], 0);
        else if (deg[i] > 0) add_edge(i, t, deg[i], 0);
}
void maxFlowMinCost()
{
    while (IJK())
    {
        //maxflow += flow[t];
        mincost += flow[t]*d[t];
        tang();
    }
}
void solve()
{
    buildGraph();
    maxFlowMinCost();
    printf("%lld", mincost);
}

int main()
{
    freopen("DCPP.INP", "r", stdin);
    freopen("DCPP.OUT", "w", stdout);
    nhap();
    solve();
}
