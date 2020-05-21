#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1000005
#define MM 1003
#define maxc 1000000007

using namespace std;

int n, dp[N];

void prepare()
{

    memset(dp, 60, sizeof dp);
     dp[0] = 0;
    for (int i = 1; i <= MM; i++)
    {
        int x = i*i;
        if (x >= N) continue;
        dp[x] = 1;
    }
    for (int i = 1; i <= MM; i++)
        for (int j = 1; j <= MM; j++)
        {
            int x = i*i + j*j;
            if (x >= N) continue;
            dp[x] = min(dp[x], 2);
        }
}
void solve()
{
    cin >> n;
    int res = maxc;
    for (int i = 0; i <= n; i++)
        res = min(res, dp[i] + dp[n-i]);
    cout <<res;
}
int main()
{
    freopen("LAND_TAX.INP", "r", stdin);
    freopen("LAND_TAX.OUT", "w", stdout);
    prepare();
    solve();
}
