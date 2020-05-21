#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 2000
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, a[N][N], dp[N][N], tracex[N][N], tracey[N][N], luux[N][N], luuy[N][N];
void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
}
void solve()
{
    memset(luux, 60, sizeof luux);
    memset(luuy, 60, sizeof luuy);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            luux[i][j] = min(luux[i-1][j], a[i][j]);
            luuy[i][j] = min(luuy[i][j-1], a[i][j]);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1) dp[i][j] = a[i][j];
            else if (i == 1)
            {
                dp[i][j] = min(dp[i][j-1], a[i][j]);
                tracex[i][j] = i;
                tracey[i][j] = j-1;
            }
            else if (j == 1)
            {
                dp[i][j] = min(dp[i-1][j], a[i][j]);
                tracex[i][j] = i-1;
                tracey[i][j] = j;
            }
            else
            {
                if (luux[i-1][j] > luuy[i][j-1])
                {
                    dp[i][j] = min(luuy[i][j-1], a[i][j]);
                    tracex[i][j] = i;
                    tracey[i][j] = j-1;
                }
                else
                {
                    dp[i][j] = min(luux[i-1][j], a[i][j]);
                    tracex[i][j] = i-1;
                    tracey[i][j] = j;
                }
            }
        }
    vector <int> ve;
    int i = n, j = m;
    while (i != 1 || j != 1)
    {
        ve.PB(a[i][j]);
        int u = tracex[i][j];
        int v = tracey[i][j];
        i = u, j = v;
    }
    ve.PB(a[1][1]);
    for (int i = ve.size()-1; i >= 0; i--) cout << ve[i]<<" ";
}

int main()
{
    freopen("MLEXPATH.INP", "r", stdin);
    freopen("MLEXPATH.OUT", "w", stdout);
    nhap();
    solve();

}
