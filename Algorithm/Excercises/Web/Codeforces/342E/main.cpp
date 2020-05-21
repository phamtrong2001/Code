#include <bits/stdc++.h>
#define PB push_back
#define maxc 1000000007
#define N 100005
#define LN 26

using namespace std;

int n, m, spe[N], sz[N], dd[N], luu[N], h[N], p[N][LN], pa[N];
int root;
vector<int> a[N];
void nhap()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; i++)
    {
        int u, v; scanf("%d %d", &u, &v);
        a[u].PB(v);
        a[v].PB(u);
    }
}
void dfsCentroid(int u)
{
    spe[u] = 0; sz[u] = 1;
    dd[u] = 1;
    for (auto v : a[u])
    {
        if (dd[v]) continue;
        dfsCentroid(v);
        if (sz[v] > sz[spe[u]]) spe[u] = v;
        sz[u] += sz[v];
    }
    dd[u] = 0;
}
void DFS(int u)
{
    dd[u] = 1;
    for (auto v : a[u])
    {
        if (dd[v]) continue;
        h[v] = h[u] + 1;
        p[v][0] = u;
        for (int i = 1; i < LN; i++) p[v][i] = p[p[v][i-1]][i-1];
        DFS(v);
    }
}
int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int diff = h[u] - h[v];
    for (int i = 0; i < LN; i++)
        if ((diff >> i) & 1) u = p[u][i];
    if (u == v) return u;
    for (int i = LN-1; i >= 0; i--)
        if (p[u][i] != p[v][i])
        {
            u = p[u][i];
            v = p[v][i];
        }
    return p[u][0];
}
int dis(int u, int v)
{
    return h[u] + h[v] - 2*h[LCA(u, v)];
}
int centroid(int u)
{
    dfsCentroid(u);
    int siz = sz[u] / 2;
    while (sz[spe[u]] > siz)
        u = spe[u];
    dd[u] = 1;
    for (auto v : a[u])
    {
        if (dd[v]) continue;
        int x = centroid(v);
        pa[x] = u;
    }
    return u;
}
void update(int u)
{
    int id = u;
    while (u)
    {
        luu[u] = min(luu[u], dis(u, id));
        u = pa[u];
    }
}
int query(int u)
{
    int res = maxc, id = u;
    while (u)
    {
        res = min(res, luu[u] + dis(u, id));
        u = pa[u];
    }
    return res;
}
void solve()
{
    root = centroid(1);
    memset(dd, 0, sizeof dd);
    for (int i = 1; i <= n; i++) luu[i] = maxc;
    DFS(root);
    update(1);
    for (int i = 1; i <= m; i++)
    {
        int type, u; scanf("%d %d", &type, &u);
        if (type == 1) update(u);
        else printf("%d\n", query(u));
    }
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    nhap();
    solve();
}
