#include <bits/stdc++.h>
#define PB push_back
#define N 200006
#define maxc 1000000007

using namespace std;

int n, tt, dp1[N], dp1a[N], tin[N], tout[N], pa[N], dxuoi[N], dnguoc[N];
vector<int> a[N], all;
int ROOT1, ROOT2, res = 0;
void DFS(int u, int p)
{
    tin[u] = ++tt;
    dp1[u] = dp1a[u] = 1;
    for (auto v : a[u])
    {
        if (v == p) continue;
        DFS(v, u);
        pa[v] = u;
        if (dp1[v] + 1 >= dp1[u])
        {
            dp1a[u] = dp1[u];
            dp1[u] = dp1[v] + 1;
        }
        else if (dp1[v] + 1 >= dp1a[u]) dp1a[u] = dp1[v] + 1;
    }
    tout[u] = ++tt;
}
void createChain()
{
    int u = ROOT2;
    while (u != ROOT1)
    {
        all.PB(u);
        u = pa[u];
    }
    all.PB(ROOT1);
}
void calc()
{
    createChain();

    int sz = all.size()-1;
    for (int i = 0; i < all.size(); i++) dnguoc[all[i]] = i+1, dxuoi[all[i]] = all.size()-i;

    if (dp1[all[sz-1]] + 1 == dp1[all[sz]]) dxuoi[all[sz]] = max(dp1a[all[sz]], dxuoi[all[sz]]);
    else dxuoi[all[sz]] = max(dxuoi[all[sz]], dp1[all[sz]]);

    for (int i = all.size()-2; i > 0; i--)
    {
        int u = all[i]; int z = 0;
        if (i != 0 && dp1[u] == dp1[all[i-1]] + 1) z = dp1a[u];
        else z = dp1[u];
        dxuoi[u] = max(dxuoi[u], (int)all.size()-i-1 + z);
        dxuoi[u] = max(dxuoi[u], dxuoi[all[i+1]]);
    }
    dnguoc[all[0]] = dp1[all[0]];
    for (int i = 1; i < all.size()-1; i++)
    {
        int u = all[i]; int z = 0;
        if (dp1[u] == dp1[all[i-1]] + 1) z = dp1a[u];
        else z = dp1[u];
        dnguoc[u] = max(dnguoc[u], i + z);
        dnguoc[u] = max(dnguoc[u], dnguoc[all[i-1]]);
    }
    for (int i = 0; i < all.size()-1; i++) res = max(min(dnguoc[all[i]], dxuoi[all[i+1]]), res);
    cout <<res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("DWARFS.INP", "r", stdin);
    freopen("DWARFS.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        a[u].PB(v);
        a[v].PB(u);
    }
    cin >> ROOT1 >> ROOT2;
    DFS(ROOT1, -1);
    calc();
    return 0;
}
