#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 2005
#define maxc 1000000007

using namespace std;

int n, a[N], k[N][N], s[N], dp[N][N];

int readInt ()
{
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

int main()
{
    n = readInt();
    memset(dp, -60, sizeof dp);
    for (int i = 1; i <= n; i++)
    {
        a[i] = readInt(); s[i] = s[i-1] + a[i];
        k[i][i] = i;
        dp[i][i] = 0;
    }
    for (int l = 2; l <= n; l++)
        for (int i = 1; i + l - 1 <= n; i++)
        {
            int j = i + l - 1;
            for (int t = k[i][j-1]; t <= k[i+1][j]; t++)
            {
                int v = min(dp[i][t] + s[t] - s[i-1], dp[t+1][j] + s[j] - s[t]);
                if (v > dp[i][j])
                {
                    dp[i][j] = v;
                    k[i][j] = t;
                }
            }
        }
    cout <<dp[1][n];
}
