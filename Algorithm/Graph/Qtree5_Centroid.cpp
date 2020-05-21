#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007
#define LN 26
using namespace std;

int n, q, spe[N], sz[N], dd[N], h[N], p[N][LN], pa[N], col[N];
int cntnow = 0;
int root;
vector<int> a[N];
priority_queue<pair<int, int> > luu[N];
void nhap()
{
    scanf("%d", &n);
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
int get(int u)
{
    if (luu[u].empty()) return maxc;
    while (!luu[u].empty())
    {
        int v = luu[u].top().S;
        int d = -luu[u].top().F;
        if (!col[v]) luu[u].pop();
        else return d;
    }
}
void update(int u)
{
    col[u] = !col[u];
    if (!col[u])
    {
        cntnow--;
        return;
    }
    cntnow++;
    int id = u;
    while (u)
    {
        int x = dis(u, id);
        luu[u].push(mp(-x, id));
        u = pa[u];
    }
}
int query(int u)
{
    int res = maxc, id = u;
    while (u)
    {
        res = min(res, get(u) + dis(u, id));
        u = pa[u];
    }
    return res;
}
void solve()
{
    root = centroid(1);
    memset(dd, 0, sizeof dd);
    DFS(root);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int type, u;
        scanf("%d %d", &type, &u);
        if (type == 0) update(u);
        else
        {
            if (cntnow == 0) printf("-1\n");
            else printf("%d\n", query(u));
        }
        //cerr<<luu[1].top().F<<" "<<luu[1].top().S<<endl;
    }
}
int main()
{
    //srand(time(NULL));
    freopen("INP.TXT", "r", stdin);
    nhap();
    solve();
}
