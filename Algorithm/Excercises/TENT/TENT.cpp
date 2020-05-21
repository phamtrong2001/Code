#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define mod 1000000007

using namespace std;

ll n, k, p[N], dp[N];

ll Pow(ll a, ll b)
{
    if (b == 0) return 1;
    ll x = Pow(a, b/2);
    x = (x * x) % mod;
    if (b % 2) return (x * a) % mod;
    return x;
}

ll C(ll n, ll k)
{
    ll x = p[n];
    ll y = (p[k]*p[n-k]) % mod;
    x = (x * Pow(y, mod-2)) % mod;
    return x;
}
int main()
{
    freopen("TENT.INP", "r", stdin);
    freopen("TENT.OUT", "w", stdout);
    cin >> n >> k;
    p[0] = 1;
    for (ll i = 1; i <= n; i++)
        p[i] = (p[i-1]*i) % mod;
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
        dp[i] = ((i-1)*(dp[i-1] + dp[i-2])) % mod;
    cout <<(C(n, k) * dp[n-k]) % mod;
}
