#include <bits/stdc++.h>
#define N 1005
#define ll long long
using namespace std;

int n, m, a[N];
ll dp[N][N][2], sum[N][N];
int main()
{
    freopen("INP.TXT", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d", &a[i]);

    //dp[0][0][1] = 1;
    for (int i = 0; i <= n; i++) dp[i][0][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i < a[j]) continue;
            dp[i][j][0] = dp[i-a[j]][j-1][1];
            dp[i][j][1] = sum[i-1][j];
            sum[i][j] = sum[i-1][j] + dp[i][j][0];
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; i++) res += dp[i][m][0];
    cout <<res;
}
