#include <bits/stdc++.h>
#define N 55
using namespace std;

int n, dp[N][N][N][N], res;
char c[N][N];
int main()
{
    //freopen("INP.TXT", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> c[i][j];

    for (int h = 1; h <= n; h++)
        for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)

                {
                    int u = i + h - 1;
                    int v = j + k - 1;
                    if (u > n || v > n) continue;
                    if (u == i && v == j) dp[i][j][u][v] = 1;
                    else if (c[i][j] == c[u][v])
                        dp[i][j][u][v] = max(dp[i][j+1][u-1][v], max(dp[i+1][j][u-1][v], max(dp[i][j+1][u][v-1], dp[i+1][j][u][v-1]))) + 2;

                    if (dp[i][j][u][v] == (u + v - i - j + 1)) res = max(dp[i][j][u][v], res);
                    //else dp[i][j][u][v] = 0;
                }
    cout <<res;
}
