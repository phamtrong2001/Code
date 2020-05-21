/******** Kho kinh nguoi ********/
#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 100005
#define maxh 20
#define task "ants"
#define  pii pair<int, int>

using namespace std;

int n, cha;
long long d[maxn];
int p[maxn][maxh];
vector <pii> ke[maxn];
int h[maxn];

void DFS(int u)
{
    for (pii q : ke[u])
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
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= 17; j++)
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

void nhap()
{
    memset(h, 0, sizeof (h));
    memset(d, 0, sizeof (d));
    for (int i = 0; i < n; i++)
        ke[i].clear();
    for (int u = 1; u < n; u++)
        {
            int v, w;
            cin >> v >> w;
            ke[u].PB(MP(v, w));
            ke[v].PB(MP(u, w));
        }
    DFS(0);
    RMQ();
    int q;
    cin >> q;
    while (q--)
    {
        int s, t;
        cin >> s >> t;
        cha = lca(s, t);
        cout << d[s] + d[t] - 2ll*d[cha] << " ";
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    while (cin >> n)
        {
            if (!n) break;
            nhap();
        }
    return 0;
}
