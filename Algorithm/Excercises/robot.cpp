/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pii pair<int, int>
#define sz(x) ((int) x.size())
#define PB push_back
#define PF push_front
#define MP make_pair
#define ll long long
#define F first
#define S second
#define maxc 1000000007
#define MOD 1000000007
#define base 107
#define eps 1e-6
#define maxn 202
#define task "robot"
#define remain(x) ((x > MOD) ? (x - MOD) : x)

using namespace std;

int m, n, p, k, dd[maxn][maxn], dp[maxn][maxn][maxn];

string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> m >> n >> p >> k;
    cin >> s;
    s = "#" + s;
    FOR(i, 1, p)
    {
        int u, v;
        cin >> u >> v;
        if (u == 1 && v == 1) continue;
        dd[u][v] = 1;
    }
    if (dd[m][n])
    {
        cout << -1;
        return 0;
    }
    FOR(i, 1, n) dd[0][i] = dd[m+1][i] = 1;
    FOR(i, 1, m) dd[i][0] = dd[i][n+1] = 1;
    FOR(d, 0, k)
        FOR(i, 0, m+1)
            FOR(j, 0, n+1) dp[d][i][j] = maxc;
    dp[0][1][1] = 1;
    FOR(d, 1, k)
        FOR(i, 1, m)
            FOR(j, 1, n)
            {
                if (dd[i][j]) continue;
                if (dp[d-1][i][j] != maxc)
                    dp[d][i][j] = min(dp[d][i][j], dp[d-1][i][j] + 1);
                int u = i, v = j;
                if (s[d] == 'U') u++;
                    else if (s[d] == 'D') u--;
                        else if (s[d] == 'R') v--;
                            else v++;
                if (dp[d-1][u][v] != maxc) dp[d][i][j] = min(dp[d][i][j], dp[d-1][u][v]);
                u = i, v = j;
                if (s[d] == 'D') u++;
                    else if (s[d] == 'U') u--;
                        else if (s[d] == 'R') v++;
                            else v--;
                if (dd[u][v]) dp[d][i][j] = min(dp[d][i][j], dp[d-1][i][j]);
            }
    if (dp[k][m][n] == maxc) dp[k][m][n] = 0;
    cout << dp[k][m][n] - 1;
    return 0;
}
