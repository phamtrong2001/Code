#include <bits/stdc++.h>
#define N 5005
#define mod 2017
using namespace std;

string s;
int n, luu[N][N], dp[N][N], sum[N][N], pos[N][N];

int main()
{
    freopen("RECOVER.INP", "r", stdin);
    freopen("RECOVER.OUT", "w", stdout);
    cin >> s;
    n = s.length(); s = "#" + s;
    for (int len = 1; len <= n; len++)
    {
        if (s[n] <= s[n-len]) luu[n-len][n] = 0;
        else luu[n-len][n] = 1;
        for (int i = n-1; i >= len; i--)
        {
            if (s[i] > s[i-len])
            {
                luu[i-len][i] = 1;
                pos[i-len][i] = i-len;
            }
            else if (luu[i-len+1][i+1] && s[i] == s[i-len] && len != 1)
            {
                if (pos[i-len+1][i+1] >= i) continue;
                luu[i-len][i] = luu[i-len+1][i+1];
                pos[i-len][i] = pos[i-len+1][i+1];
            }
            else luu[i-len][i] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[1] == '0') dp[i][i] = 0; else dp[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (s[i-j+1] == '0') continue;
            dp[i][j] = (dp[i][j] + sum[i-j][j-1]) % mod;
            if (i - 2*j + 1 < 1 || s[i - 2*j + 1] == '0' || luu[i -2*j + 1][i-j+1] == 0) continue;
            dp[i][j] = (dp[i][j] + dp[i-j][j]) % mod;
        }
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] = (sum[i][j-1] + dp[i][j]) % mod;
        }
    }
    cout <<sum[n][n];
}
