#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 50
#define M 205
#define maxc 1000000007

using namespace std;

int n, m, p, K, dd[N][N], dp[M][N][N];
string s;

void inline MIN(int &a, int b) {a = min(a, b);}

int main()
{
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    cin >> m >> n >> p >> K;
    cin >> s; s = "#" + s;
    for (int i = 1; i <= p; i++)
    {
        int u, v; cin >> u >> v;
        if (u == 1 && v == 1) continue;
        dd[u][v] = 1;
    }
    for (int i = 0; i <= n+1; i++) dd[0][i] = dd[m+1][i] = 1;
    for (int i = 0; i <= m+1; i++) dd[i][0] = dd[i][n+1] = 1;
    for (int i = 0; i <= K; i++)
        for (int j = 0; j <= m+1; j++)
            for (int k = 0; k <= n+1; k++) dp[i][j][k] = maxc;
    dp[0][1][1] = 1;
    for (int i = 1; i <= K; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= n; k++)
            {
                if (dd[j][k]) continue;
                MIN(dp[i][j][k], dp[i-1][j][k] + 1);
                int u = j, v = k;
                if (s[i] == 'U') u++;
                else if (s[i] == 'D') u--;
                else if (s[i] == 'L') v++;
                else v--;
                MIN(dp[i][j][k], dp[i-1][u][v]);
                u = j, v = k;
                if (s[i] == 'U') u--;
                else if (s[i] == 'D') u++;
                else if (s[i] == 'L') v--;
                else v++;
                if (dd[u][v]) MIN(dp[i][j][k], dp[i-1][j][k]);
            }
    if (dp[K][m][n] >= maxc) dp[K][m][n] = 0;
    cout <<dp[K][m][n] - 1;
}
