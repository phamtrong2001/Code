#include <bits/stdc++.h>
#define pii pair<int, int>
#define PB push_back
#define MP make_pair
#define ll long long
#define F first
#define S second
#define task "enjoy"
#define maxc 1000000007
#define maxn 20

using namespace std;

ll m, n, k, a[maxn], c[maxn][maxn], dp[1<<maxn][maxn], res = -maxc;

bool bit(ll x, ll i)
{
    return ((x >> i) & 1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[1 << (i-1)][i] = a[i];
    }
    for (int x, y, w, i = 1; i <= k; i++)
    {
        cin >> x >> y >> w;
        c[x][y] = w;
    }
    for (int x = 0; x < (1 << n); x++)
    {
        ll pos = -maxc;
        for (int i = 1; i <= n; i++)
            if (bit(x, i-1))
            {
                ll y = x ^ (1 << (i-1));
                for (int j = 1; j <= n; j++)
                    if (bit(y, j-1)) dp[x][i] = max(dp[x][i], dp[y][j] + a[i] + c[j][i]);
                pos = max(pos, dp[x][i]);
            }
        int sl = __builtin_popcount(x);
        if (sl == m) res = max(res, pos);
    }
    memset(dp, 0x32, sizeof dp);
    cout << dp[0][0] << '\n';
    cout << res;
    return 0;
}
