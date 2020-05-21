#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define MOD 1000000007
#define ll long long

using namespace std;

ll n, a[71], f[1 << 20], g[1 << 20], state[70];
ll prime[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
main()
{
    freopen("INP.TXT", "r", stdin);
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll x; cin >> x;
        a[x]++;
    }
    for (ll i = 1; i <= 70; i++)
    {
        ll x = i;
        for (ll j = 0; j < 19; j++)
            while (x % prime[j] == 0)
            {
                x /= prime[j];
                state[i] ^= (1 << j);
            }
    }
    g[0] = 1;
    for (ll i = 1; i <= 70; i++)
    {
        ll haha = 1;
        for (ll j = 1; j < a[i]; j++) haha = (haha*2) % MOD;
        for (ll x = 0; x < (1 << 19); x++)
        {
            if (a[i]) f[x] = (f[x] + g[x^state[i]]*haha) % MOD;
            f[x] = (f[x] + g[x]*haha) % MOD;
        }
        for (int i = 0; i < (1 << 19); i++)
        {
            g[i] = f[i];
            f[i] = 0;
        }
    }
    cout <<(g[0] + MOD - 1) % MOD;
}
