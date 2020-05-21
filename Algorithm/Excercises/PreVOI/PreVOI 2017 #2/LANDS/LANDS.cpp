#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define MM 100005
#define mod 1000000007
#define N 55
#define ZZ x1][y1][x2][y2

using namespace std;

int n, m, k, u[MM], v[MM], xmin, ymin, xmax, ymax;
ll p[MM], dp1[N][N][N][N], dp2[N][N][N][N];

void solve(int x1, int y1, int x2, int y2)
{
    if ((x1 != xmin && k > 0) || (x1 != x2 && k == 0))
    {
        if (dp1[ZZ] < dp1[x1+1][y1][x2][y2] + 1)
        {
            dp1[ZZ] = dp1[x1+1][y1][x2][y2] + 1;
            dp2[ZZ] = (dp2[x1+1][y1][x2][y2]*p[ymax-ymin+1]) % mod;
        }
        else if (dp1[ZZ] == dp1[x1+1][y1][x2][y2] + 1)
            dp2[ZZ] = (dp2[ZZ] + (dp2[x1+1][y1][x2][y2]*p[ymax-ymin+1]) % mod) % mod;
    }
    if ((y1 != ymin && k > 0) || (y1 != y2 && k == 0))
    {
        if (dp1[ZZ] < dp1[x1][y1+1][x2][y2] + 1)
        {
            dp1[ZZ] = dp1[x1][y1+1][x2][y2] + 1;
            dp2[ZZ] = (dp2[x1][y1+1][x2][y2]*p[xmax-xmin+1]) % mod;
        }
        else if (dp1[ZZ] == dp1[x1][y1+1][x2][y2] + 1)
            dp2[ZZ] = (dp2[ZZ] + (dp2[x1][y1+1][x2][y2]*p[xmax-xmin+1]) % mod) % mod;
    }
    if ((x2 != xmax && k > 0) || (x1 != x2 && k == 0))
    {
        if (dp1[ZZ] < dp1[x1][y1][x2-1][y2] + 1)
        {
            dp1[ZZ] = dp1[x1][y1][x2-1][y2] + 1;
            dp2[ZZ] = (dp2[x1][y1][x2-1][y2]*p[ymax-ymin+1]) % mod;
        }
        else if (dp1[ZZ] == dp1[x1][y1][x2-1][y2] + 1)
            dp2[ZZ] = (dp2[ZZ] + (dp2[x1][y1][x2-1][y2]*p[ymax-ymin+1]) % mod) % mod;
    }
    if ((y2 != ymax && k > 0) || (y1 != y2 && k == 0))
    {
        if (dp1[ZZ] < dp1[x1][y1][x2][y2-1] + 1)
        {
            dp1[ZZ] = dp1[x1][y1][x2][y2-1] + 1;
            dp2[ZZ] = (dp2[x1][y1][x2][y2-1]*p[xmax-xmin+1]) % mod;
        }
        else if (dp1[ZZ] == dp1[x1][y1][x2][y2-1] + 1)
            dp2[ZZ] = (dp2[ZZ] + (dp2[x1][y1][x2][y2-1]*p[xmax-xmin+1]) % mod) % mod;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("LANDS.INP", "r", stdin);
    freopen("LANDS.OUT", "w", stdout);
    cin >> n >> m >> k;
    p[0] = 1;
    for (int i = 1; i < MM; i++) p[i] = (p[i-1]*i) % mod;
    if (k)
    {
        xmin = ymin = mod;
        xmax = ymax = -mod;
        for (int i = 1; i <= k; i++)
        {
            cin >> u[i] >> v[i];
            xmin = min(xmin, u[i]);
            xmax = max(xmax, u[i]);
            ymin = min(ymin, v[i]);
            ymax = max(ymax, v[i]);
        }
        if (xmin == 1 && ymin == 1 && xmax == n && ymax == m)
        {
            cout <<p[n*m-k];
            return 0;
        }
        dp1[xmin][ymin][xmax][ymax] = 1;
        dp2[xmin][ymin][xmax][ymax] = p[xmax-xmin+ymax-ymin+2-k];
        for (int x1 = xmin; x1 >= 1; x1--)
        for (int y1 = ymin; y1 >= 1; y1--)
            for (int x2 = xmax; x2 <= n; x2++)
                for (int y2 = ymax; y2 <= m; y2++)
                {
                    if (x1 == xmin && y1 == ymin && x2 == xmax && y2 == ymax) continue;
                    solve(x1, y1, x2, y2);
                }
    }
    else
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) dp1[i][j][i][j] = dp2[i][j][i][j] = 1;
        for (int l1 = 1; l1 <= n; l1++)
            for (int l2 = 1; l2 <= m; l2++)
            {
                if (l1 == 1 && l2 == 1) continue;
                for (int x1 = 1; x1 + l1 - 1 <= n; x1++)
                    for (int y1 = 1; y1 + l2 - 1 <= m; y1++)
                    {
                        int x2 = x1 + l1 - 1;
                        int y2 = y1 + l2 - 1;
                        solve(x1, y1, x2, y2);
                    }
            }
    }
    cout <<dp2[1][1][n][m];
}
