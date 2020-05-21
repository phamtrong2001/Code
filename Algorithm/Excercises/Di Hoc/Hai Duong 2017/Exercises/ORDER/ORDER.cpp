#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 17
#define maxc 1000000007

using namespace std;

int n, a[N][N], dp[1 << N];

bool bit(int x, int i)
{
    return (x >> i) & 1;
}
int calc(int x, int p)
{
    int ans = a[p][p];
    for (int i = 0; i < n; i++)
        if (bit(x, i)) ans += a[i+1][p];
    return ans;
}
int main()
{
    freopen("ORDER.INP", "r", stdin);
    freopen("ORDER.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];

    for (int x = 1; x < (1 << n); x++)
    {
        dp[x] = maxc;
        for (int i = 0; i < n; i++)
            if (bit(x, i)) dp[x] = min(dp[x], dp[x^(1<<i)] + calc(x^(1 << i), i+1));
    }
    cout <<dp[(1 << n) - 1];
}
