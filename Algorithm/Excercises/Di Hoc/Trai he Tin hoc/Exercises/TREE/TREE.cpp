#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1005
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, val[N], x[N], type[N], p[N], dem;
vector<int> a[N];
void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> val[i];
    for (int i = 1; i <= n; i++)
    {
        int u, v; cin >> type[i] >> u >> v;
        if (u != 0) a[i].PB(u);
        if (v != 0) a[i].PB(v);
    }
}

void DFS(int u)
{
    if (type[u] == 0)
    {
        x[u] = val[p[++dem]];
        return;
    }
    if (type[u] == 1)
    {
        for (int &v : a[u])
        {
            DFS(v);
            x[u] = max(x[u], x[v]);
        }
    }
    else
    {
        x[u] = maxc;
        for (int &v : a[u])
        {
            DFS(v);
            x[u] = min(x[u], x[v]);
        }
    }
}
void solve()
{
    for (int i = 1; i <= m; i++) p[i] = i;
    int res = 0;
    DFS(1);
    res = x[1];
    while (next_permutation(p+1, p+m+1))
    {
        memset(x, 0, sizeof x);
        dem = 0;
        DFS(1);
        res = max(res, x[1]);
    }
    cout <<res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("TREE.INP", "r", stdin);
    freopen("TREE.OUT", "w", stdout);
    nhap();
    if (m <= 15) solve();
    else
    {
        sort(val+1, val+m+1);
        cout <<val[m/2];
    }
}
