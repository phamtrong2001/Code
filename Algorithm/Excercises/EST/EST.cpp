#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 2005
#define maxc 1000000007

using namespace std;

int m, n, s[N], dp[N][N], minUp[N][N], minDown[N][N];

int len(int u, int v)
{
    return s[v] - s[u-1] + (v - u);
}
void calc(int u, int v)
{
    if (v == 0)
    {
        dp[u][v] = 0;
        return;
    }
    int length = len(v+1, u);
    int l = -1, r = v;
    while (r - l > 1)
    {
        int mid = (r + l)/2;
        if (len(mid+1, v) > length) l = mid;
        else r = mid;
    }
    if (l != -1) dp[u][v] = min(minUp[v][l] - length, minDown[v][r] + length);
    else dp[u][v] = minDown[v][r] + length;
}
int main()
{
    freopen("EST.INP", "r", stdin);
    //freopen("EST.OUT", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        s[i] = s[i-1] + x;
    }
    memset(dp, 60, sizeof dp);
    memset(minUp, 60, sizeof minUp);
    memset(minDown, 60, sizeof minDown);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            if (len(j, i) > m) break;
            calc(i, j-1);
        }
        for (int j = 0; j <= i; j++)
            minUp[i][j] = min(minUp[i][j-1], dp[i][j] + len(j+1, i));
        for (int j = i; j >= 0; j--)
            minDown[i][j] = min(minDown[i][j+1], dp[i][j] - len(j+1, i));
    }
    cout<< *min_element(dp[n]+1, dp[n]+n+1);
}
