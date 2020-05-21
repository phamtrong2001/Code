#include <bits/stdc++.h>
#define N 100005
#define LN 25
#define mp make_pair
#define F first
#define S second
#define PB push_back

using namespace std;

int n, spe[N], sz[N], tin[N], tout[N], ver[N], tt, h[N], p[N][LN], res[N], cnt[N];
vector<int> a[N];
vector<pair<int, int> > query[N];

void nhap()
{
    scanf("%d", &n);
    n++;
    for (int v = 2; v <= n; v++)
    {
        int u; scanf("%d", &u); u++;
        a[u].PB(v);
    }
}
void DFS1(int u)
{
    spe[u] = 0; sz[u] = 1;
    tin[u] = ++tt;
    ver[tt] = u;
    for (auto v : a[u])
    {
        h[v] = h[u] + 1;
        p[v][0] = u;
        for (int i = 1; i < LN; i++) p[v][i] = p[p[v][i-1]][i-1];
        DFS1(v);
        if (sz[v] > sz[spe[u]]) spe[u] = v;
        sz[u] += sz[v];
    }
    tout[u] = tt;
}
void DFS2(int u, bool keep)
{
    for (auto v : a[u])
        if (v != spe[u])
            DFS2(v, 0);
    if (spe[u])
        DFS2(spe[u], 1);
    for (auto v : a[u])
        if (v != spe[u])
            for (int x = tin[v]; x <= tout[v]; x++)
            {
                int w = ver[x];
                cnt[h[w]]++;
            }
    cnt[h[u]]++;
    for (auto z : query[u])
    {
        int x = z.F;
        int id = z.S;
        res[id] = cnt[x];
    }
    if (keep == 0)
        for (int x = tin[u]; x <= tout[u]; x++)
        {
            int w = ver[x];
            cnt[h[w]]--;
        }
}
void solve()
{
    DFS1(1);
    int m; scanf("%d", &m);
    for (int i = 1; i <= m; i++) res[i] = 1;
    for (int i = 1; i <= m; i++)
    {
        int v, mm; scanf("%d %d", &v, &mm);
        v++;
        int x = h[v];
        for (int j = LN-1; j >= 0; j--)
            if ((mm >> j) & 1) v = p[v][j];
        if (v > 1) query[v].PB(mp(x, i));
    }
    DFS2(1, 0);
    for (int i = 1; i <= m; i++) printf("%d ", res[i]-1);
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    nhap();
    solve();
}
