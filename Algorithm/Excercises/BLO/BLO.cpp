#include <bits/stdc++.h>
#define PB push_back
#define N 100005
using namespace std;

int n, m, indexx[N], low[N], s[N], isCut[N], tt, child[N], par[N];
vector<int> a[N];
void nhap()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v; scanf("%d %d", &u, &v);
        a[u].PB(v);
        a[v].PB(u);
    }
}
void visit(int u)
{
    indexx[u] = low[u] = ++tt;
    s[u] = 1;
    for (auto v : a[u])
    {
        if (v != par[u])
        {
            if (!indexx[v])
            {
                child[u]++;
                par[v] = u;
                visit(v);
                s[u] += s[v];
                low[u] = min(low[u], low[v]);
                if ((child[u] > 1 || par[u] != -1) && low[v] >= indexx[u]) isCut[u] = 1;
            }
            else low[u] = min(low[u], indexx[v]);

        }
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        if (!isCut[i]) printf("%d\n", 2*(n-1));
        else
        {
            int sum = 0;
            for (auto v : a[u])
                if (low[v] >= indexx[u]) sum += s[v];

            ll res = 1ll*(n - sum) * sum + 2ll*(n - sum - 1);
            for (auto v : a[u])
                if (low[v] >= indexx[u])
                    res += 1ll*sum * (n - s[v]);
            printf("%I64d\n", &res);
        }
    }
}
int main()
{
    freopen("BLO.INP", "r", stdin);
    freopen("BLO.OUT", "w", stdout);
    nhap();
    par[1] = -1;
    visit(1);
    solve();
}
