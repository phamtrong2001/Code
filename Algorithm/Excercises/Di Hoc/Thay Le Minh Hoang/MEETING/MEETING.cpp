#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1005
#define maxc 1000000007

using namespace std;

int n, dd[N], ans[N], res, dem[3], tt;
pii c[N];
bool dp[N][N];
int tr[N][N];
vector<int> a[N], all[N][3];

void nhap()
{
    scanf("%d", &n);
    int u, v;
    while (scanf("%d %d", &u, &v) > 0)
    {
        a[u].PB(v);
        a[v].PB(u);
    }
}
void DFS(int u)
{
    for (auto v : a[u])
    {
        if (dd[v]) continue;
        else
        {
            dd[v] = 3 - dd[u];
            dem[dd[v]]++;
            all[tt][dd[v]].PB(v);
            DFS(v);
        }
    }
}

void solve()
{
    for (int i = 1; i <= n; i++)
        if (!dd[i])
        {
            tt++;
            dem[1] = 1; dem[2] = 0;
            dd[i] = 1; all[tt][1].PB(i);
            DFS(i);
            c[tt] = mp(dem[1], dem[2]);
        }
    dp[0][0] = 1;
    for (int i = 1; i <= tt; i++)
        for (int j = n; j >= 0; j--)
        {
            if (j >= c[i].F && dp[i-1][j-c[i].F])
            {
                dp[i][j] |= dp[i-1][j-c[i].F];
                tr[i][j] = 1;
            }
            if (j >= c[i].S && dp[i-1][j-c[i].S])
            {
                dp[i][j] |= dp[i-1][j-c[i].S];
                tr[i][j] = 2;
            }
        }
}
void truyvet()
{
    for (int i = n/2; i >= 0; i--)
        if (dp[tt][i])
        {
            res = i;
            break;
        }
    int i = tt, j = res;
    while (i || j)
    {
        if (tr[i][j] == 1)
        {
            for (auto x : all[i][1]) ans[x] = 1;
            j -= c[i--].F;
        }
        else
        {
            for (auto x : all[i][2]) ans[x] = 1;
            j -= c[i--].S;
        }
    }
    printf("%d %d\n", res, n-res);
    for (int i = 1; i <= n; i++)
        if (ans[i]) printf("%d ", i);
    printf("\n");
    for (int i = 1; i <= n; i++)
        if (!ans[i]) printf("%d ", i);
}
int main()
{
    freopen("MEETING.INP", "r", stdin);
    freopen("MEETING.OUT", "w", stdout);
    nhap();
    solve();
    truyvet();
}
