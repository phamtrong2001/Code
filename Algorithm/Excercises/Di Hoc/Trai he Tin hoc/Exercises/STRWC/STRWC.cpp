#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, l, dp[N], p[N][25], luu[N][30];
char c[N], a[N];
void reset()
{
    memset(dp, 0, sizeof dp);
    memset(a, 0, sizeof a);
    memset(p, 0, sizeof p);
}
void nhap()
{
    cin >> n >> l;
    for (int i = 1; i <= n; i++) cin >> c[i];
}
void solve()
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j <= 26; j++)
        {
            if (c[i] == '*') luu[i][j] = 1;
            else luu[i][j] =
        luu[i][c[i]-'a'] = luu[i+l][c[i]-'a'];
        if (i + l > n)
        {
            dp[i] = 1;
            if (c[i] == '*') a[i] = 0;
            else a[i] = c[i];
            continue;
        }
        if (c[i] == '*')
        {
            dp[i] = dp[i+l] + 1;
            a[i] = c[i+l];
            continue;
        }
        if (a[i+l] == c[i] || a[i+l] == 0)
        {
            dp[i] = dp[i+l] + 1;
            a[i] = c[i];
            continue;
        }
        dp[i] = luu[i+l][c[i]-'a'];
        a[i] = c[i];

    }
    for (int i = 1; i <= n; i++) p[i][0] = dp[i];

    for (int k = 1; (1 << k) <= n; k++)
        for (int i = 1; i + (1 << k) - 1 <= n; i++)
            p[i][k] = min(p[i][k-1], p[i+(1<<(k-1))][k-1]);
    int res = 0;
    for (int u = 1; u <= n; u++)
    {
        int v = u + l - 1;
        if (v > n) break;
        int k = log2(v-u+1);
        res = max(res, min(p[u][k], p[v-(1 << k) + 1][k]) * l);
    }
    cout <<res<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    freopen("STRWC.INP", "r", stdin);
   // freopen("STRWC.OUT", "w", stdout);
    int t; cin >> t;
    while (t--)
    {
        reset();
        nhap();
        solve();
    }
}
