#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, q, ROOT, col[N], sz[N], spe[N], tin[N], tout[N], ver[N], tt, tt1, dem[N], curAns, res[N];
map<int, int> ma;
vector<int> a[N];

void dfsPre(int u, int p)
{
    sz[u] = 1, spe[u] = 0;
    tin[u] = ++tt;
    ver[tt] = u;
    for (auto v : a[u])
    {
        if (v == p) continue;
        dfsPre(v, u);
        if (sz[spe[u]] < sz[v]) spe[u] = v;
        sz[u] += sz[v];
    }
    tout[u] = tt;
}
void upd(int x, int val)
{
    if (dem[x]) curAns--;
    dem[x] += val;
    if (dem[x]) curAns++;
}
void DFS(int u, int p, bool keep)
{
    for (auto v : a[u])
        if (v != p && v != spe[u])
            DFS(v, u, 0);
    if (spe[u])
        DFS(spe[u], u, 1);
    for (auto v : a[u])
        if (v != p && v != spe[u])
            for (int i = tin[v]; i <= tout[v]; i++)
                upd(col[ver[i]], 1);
    upd(col[u], 1);
    res[u] = curAns;
    if (!keep)
        for (int i = tin[u]; i <= tout[u]; i++)
            upd(col[ver[i]], -1);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("COLTREE.INP", "r", stdin);
    freopen("COLTREE.OUT", "w", stdout);
    cin >> n >> q >> ROOT;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        a[u].PB(v);
        a[v].PB(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> col[i];
        if (!ma[col[i]]) ma[col[i]] = ++tt1;
        col[i] = ma[col[i]];
    }
    dfsPre(ROOT, -1);
    DFS(ROOT, -1, 0);
    while (q--)
    {
        int u; cin >> u;
        cout <<res[u]<<'\n';
    }
}
