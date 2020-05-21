/******** Kho kinh nguoi ********/
#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 100005
#define maxh 20
#define task "upgranet"

using namespace std;

long long n, m, root[maxn], p[maxn][maxh], h[maxn];

long long d[maxn], res = 0;

bool dd[maxn];

struct data
{
    int u, v, w;
}ke[maxn];


vector <pair <int, int> > g[maxn];

bool comp(data x, data y)
{
    return x.w > y.w;
}

int get_root(int u)
{
    return (root[u] ? root[u] = get_root(root[u]) : u);
}

void kruskal()
{
    sort(ke+1, ke+m+1, comp);
    for(int i = 1; i <= n; i++) root[i] = 0;
    for (int i = 1; i <= m; i++)
        {
            int p = get_root(ke[i].u);
            int q = get_root(ke[i].v);
            if (p == q) continue;
            root[p] = q;
            g[ke[i].u].PB(MP(ke[i].v, ke[i].w));
            g[ke[i].v].PB(MP(ke[i].u, ke[i].w));
            dd[i] = 1;
        }
}

void DFS(int u)
{
    for (pair <int, int> q : g[u])
    {
        int v = q.F;
        if (p[u][0] == v) continue;
        d[v] = d[u] + q.S;
        p[v][0] = u;
        h[v] = h[u] + 1;
        DFS(v);
    }
}

void RMQ()
{
    for (int j = 1; j <= 17; j++)
        for (int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j-1]][j-1];
}

int lca(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];
    for (int i = 17; i >= 0; i--)
        if ((delta >> i) & 1) u = p[u][i];
    if (u == v) return u;
    for (int i = 17; i >= 0; i--)
        if (p[u][i] != p[v][i])
        {
            u = p[u][i];
            v = p[v][i];
        }
    return p[u][0];
}

long long get_min(int con, int cha)
{
    long long cur = maxc;
    while (con != cha)
    {
        cur = min(cur, d[con] - d[p[con][0]]);
        con = p[p[con][0]][0];
    }
    return cur;
}

void solve()
{
    for (int i = 1; i <= m; i++)
        if (!dd[i])
        {
            int cha = lca(ke[i].u, ke[i].v);
            int m1 = get_min(ke[i].u, cha);
            int m2 = get_min(ke[i].v, cha);
            res += min(m1, m2) - ke[i].w;
        }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> ke[i].u >> ke[i].v >> ke[i].w;
    kruskal();
    h[1] = 0; d[1] = 0;
    DFS(1);
    RMQ();
    solve();
    return 0;
}
