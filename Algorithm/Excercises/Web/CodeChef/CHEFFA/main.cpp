#include <bits/stdc++.h>
#define mod 1000000007
#define N 132


using namespace std;

int t, n, a[N], sum[63][N][N], dp[63][N][N][N], amax[N];

void inline add(int &x, int y) {x += y; if (x >= mod) x-=mod;}

int main()
{
    freopen("INP.TXT", "r", stdin);
    freopen("OUT.TXT", "w", stdout);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int res = 0;
        memset(a, 0, sizeof a);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

        for (int i = 3; i <= n+10; i++)
            for (int x = 0; x <= 130; x++)
                for (int y = 0; y <= 130; y++)
                {
                    sum[i][x][y] = 0;
                    for (int z = 0; z <= 130; z++) dp[i][x][y][z] = 0;
                }
        if (n == 1)
        {
            cout <<1<<'\n';
            continue;
        }
        if (n == 2) res++;

        dp[3][a[3]][a[2]][a[1]] = 1;
        amax[1] = a[1];
        amax[2] = a[2];

        for (int i = 3; i <= n+10; i++)
            for (int x = a[i]; x <= 130; x++)
                for (int y = amax[i-1]; y >= 0; y--)
                    for (int z = amax[i-2]; z >= 0; z--)
                    {
                        if (x == a[i]) add(dp[i][x][y][z], sum[i-1][y][z]);
                        if (x > 0) add(dp[i][x][y][z], dp[i][x-1][y+1][z+1]);
                        add(sum[i][x][y], dp[i][x][y][z]);
                        if (dp[i][x][y][z]) amax[i] = x;
                    }


            for (int x = 0; x <= amax[n]; x++)
                for (int y = 0; y <= amax[n-1]; y++)
                    for (int z = 0; z <= amax[n-2]; z++)
                        add(res, dp[n][x][y][z]);

        for (int i = n+1; i <= n+10; i++)
            for (int x = 1; x <= amax[i]; x++)
                for (int y = 0; y <= amax[i-1]; y++)
                    for (int z = 0; z <= amax[i-2]; z++)
                        add(res, dp[i][x][y][z]);
        printf("%d\n", res);
    }
}
