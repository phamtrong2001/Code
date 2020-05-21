#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
using namespace std;

int n, m, dd[N], h[N], res;
vector<pii> a[N];
void nhap()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) a[i].clear();
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (u == v && w == 1) res = 1;
        if (u == v) continue;
        a[u].PB(mp(v, w));
        a[v].PB(mp(u, w));
    }
}
void DFS(int u)
{
    dd[u] = 1;
    for (auto z : a[u])
    {
        int v = z.F;
        int w = z.S;

        if (!dd[v])
        {
            h[v] = h[u] + w;
            DFS(v);

        }
        else
        {
            int diff = h[u] - h[v];
            if (w == 1 && diff % 2 == 0) res = 1;
            if (w == 0 && diff % 2 == 1) res = 1;
        }
    }
}
void solve()
{
    memset(dd, 0, sizeof dd);
    memset(h, 0, sizeof h);
    for (int i = 1; i <= n; i++)
        if (!dd[i]) DFS(i);
    if (res) printf("no\n");
    else printf("yes\n");
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    int testCase; scanf("%d", &testCase);
    while (testCase--)
    {
        res = 0;
        nhap();
        solve();
    }
}
