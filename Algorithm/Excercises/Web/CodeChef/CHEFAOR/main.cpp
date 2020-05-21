#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 5005
#define maxc 1ll*100000000000000007

using namespace std;

int n, k, a[N], s[N][N];
long long dp[N][N];

void calc(int id, int l, int r, int x, int y)
{
    if (l > r) return;
    int mid = (r + l)/2;
    long long ans = -maxc; int pos;

    for (int i = x; i <= min(mid, y); i++)
    {
        long long res = dp[id-1][i-1] + s[i][mid];
        if (res > ans)
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
    freopen("INP.TXT", "r", stdin);
    int Tests; scanf("%d", &Tests);
    while (Tests--)
    {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++) s[i][j] = s[i][j-1] | a[j];
        for (int i = 1; i <= n; i++) dp[0][i] = -maxc;
        for (int i = 1; i <= k; i++)
            calc(i, 1, n, 1, n);
        printf("%lld\n", dp[k][n]);
    }
}
