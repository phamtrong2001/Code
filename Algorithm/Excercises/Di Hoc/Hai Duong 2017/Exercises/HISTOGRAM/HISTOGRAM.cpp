#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 15, maxval = (1 << maxn);
int n, A[maxn+1];
ll Dp[maxval][maxn+1], ans, D[maxval][maxn+1];

int main()
{
    freopen("HISTOGRAM.INP", "r", stdin);
    freopen("HISTOGRAM.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    while (cin >> n)
    {
        if (n == 0) return 0;
        memset(Dp, 0, sizeof(Dp));
        memset(D, 0, sizeof(D));
        for (int i=1; i<=n; i++) cin >> A[i], Dp[1 << (i-1)][i] = A[i], D[1 << (i-1)][i] = 1;
        int val = (1 << n) - 1;
        for (int x=0; x<=val; x++)
            for (int i=1; i<=n; i++)
                if ((x >> (i-1)) & 1)
                {
                    int y = x ^ (1 << (i-1));
                    for (int j=1; j<=n; j++)
                        if ((y >> (j-1)) & 1)
                        {
                                if (Dp[x][i] < Dp[y][j] + abs(A[i] - A[j]))
                                    Dp[x][i] = Dp[y][j] + abs(A[i] - A[j]), D[x][i] = D[y][j];
                                else
                                    if (Dp[x][i] == Dp[y][j] + abs(A[i] - A[j])) D[x][i] += D[y][j];
                        }
                }
        ans = 0;
        ll res = 0;
        for (int i=1; i<=n; i++)
        {
            if (ans < Dp[val][i] + 2*n + A[i]) ans = Dp[val][i] + 2*n + A[i], res = D[val][i];
            else
                if (ans == Dp[val][i] + 2*n + A[i]) res += D[val][i];
        }
        cout << ans << " " << res << "\n";
    }
    return 0;
}
