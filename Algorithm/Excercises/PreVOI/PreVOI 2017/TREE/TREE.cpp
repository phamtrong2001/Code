#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 5005
#define MM 5000
#define maxc 1000000007

using namespace std;

int n, val[N], sz[N];
long long dp[N][N];
vector<int> a[N], g[N];


void DFSPre(int u, int p)
{
    for (auto v : a[u])
    {
        if (v == p) continue;
        g[u].PB(v);
        DFSPre(v, u);
    }
}
void DFS(int u)
{
    for (int i = 0; i <= MM; i++) dp[u][i] = maxc;
    if (g[u].size() == 0)
    {
        dp[u][0] = abs(val[u] - 0);
        dp[u][1] = abs(val[u] - 1);
        sz[u] = 1;
        return;
    }
    for (auto v : g[u]) DFS(v), sz[u] += sz[v];
    if (g[u].size() == 1)
    {
        int v = g[u][0];
        for (int i = 0; i <= sz[v]; i++)
            dp[u][i] = dp[v][i] + abs(val[u] - i);
    }
    else
    {
        int v1 = g[u][0];
        int v2 = g[u][1];
        for (int i = 0; i <= sz[v1]; i++)
            for (int j = 0; j <= sz[v2]; j++)
            {
                if (i+j > MM) break;
                dp[u][i+j] = min(dp[u][i+j], dp[v1][i] + dp[v2][j] + abs(val[u] - i - j));
            }
    }
}
int main()
{
    freopen("TREE.INP", "r", stdin);
    freopen("TREE.OUT", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
    for (int i = 1; i < n; i++)
    {
        int u, v; scanf("%d %d", &u, &v);
        a[u].PB(v);
        a[v].PB(u);
    }
    DFSPre(1, -1);
    DFS(1);
    printf("%d", *min_element(dp[1], dp[1] + MM + 1));
}
