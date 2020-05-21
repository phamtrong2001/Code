#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second
#define PB push_back
#define mod 1000000007
#define N 1000005


using namespace std;

int n, a[N], p[N], c[N], d[N], res[N], ans;

void nhap()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    p[0] = 1;
    for (int i = 1; i < N; i++) p[i] = (p[i-1]*2) % mod;

    for (int i = 1; i < N; i++) c[i] = 1ll*(1ll*p[i-1]*i) % mod;
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sqrt(a[i]); j++)
        {
            if (a[i] % j) continue;
            d[j]++;
            d[a[i]/j]++;
        }
        int can = sqrt(a[i]);
        if (can*can == a[i]) d[can]--;
    }
    for (int i = N-1; i >= 2; i--)
    {
        int cur = c[d[i]];
        for (int j = i*2; j < N; j += i)
            cur = (cur - res[j] + mod) % mod;
        res[i] = cur;
        ans = (ans + (1ll*res[i]*i) % mod) % mod;
    }
    printf("%d", ans);
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    nhap();
    solve();
}
