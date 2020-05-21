#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 4005
#define K 804
#define maxc 1000000007

using namespace std;

int n, k, s[N][N], dp[K][N];

int sum(int x, int y, int u, int v)
{
    return s[u][v] - s[x-1][v] - s[u][y-1] + s[x-1][y-1];
}
void calc(int id, int l, int r, int x, int y)
{
    if (l > r) return;
    int mid = (r + l)/2;
    int ans = maxc, pos;
    for (int i = x; i <= min(y, mid); i++)
    {
        int res = dp[id-1][i-1] + sum(i, i, mid, mid)/2;
        if (res < ans)
        {
            ans = res;
            pos = i;
        }
    }
    dp[id][mid] = ans;
    calc(id, l, mid-1, x, pos);
    calc(id, mid+1, r, pos, y);
}
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char c;
            c = getchar();
            while(c == ' '|| c == '\n') c = getchar();
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + c - '0';
        }
    for (int i = 1; i <= n; i++) dp[1][i] = sum(1, 1, i, i)/2;
    for (int i = 2; i <= k; i++)
        calc(i, 1, n, 1, n);
    printf("%d", dp[k][n]);
}
