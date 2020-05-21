
#include <bits/stdc++.h>
#define pii pair<int, int>
#define PB push_back
#define MP make_pair
#define ll long long
#define F first
#define S second
#define task "marriage"
#define maxc 1000000007
#define maxn 25

using namespace std;

int n, a[maxn][maxn];

ll dp[1 << maxn], dd[1 << maxn];

bool bit(int x, int i)
{
    return ((x >> i) & 1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    dd[0] = 1;
    for (int x = 0; x < (1 << n); x++)
       {
           int d = __builtin_popcount(x);
           for (int i = 1; i <= n; i++)
               if (bit(x, i-1))
               {
                    int y = x ^ (1 << (i-1));
                    if (dp[x] < dp[y] + a[d][i]) dp[x] = dp[y] + a[d][i], dd[x] = dd[y];
                        else if (dp[x] == dp[y] + a[d][i]) dd[x] += dd[y];
               }
       }
    cout << dp[(1<<n)-1] << " " << dd[(1<<n)-1];
    return 0;
}
