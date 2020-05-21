#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1ll*1000000000000000007

using namespace std;

int n, m;
long long d[N], tr[N], p[N], res;
vector<pii> a[N];
vector<int> path[5];
map<pii, bool> dd;
bool ok[3][N], flag;

void nhap()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        a[u].PB(mp(v, w));
        a[v].PB(mp(u, w));
    }
}
void IJK()
{
    priority_queue<pair<long long, int> >q;
    for (int i = 1; i <= n; i++) d[i] = maxc;
    d[1] = 0;
    q.push(mp(0, 1));
    while (!q.empty())
    {
        int u = q.top().S;
        ll l = -q.top().F;
        q.pop();
        if (d[u] < l) continue;
        for (auto z : a[u])
        {
            int v = z.F;
            if (z.S == 0) continue;
            ll w = z.S + p[u] - p[v];
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push(mp(-d[v], v));
                tr[v] = u;
            }
        }
    }
}

void solve()
{
    IJK();
    if (d[n] == maxc) flag = 1;
    res = d[n];
    for (int u = 1; u <= n; u++)
        if (d[u] != maxc) p[u] += d[u];

    int u = n;
    path[1].PB(n);
    while (u != 1)
    {
        int v = tr[u];
        path[1].PB(v);
        for (int i = 0; i < a[v].size(); i++)
            if (a[v][i].F == u)
                a[v][i].S = 0;
        for (int i = 0; i < a[u].size(); i++)
            if (a[u][i].F == v)
                a[u][i].S = -a[u][i].S;
        u = v;
    }
    IJK();
    if (d[n] == maxc) flag = 1;
    res += d[n] - p[1] + p[n];

    u = n;
    path[2].PB(n);
    while (u != 1)
    {
        int v = tr[u];
        path[2].PB(v);
        u = v;
    }
    if (flag) printf("-1");
    else printf("%lld\n", res);
    reverse(path[1].begin(), path[1].end());
    reverse(path[2].begin(), path[2].end());
}


void truyvet2()
{
    if (flag) return;
    for (int i = 1; i <= n; i++) a[i].clear();

    for (int id = 1; id <= 2; id++)
        for (int i = 0; i < path[id].size()-1; i++)
        {
            int u = path[id][i];
            int v = path[id][i+1];
            dd[mp(u, v)] = 1;
        }
    for (int id = 1; id <= 2; id++)
        for (int i = 0; i < path[id].size()-1; i++)
        {
            int u = path[id][i];
            int v = path[id][i+1];
            if (dd[mp(v, u)]) ok[id][i] = 1;
            if (!ok[id][i]) a[u].PB(mp(v, 1));
        }
    memset(p, 0, sizeof p);
    IJK();
    int u = n;
    path[3].PB(n);
    while (u != 1)
    {
        int v = tr[u];
        path[3].PB(v);
        for (int i = 0; i < a[v].size(); i++)
            if (a[v][i].F == u)
                a[v][i].S = 0;
        for (int i = 0; i < a[u].size(); i++)
            if (a[u][i].F == v)
                a[u][i].S = 0;
        u = v;
    }
    IJK();
    u = n;
    path[4].PB(n);
    while (u != 1)
    {
        int v = tr[u];
        path[4].PB(v);
        u = v;
    }
    for (int i = path[3].size()-1; i >= 0; i--) printf("%d ", path[3][i]);
    for (int i = 1; i < path[4].size(); i++) printf("%d ", path[4][i]);
}
int main()
{
    freopen("WALK.INP", "r", stdin);
    freopen("WALK.OUT", "w", stdout);
    nhap();
    solve();
    truyvet2();
}
