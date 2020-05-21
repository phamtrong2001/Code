#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 19
#define maxc 1000000007

using namespace std;

long long n, m, k, a[N], c[N][N], dp[1 << N][N], res;

bool bit(long long x, long long i)
{
    return (x >> i) & 1;
}
int main()
{
    freopen("ENJOY.INP", "r", stdin);
    freopen("ENJOY.OUT", "w", stdout);
    cin >> n >> m >> k;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long i = 1; i <= k; i++)
    {
        long long u, v, w; cin >> u >> v >> w;
        c[u][v] = w;
    }
    for (long long x = 1; x < (1 << n); x++)
        for (long long i = 0; i < n; i++)
            if (bit(x, i))
            {
                dp[x][i] = a[i+1];
                long long y = x ^ (1 << i);
                for (long long j = 0; j < n; j++)
                    if (bit(y, j)) dp[x][i] = max(dp[x][i], dp[y][j] + a[i+1] + c[j+1][i+1]);

                if (__builtin_popcount(x) == m) res = max(res, dp[x][i]);
            }
    cout <<res;
}
