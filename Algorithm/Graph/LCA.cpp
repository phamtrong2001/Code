#include <bits/stdc++.h>
#define MAX(x, y) if (x < y) x = y;
#define MIN(x, y) if (x > y) x = y;
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define MOD 1000000007
#define BASE 97
#define maxn 1000006

using namespace std;

int n, k, m, dd[maxn], dem[maxn], p[maxn][20], h[maxn];
vector <int> a[maxn];

void DFS(int u)
{
    for (int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i];
        if (dd[v]) continue;
        dd[v] = 1;
        h[v] = h[u] + 1;
        p[v][0] = u;
        for (int j = 1; j < 20 ; j++)
            p[v][j] = p[pr[v][j-1]][j-1];
        DFS(v);
    }
}

int lca( int u, int v)
{
    if (h[u] < h[v]) swap (u, v);

    int d = h[u] - h[v];
    for (int i = 19; i >= 0; i--)
        if ((d >> i) & 1) u = p[u][i];
    if (u == v) return u;

    for (int i = 19; i >= 0; i--)
        if (p[u][i]!=p[v][i])
        {
            u= pr[u][i];
            v= pr[v][i];
        }
    return p[u][0];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("LCA.inp","r",stdin);
    freopen("LCA.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        a[u].PB(v);
        a[v].PB(u);
    }
    dd[1] = 1;
    DFS(1);
}
