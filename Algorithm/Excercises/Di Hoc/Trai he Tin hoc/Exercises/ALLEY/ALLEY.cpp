#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 505
#define mod 20152015
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define full x[1]][x[2]][x[3]][x[4]][x[5]

using namespace std;

long long n, x[10], u[10];
long long dp[505][3][3][3][3][3];
char c[N][6];
void nhap()
{
    cin >> n;
    for (long long i = 1; i <= n; i++)
        for (long long j = 1; j <= 5; j++) cin >> c[i][j];
}

bool check()
{
    for (long long i = 1; i < 5; i++)
        if (u[i] == u[i+1] && u[i] == x[i] && x[i] == x[i+1] && x[i] != 2) return 0;
    return 1;
}
void cal(long long pos)
{
    for (u[1] = 0; u[1] <= 2; u[1]++)
        for (u[2] = 0; u[2] <= 2; u[2]++)
            for (u[3] = 0; u[3] <= 2; u[3]++)
                for (u[4] = 0; u[4] <= 2; u[4]++)
                    for (u[5] = 0; u[5] <= 2; u[5]++)
                        if (check()) dp[pos][full] = (dp[pos][full] + dp[pos-1][u[1]][u[2]][u[3]][u[4]][u[5]]) % mod;
}
void duyet(long long u, long long pos)
{
    if (pos > 5)
    {
        cal(u);
        return;
    }
    if (c[u][pos] == 'x')
    {
        x[pos] = 2;
        duyet(u, pos+1);
        return;
    }
    for (long long i = 0; i <= 1; i++)
    {
        x[pos] = i;
        duyet(u, pos+1);
    }
}
void solve()
{
    dp[0][2][2][2][2][2] = 1;
    for (long long i = 1; i <= n; i++) duyet(i, 1);
    long long res = 0;
    for (u[1] = 0; u[1] <= 2; u[1]++)
        for (u[2] = 0; u[2] <= 2; u[2]++)
            for (u[3] = 0; u[3] <= 2; u[3]++)
                for (u[4] = 0; u[4] <= 2; u[4]++)
                    for (u[5] = 0; u[5] <= 2; u[5]++) res = (res + dp[n][u[1]][u[2]][u[3]][u[4]][u[5]]) % mod;
    cout <<res;
}

int main()
{
    //freopen("ALLEY.INP", "r", stdin);
    nhap();
    solve();

}
