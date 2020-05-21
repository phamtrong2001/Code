#include <bits/stdc++.h>
#define N 505
using namespace std;

int n, m, k, a[N];
long long dp[N][N];
void nhap()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        int x; scanf("%d", &x);
        a[x]++;
    }
}

long long calc(int x, int y)
{
    y++;
    if (y == 1) return 1ll*x*(x+1)/2;
    return 1ll*(x/y + 1) * (x/y + 2)/2 * (x % y) + 1ll*(x/y) * (x/y+1) * (y - x % y)/2;
}
void solve()
{
    memset(dp, 60, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j <= k; j++)
            for (int l = 0; l <= j; l++)
                dp[i][j] = min(dp[i][j], dp[i-1][j-l] + calc(a[i], l));
    printf("%I64d", dp[m][k]);
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    nhap();
    solve();
}
