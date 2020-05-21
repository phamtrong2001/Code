#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 25
#define maxc 1000000007

using namespace std;

ll n, m, dirty, dd[N][N], dp[1 << 12][N], d[N][N], dxx[N][N], res = maxc;
char c[N][N];
pii st, dir[N];
ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};

bool bit(ll x, ll i)
{
    return (x >> i) & 1;
}
ll BFS(int u, int v, int u0, int v0)
{
    queue<pair<pii, int> >q;
    dxx[u][v] = 0;
    q.push(mp(mp(u, v), 0));
    while (!q.empty())
    {
        int u1 = q.front().F.F;
        int v1 = q.front().F.S;
        int l = q.front().S;
        q.pop();
        if (dxx[u1][v1] < l) continue;
        for (int i = 0; i < 4; i++)
        {
            int x = u1 + dx[i];
            int y = v1 + dy[i];
            if (c[x][y] == 'x' || x < 1 || y < 1 || x > n || y > m) continue;
            if (dxx[x][y] > dxx[u1][v1] + 1)
            {
                dxx[x][y] = dxx[u1][v1] + 1;
                q.push(mp(mp(x, y), dxx[x][y]));
            }
        }
    }
    return dxx[u0][v0];
}
int main()
{
    freopen("MCLEAN.INP", "r", stdin);
    freopen("MCLEAN.OUT", "w", stdout);
    cin >> m >> n;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= m; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == 'o') st = mp(i, j);
            else if (c[i][j] == '*') dir[++dirty] = mp(i, j);
        }

    for (int i = 1; i <= dirty; i++)
    {
        memset(dd, 0, sizeof dd);
        memset(dxx, 60, sizeof dxx);
        d[0][i] = BFS(st.F, st.S, dir[i].F, dir[i].S);
        dp[(1 << (i-1))][i-1] = d[0][i];
        if (d[0][i] >= maxc) {cout <<-1; return 0;}
    }
    for (int i = 1; i <= dirty; i++)
        for (int j = 1; j <= dirty; j++)
        {
            memset(dd, 0, sizeof dd);
            memset(dxx, 60, sizeof dxx);
            d[i][j] = BFS(dir[i].F, dir[i].S, dir[j].F, dir[j].S);
        }

    for (int x = 1; x < (1 << dirty); x++)
        for (int i = 0; i < dirty; i++)
            if (bit(x, i))
            {
                if (__builtin_popcount(x) == 1) continue;
                dp[x][i] = maxc;
                int y = x ^ (1 << i);
                for (int j = 0; j < dirty; j++)
                    if (bit(y, j))
                    dp[x][i] = min(dp[x][i], dp[y][j] + d[j+1][i+1]);
            }
    for (int i = 1; i <= dirty; i++) res = min(res, dp[(1 << dirty) - 1][i-1]);
    cout <<res;
}
