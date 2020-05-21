#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1005
#define maxc 1000000007

using namespace std;

int n, m, k, x1, x2, y1, y2, d[N][N][5], trc[N][N][5];
char c[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> c[i][j];
    for (int i = 1; i <= n; i++) c[i][0] = c[i][m+1] = '#';
    for (int i = 1; i <= m; i++) c[0][i] = c[n+1][0] = '#';
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2 && y1 == y2)
    {
        cout <<0;
        return 0;
    }
    memset(d, 60, sizeof d);
    memset(trc, 60, sizeof trc);

    priority_queue<pair<pii, pair<pii, int> > >q;
    for (int i = 0; i < 4; i++)
    {
        d[x1][y1][i] = trc[x1][y1][i] = 0;
        q.push(mp(mp(0, 0), mp(mp(x1, y1), i)));
    }
    while (!q.empty())
    {
        int u = q.top().S.F.F;
        int v = q.top().S.F.S;
        int dir = q.top().S.S;
        int l = q.top().F.F;
        int ll = q.top().F.S;
        q.pop();
        if (d[u][v][dir] < l || (d[u][v][dir] == l && trc[u][v][dir] < ll)) continue;
        for (int i = 0; i < 4; i++)
        {
            int x = u + dx[i];
            int y = v + dy[i];
            if (c[x][y] == '#' || x < 1 || x > n || y < 1 || y > m) continue;
            if (i == dir)
            {
                if (trc[u][v][i] < k)
                {
                    if (d[x][y][i] > d[u][v][i] || (d[x][y][i] == d[u][v][i] && trc[x][y][i] > trc[u][v][i]+1))
                    {
                        d[x][y][i] = d[u][v][i];
                        trc[x][y][i] = trc[u][v][i]+1;
                        q.push(mp(mp(-d[x][y][i], -trc[x][y][i]), mp(mp(x, y), i)));
                    }
                }
                else if (trc[u][v][i] == k)
                {
                    if (d[x][y][i] > d[u][v][i] + 1 || (d[x][y][i] == d[u][v][i] + 1 && trc[x][y][i] > 1))
                    {
                        d[x][y][i] = d[u][v][i] + 1;
                        trc[x][y][i] = 1;
                        q.push(mp(mp(-d[x][y][i], -trc[x][y][i]), mp(mp(x, y), i)));
                    }
                }
            }
            else if (d[x][y][i] > d[u][v][dir] + 1 || (d[x][y][i] == d[u][v][dir] + 1 && trc[x][y][i] > 1))
            {
                d[x][y][i] = d[u][v][dir] + 1;
                trc[x][y][i] = 1;
                q.push(mp(mp(-d[x][y][i], -trc[x][y][i]), mp(mp(x, y), i)));
            }
        }
    }
    int res = maxc;
    for (int i = 0; i < 4; i++) res = min(res, d[x2][y2][i]+1);
    if (res == maxc) res = -1;
    cout <<res;
}
