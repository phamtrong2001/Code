#include <bits/stdc++.h>

using namespace std;

void nhap()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int u, v; scanf("%d %d", &u, &v);
        a[u].PB(v);
    }
}

void DFS(int u, int dep)
{
    tin[u] = ++tt;
    s[dep].PB(tin[u]);
    h[u] = dep;
    for (auto v : a[u])
        DFS(v, dep+1);
    tout[u] = ++tt;
}

void update(int u, int k, int e)
{
    k += h[u];
    int lef = lower_bound(s[k].begin(), s[k].end(), tin[u]) - s[k].begin();
    int rig = upper_bound(s[k].begin(), s[k].end(), tout[u]) - s[k].begin()-1;
    upd(k, rig, e);
    upd(k, lef-1, -e);
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    nhap();
    DFS(1, 0);
    scanf("%d", &q);
    while (q--)
    {
        int type, u, k, e;
        scanf("%d %d", &type, &u);
        if (type == 1)
        {
            scanf("%d %d", &k, &e);
            update(u, k, e);
        }
        else printf("%d\n", query(u));
    }
}
