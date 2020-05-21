#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("INP.TXT", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        ma[mp(u, v)]++;
        ma[mp(v, u)]++;
        if (ma[mp(u, v)] == 1)
        {
            a[u].PB(mp(v, 0));
            a[v].PB(mp(u, 0));
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < a[i].size(); j++)
        {
            int v = a[i][j].F;
            a[i][j].S = ma[mp(i, v)];
        }

}
