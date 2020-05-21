#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define LN 23
#define maxc 1000000007

using namespace std;

int n, k, c[N], res[N], dp[N][LN], dp1[N][LN];
vector<int> a[N];

void DFS1(int u, int p)
{
    dp[u][0] = c[u];
    for (auto v : a[u])
    {
        if (v == p) continue;
        DFS1(v, u);
        for (int i = 1; i <= 20; i++)
            dp[u][i] += dp[v][i-1];
    }
}

void DFS2(int u, int p)
{
    dp1[u][0] = c[u];
    if (p != -1)
    {
        dp1[u][1] -= c[p];
        for (int i = 1; i <= 20; i++)
            dp1[u][i] += dp1[p][i-1] + (dp[p][i-1] - dp[u][i-2]);
    }
    for (auto v : a[u])
    {
        if (v == p) continue;
        DFS2(v, u);
    }
    int ans = c[u];
    for (int i = 1; i <= k; i++) ans += dp[u][i] + dp1[u][i];
    res[u] = ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("NEARCOW.INP", "r", stdin);
    freopen("NEARCOW.OUT", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        a[u].PB(v);
        a[v].PB(u);
    }
    for (int i = 1; i <= n; i++) cin >> c[i];
    DFS1(1, -1);
    DFS2(1, -1);
    for (int i = 1; i <= n; i++) cout <<res[i]<<'\n';
}
