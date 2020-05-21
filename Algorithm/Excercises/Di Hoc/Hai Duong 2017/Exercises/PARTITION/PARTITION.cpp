#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define ll long long
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 35
#define maxc 1000000007

using namespace std;

ll n, m, a[N][N], s[N][N], c[N][N], dp[N][N], res = maxc;

bool bit(ll x, ll i) {return (x >> i) & 1;}
ll calc(ll u, ll v, ll x, ll y)
{
    return s[x][y] - s[u-1][y] - s[x][v-1] + s[u-1][v-1];
}
int main()
{
    freopen("PARTITION.INP", "r", stdin);
    freopen("PARTITION.OUT", "w", stdout);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
        }

    memset(dp, 60ll, sizeof dp);
    for (ll x = 0; x < (1 << (n-1)); x++)
    {
        if (__builtin_popcount(x) > m) continue;
        vector<ll> v; v.PB(0);
        ll cur = 1;
        for (ll i = 0; i < n-1; i++)
        {
            if (bit(x, i))
                v.PB(cur);
            cur++;
        }
        v.PB(n);
        for (ll i = 1; i <= n; i++)
            for (ll j = i; j <= n; j++)
            {
                c[i][j] = 0;
                for (ll k = 1; k < v.size(); k++)
                    c[i][j] = max(c[i][j], calc(i, v[k-1]+1, j, v[k]));
            }
        for (ll i = 1; i <= n; i++)
        {
            dp[i][0] = c[1][i];
            for (ll j = 1; j < i; j++)
            {
                dp[i][j] = maxc;
                for (ll k = 1; k < i; k++)
                    dp[i][j] = min(dp[i][j], max(dp[k][j-1], c[k+1][i]));
            }
        }
        for (ll i = 0; i <= m; i++)
            if (__builtin_popcount(x) + i <= m) res = min(res, dp[n][i]);
    }
    cout <<res;
}
