#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1005
#define MOD 1000000007

using namespace std;

long long dp[N][N], sum[N][N], c[2*N][2*N];
long long res[55][N], p[55];
int main()
{
    freopen("INP.TXT", "r", stdin);
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) sum[0][i] = 1;
    for (int i = 1; i <= 51; i++)
    {
        for (int j = N-1; j >= 1; j--)
        {
            for (int k = N-1; k >= 1; k--)
            {
                if ((j >= k && i == 1) || j > k) dp[j][k] = sum[j-k][k-1];
                else dp[j][k] = 0;
                sum[j][k] = dp[j][k];
            }

            for (int k = 1; k < N; k++) sum[j][k] = (sum[j][k] + sum[j][k-1]) % MOD;
            res[i][j] = sum[j][N-1];
        }
        sum[0][0] = dp[0][0] = 0;
    }
    //cout <<res[2][2]<<endl;
    c[0][0] = c[1][1] = 1;
    for (int i = 2; i < 2*N; i++)
        for (int j = 1; j <= i; j++) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
    p[0] = 1;
    for (int i = 1; i < 55; i++) p[i] = (p[i-1]*i) % MOD;
    for (int i = 0; i <= 51; i++)
        for (int j = 1; j < N; j++) res[i][j] = (res[i][j-1] + (res[i][j] * p[i]) % MOD) % MOD;

    int t; scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        if (k > 51) printf("0\n");
        else
        {
            long long ans = 0;
            for (int i = k; i <= n; i++) ans = (ans + (res[k][i]*c[n-i+k][k]) % MOD) % MOD;
            printf("%I64d\n", ans);
        }

    }
    return 0;

}
