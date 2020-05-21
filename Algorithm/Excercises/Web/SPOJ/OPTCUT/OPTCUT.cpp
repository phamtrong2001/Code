#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 2005
#define maxc 1000000007

using namespace std;

int n, dp[N][N], k[N][N], s[N], a[N];

int main()
{
    cin >> n;
    memset(dp, 60, sizeof dp);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        k[i][i] = i;
        s[i] = s[i-1] + a[i];
        dp[i][i] = 0;
    }
    for (int l = 2; l <= n; l++)
        for (int i = 1; i + l - 1 <= n; i++)
        {
            int j = i + l - 1;
            for (int t = k[i][j-1]; t <= k[i+1][j]; t++)
            {
                int v = s[j] - s[i-1] + dp[i][t] + dp[t+1][j];
                if (v < dp[i][j])
                {
                    dp[i][j] = v;
                    k[i][j] = t;
                }
            }
        }
    cout <<dp[1][n];
}
