#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1005
#define maxc 1000000007

using namespace std;

int n, q, dp[N][N];
vector<pii> a[N];

void DFS(int u, int p)
{
    int pos = -1;
    for (int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i].F;
        if (v == p) pos = i;
        if (v == p || v == 0) continue;
        DFS(v, u);
    }
    if (pos != -1) a[u].erase(a[u].begin() + pos);
    int v1 = a[u][0].F; int w1 = a[u][0].S;
    int v2 = a[u][1].F; int w2 = a[u][1].S;
    for (int i = 1; i <= q; i++)
    {
        dp[u][i] = max(dp[v1][i-1] + w1, dp[v2][i-1] + w2);
        for (int j = 0; j <= i-2; j++)
            dp[u][i] = max(dp[u][i], dp[v1][j] + dp[v2][i-j-2] + w1 + w2);
    }

}
int main()
{
    freopen("APPLE.INP", "r", stdin);
    freopen("APPLE.OUT", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        a[u].PB(mp(v, w));
        a[v].PB(mp(u, w));
    }
    for (int u = 1; u <= n; u++) a[u].PB(mp(0, 0)), a[u].PB(mp(0, 0));
    DFS(1, -1);
    cout <<dp[1][q];
}
