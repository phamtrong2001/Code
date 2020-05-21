#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

long long n, m, k, p[55], dp[104][104][11], sum[104][104], ans[105];

void DFS(long long u, long long mod, long long val)
{
    if (n % 2 == 1 && u == n/2+2) return;
    if (n % 2 == 0 && u == n/2+1) return;
    for (long long i = 0; i <= 9; i++)
    {
        if (val > dp[u][mod][i]) val -= dp[u][mod][i];
        else
        {
            long long x = p[u-1] + p[n-u];
            if (n % 2 == 1 && u == n/2+1) x = p[u-1];
            mod = ((mod - i*(p[u-1] + p[n-u])) % m + m) % m;
            ans[u] = ans[n-u+1] = i;
            DFS(u+1, mod, val);
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("PALINN.INP", "r", stdin);
    freopen("PALINN.OUT", "w", stdout);
    cin >> n >> m >> k;
    p[0] = 1;
    for (long long i = 1; i <= 45; i++) p[i] = (p[i-1]*10) % m;
    if (n == 1)
    {
        vector<long long> v;
        for (long long i = 1; i < 10; i++)
            if (i % m == 0) v.PB(i);
        cout <<v.size()<<endl<<v[k-1];
        return 0;
    }
    if (n % 2 == 0) sum[n/2+1][0] = 1;
    else for (long long i = 0; i <= 9; i++)
        dp[n/2+1][i*p[n/2] % m][i]++, sum[n/2+1][i*p[n/2] % m]++;
    for (long long i = n/2; i >= 1; i--)
        for (long long j = 0; j < m; j++)
            for (long long c = 0; c <= 9; c++)
            {
                if (i == 1 && c == 0) continue;
                long long x = (j + c*(p[i-1] + p[n-i])) % m;
                dp[i][x][c] += sum[i+1][j];
                sum[i][x] += sum[i+1][j];
            }
    cout <<sum[1][0]<<endl;
    DFS(1, 0, k);
    for (long long i = 1; i <= n; i++) cout <<ans[i];
}
