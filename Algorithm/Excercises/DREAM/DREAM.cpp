#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 205
#define M 1005
#define maxc 1000000007

using namespace std;

ll n, m, k, mod, dem[N][M], c[N][M], dp[N][M], id[M*M], cnt;
vector<ll> alldiv;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("DREAM.INP", "r", stdin);
    freopen("DREAM.OUT", "w", stdout);
    cin >> n >> m >> k >> mod;
    for (int i = 1; i <= k; i++)
        if (k % i == 0)
        {
            alldiv.PB(i);
            id[i] = ++cnt;
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1, x; j <= m; j++)
        {
            cin >> x;
            x = __gcd(1ll*x, k);
            dem[i][id[x]] = (dem[i][id[x]] + 1) % mod;
        }
    for (int i = 1; i <= n; i++)
        for (auto x : alldiv) c[i][id[x]] = dem[i][id[x]];
    for (int i = 2; i < n; i++)
    {
        for (auto x : alldiv)
            for (auto y : alldiv)
                if (x != y)
                {
                    ll z = __gcd(1ll*x*y, 1ll*k);
                    c[i][id[z]] = (c[i][id[z]] + dem[i][id[x]]*dem[i][id[y]]) % mod;
                }
        for (auto x : alldiv)
        {
            ll z = __gcd(1ll*x*x, 1ll*k);
            c[i][id[z]] = (c[i][id[z]] + dem[i][id[x]]*(dem[i][id[x]]-1)) % mod;
        }
    }
    for (auto x : alldiv) dp[1][id[x]] = c[1][id[x]];
    for (int i = 2; i <= n; i++)
        for (auto x : alldiv)
            for (auto y : alldiv)
            {
                ll z = __gcd(1ll*x*y, 1ll*k);
                dp[i][id[z]] = (dp[i][id[z]] + dp[i-1][id[x]]*c[i][id[y]]) % mod;
            }
    cout <<dp[n][id[k]];
}
