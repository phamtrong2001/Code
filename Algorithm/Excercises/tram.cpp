/******** Kho kinh nguoi ********/
#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 100005
#define task "tram"

using namespace std;

int m, n, par[maxn][20], h[maxn], root[maxn], res = 0;

vector <int> a[maxn];

bool dd[maxn];

void DFS(int u)
{
    for (int &v : a[u])
    {
        if (par[u][0] == v) continue;
        par[v][0] = u;
        h[v] = h[u] + 1;
        DFS(v);
    }
}

void RMQ()
{
    for (int j = 1; j <= 17; j++)
        for (int i = 1; i <= n; i++)
            par[i][j] = par[par[i][j-1]][j-1];
}

int LCA(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];
    for (int i = 17; i >= 0; i--)
        if ((delta >> i) & 1) u = par[u][i];
    if (u == v) return u;
    for (int i = 17; i >= 0; i--)
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    return par[u][0];
}

int get_root(int u)
{
    return (root[u] ? root[u] = get_root(root[u]) : u);
}

void calc (int u, int p)
{
    int r = get_root(p);
    u = get_root(u);
    while (h[u] > h[r])
    {
        root[u] = r;
        dd[u] = 1;
        u = get_root(par[u][0]);
    }
}

void solve(int u, int v)
{
    //memset(root, 0, sizeof (root));
    int p = LCA(u, v);
    calc(u, p);
    calc(v, p);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].PB(v);
        a[v].PB(u);
    }
    h[1] = 0;
    DFS(1);
    RMQ();
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        solve(u, v);
    }
    for (int u = 1; u <= n; u++)
        if (dd[u]) res++;
    cout << n-res-1;
    return 0;
}
