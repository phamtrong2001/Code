/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pii pair<int, int>
#define sz(x) ((int) x.size())
#define PB push_back
#define PF push_front
#define MP make_pair
#define ll long long
#define F first
#define S second
#define maxc 1000000007
#define MOD 1000000007
#define base 107
#define eps 1e-6
#define maxn 13
#define task "bgame"
#define remain(x) ((x > MOD) ? (x - MOD) : x)

using namespace std;

int n, k, x[maxn], y[maxn], dp[1<<maxn][maxn], w[maxn], c[1<<maxn], h[maxn], g[maxn];

pii pos, a[maxn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> k;
    FOR(i, 1, n)
        cin >> x[i] >> y[i];
    FOR(i, 1, n)
        w[i] = abs(pos.F - a[i].F) + abs(pos.S - a[i].S);
    FOR(xx, 1, (1 << n)-1)
    {
        int dem = 0;
        FOR(i, 0, n-1)
            if ((xx >> i) & 1)
            {
                g[++dem] = x[i+1];
                h[dem] = y[i+1];
                a[dem] = MP(x[i+1], y[i+1]);
            }
        sort(g+1, g+dem+1);
        sort(h+1, h+dem+1);
        pos = MP(g[(dem+1)/2], h[(dem+1)/2]);
        FOR(i, 1, dem)
            c[xx] += abs(a[i].F - pos.F) + abs(a[i].S - pos.S);
    }
    memset(dp, 0x32, sizeof(dp));
    dp[0][0] = 0;
    FOR(i, 1, k)
        FOR(s, 0, (1 << n) - 1)
            for (int m = s; m; m = (m-1) & s)
                dp[s][i] = min(dp[s][i], dp[s^m][i-1] + c[m]);
    cout << dp[(1 << n)-1][k];
    return 0;
}
