#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1000005
#define maxc 1000000007

using namespace std;

int n, m, root[N], in[N], d[N];
pii b[N];
vector<int> a[N], g[N];


int get_root(int u)
{
    return (root[u] == 0) ? u : root[u] = get_root(root[u]);
}
void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        a[i].resize(m+1);
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            b[j] = mp(a[i][j], (i-1)*m + j);
        sort(b+1, b+m+1);
        for (int j = 2; j <= m; j++)
        {
            int p = get_root(b[j].S);
            int q = get_root(b[j-1].S);
            if (b[j].F == b[j-1].F && p != q) root[p] = q;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            b[j] = mp(a[j][i], (j-1)*m + i);
        sort(b+1, b+n+1);
        for (int j = 2; j <= n; j++)
        {
            int p = get_root(b[j].S);
            int q = get_root(b[j-1].S);
            if (b[j].F == b[j-1].F && p != q) root[p] = q;
        }
    }
}

void makeGraph()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            b[j] = mp(a[i][j], (i-1)*m + j);
        sort(b+1, b+m+1);
        int st = get_root(b[1].S);
        for (int j = 2; j <= m; j++)
            if (b[j].F != b[j-1].F)
            {
                int p = get_root(b[j].S);
                g[st].PB(p);
                st = p;
            }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            b[j] = mp(a[j][i], (j-1)*m + i);
        sort(b+1, b+n+1);
        int st = get_root(b[1].S);
        for (int j = 2; j <= n; j++)
            if (b[j].F != b[j-1].F)
            {
                int p = get_root(b[j].S);
                g[st].PB(p);
                st = p;
            }
    }
}
void solve()
{
    for (int i = 1; i <= n*m; i++)
    {
        sort(g[i].begin(), g[i].end());
        auto it = unique(g[i].begin(), g[i].end());
        g[i].resize(distance(g[i].begin(), it));
        for (auto v : g[i]) in[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n*m; i++)
        if (in[i] == 0)
            {q.push(i), d[i] = 1;}
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {in[v]--, d[v] = max(d[v], d[u]+1);};
        for (auto v : g[u])
            if (in[v] == 0) q.push(v);
    }
    int res = 0;
    for (int i = 1; i <= n*m; i++)
        res = max(res, d[i]);
    cout <<res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    nhap();
    makeGraph();
    solve();
}
