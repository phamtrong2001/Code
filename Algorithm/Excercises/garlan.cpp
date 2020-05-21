/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxc 1000000007
#define task "garlan"
#define maxn 1004
#define maxm 20
#define maxx 66000

using namespace std;

int m, n, a[maxn][maxn], dp[maxx][maxm], res = maxc;
bool nho[maxx][maxm];

string s[maxm];

int calc(int y, int j)
{
    if (y == (1 << m)) return 0;
    if (y == (1 << (j-1))) return maxc;
    if (nho[y][j]) return dp[y][j];
    nho[y][j] = 1;
    dp[y][j] = maxc;
    int x = y ^ (1 << (j-1));
    for (int i = 1; i <= m+1; i++)
        if ((x >> (i-1)) & 1)
            dp[y][j] = min(dp[y][j], calc(x, i) + a[i][j]);
    return dp[y][j];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> s[i];
    s[m+1] = "";
    for (int i = 1; i <= n; i++)
        s[m+1] = s[m+1] + "0";
    for (int i = 1; i <= m; i++)
        for (int j = i; j <= m+1; j++)
            for (int k = 0; k < n; k++)
                if (s[i][k] != s[j][k]) a[i][j]++, a[j][i] = a[i][j];
    for (int i = 1; i <= m; i++)
        res = min(res, calc((1 << (m+1))-1, i));
    cout << res;
    return 0;
}
