/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxc 1000000007
#define task "histogram"
#define maxn 15
#define maxx (1 << maxn)
#define ll long long

using namespace std;

int h[maxn], n;

ll dp[maxx][maxn], d[maxx][maxn];

pair <ll, ll> res;

int tinh(int i, int j)
{
    return abs(h[j] - h[i]);
}

bool bit(int x, int i)
{
    return (x >> i) & 1;
}

void solve(ll n)
{
    memset(dp, 0, sizeof (dp));
    memset(d, 0, sizeof (d));
    for (ll i = 1; i <= n; i++)
    {
        cin >> h[i];
        dp[1 << (i-1)][i] = h[i];
        d[1 << (i-1)][i] = 1;
    }
    for (int x = 1; x < (1 << n); x++)
        for (int i = 1; i <= n; i++)
            if (bit(x, i-1))
            {
                int y = x ^ (1 << (i-1));
                for (int j = 1; j <= n; j++)
                    if (bit(y, j-1))
                    {
                        if (dp[x][i] < dp[y][j] + tinh(i, j))
                        {
                            dp[x][i] = dp[y][j] + tinh(i, j);
                            d[x][i] = d[y][j];
                        }
                            else if (dp[x][i] == dp[y][j] + tinh(i, j))
                                d[x][i] += d[y][j];
                    }
            }
    int m = (1 << n) - 1;
    res = MP(0, 0);
    for (ll i = 1; i <= n; i++)
    {
        if (res.F < dp[m][i] + 2*n + h[i]) res = MP(dp[m][i] + 2*n + h[i], d[m][i]);
            else if (res.F == dp[m][i] + 2*n + h[i]) res.S += d[m][i];
    }
    cout << res.F << " " << res.S << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    while (cin >> n)
    {
        if (!n) return 0;
        solve(n);
    }
    return 0;
}
