#include <bits/stdc++.h>
#define N 100005
#define PB push_back


using namespace std;

int n, m, k, l, vala[N], valb[N], cala[N], calb[N], par[N], indexx[N], low[N], tt;
vector<int> a[N];

void nhap()
{
    scanf("%d %d %d %d", &n, &m, &k, &l);
    for (int i = 1; i <= k; i++)
    {
        int x; scanf("%d", &x);
        vala[x] = 1;
    }
    for (int i = 1; i <= l; i++)
    {
        int x; scanf("%d", &x);
        valb[x] = 1;
    }
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
    for (auto v : a[u])
    {
        if (!par[v])
        {
            par[v] = u;
            visit(v);
            low[u] = min(low[u], low[v]);
            cala[u] = cala[v] + vala[u];
            calb[u] = calb[v] + valb[u];
        }
        else low[u] = min(low[u], indexx[v]);
    }
}
void solve()
{
    int res = 0;
    for (int u = 1; u <= n; u++)
    {
        for (auto v : a[u])
        {
            if (low[v] < indexx[v]) continue;
            dem++;
            if (cala[v] == k || cala[v] == 0 || calb[v] == l || calb[v] == 0) res++;
        }
    }
    cout <<res;
}
int main()
{
    freopen("NET.INP", "r", stdin);
    freopen("NET.OUT", "w", stdout);
    nhap();
    par[1] = 1;
    visit(1);
    solve();
}
