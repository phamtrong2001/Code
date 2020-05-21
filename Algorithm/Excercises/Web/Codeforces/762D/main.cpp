#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1ll*1000000000000000007

using namespace std;

long long n, a[4][N], dp[N][4];

int main()
{
    freopen("INP.TXT", "r", stdin);
    cin >> n;
    for (int i = 1; i <= 3; i++)
        for (int j = 0; j < N; j++) dp[j][i] = -maxc;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    dp[0][1] = 0; a[2][0] = a[3][0] = -maxc;
    for (int i = 0; i <= n; i++)
        for (int st = 1; st <= 3; st++)
            for (int en = 1; en <= 3; en++)
            {
                long long cur = dp[i][st] - a[st][i] + a[en][i+1];
                for (int j = min(st, en); j <= max(st, en); j++)
                    cur += a[j][i];
                dp[i+1][en] = max(dp[i+1][en], cur);

                cur = 0;
                for (int j = 1; j <= 3; j++)
                    cur += a[j][i] + a[j][i+1];
                dp[i+2][1] = max(dp[i+2][1], dp[i][3] + cur - a[3][i] + a[1][i+2]);
                dp[i+2][3] = max(dp[i+2][3], dp[i][1] + cur - a[1][i] + a[3][i+2]);
            }
    cout <<dp[n+1][3];
}
