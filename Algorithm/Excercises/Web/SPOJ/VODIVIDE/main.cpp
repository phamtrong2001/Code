#include <bits/stdc++.h>
#define N 5005
#define PB push_back
using namespace std;

struct coin
{
    int x, y, id;
}a[N];
bool cmp(coin p, coin q)
{
    return p.x < q.x;
}

vector<int> vinh, son;
int n;
long long dp[N][N];

int main()
{
    freopen("INP.TXT", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].x);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].y), a[i].id = i;
    sort(a+1, a+n+1, cmp);
    dp[1][0] = a[1].y;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i/2; j++)
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j] + a[i].y);
    printf("%lld\n", dp[n][n/2]);
    int u = n, v = n/2;
    while (u > 0)
    {
        if (dp[u][v] == dp[u-1][v-1]) vinh.PB(a[u].id);
        else
        {
            v--;
            son.PB(a[u].id);
        }
        u--;
    }
    for (int i = 0; i < n/2; i++)
        printf("%d %d\n", son[i], vinh[i]);
}
