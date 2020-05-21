#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 105
#define mod 1000000007

using namespace std;

ll n, tests, sz[N], dd[N][N], dp[1 << 11][N];

bool bit(ll x, ll i) {return (x >> i) & 1;}
ll calc(ll mask, ll tid)
{
    if (tid > 100)
    {
        if (mask == (1 << n) - 1) return dp[mask][tid] = 1;
        return dp[mask][tid] = 0;
    }
    if (dp[mask][tid] != -1) return dp[mask][tid];

    ll ans = calc(mask, tid+1);
    for (ll i = 1; i <= n; i++)
    {
        if (dd[i][tid] && !bit(mask, i-1))
            ans += calc(mask | (1 << (i-1)), tid+1);
        if (ans >= mod) ans -= mod;
    }
    return dp[mask][tid] = ans;
}
int main()
{
    freopen("TSHIRTS.INP", "r", stdin);
    freopen("TSHIRTS.OUT", "w", stdout);
    ll tests; cin >> tests;
    while (tests--)
    {
        memset(dd, 0, sizeof dd);
        memset(sz, 0, sizeof sz);
        memset(dp, -1, sizeof dp);
        cin >> n;
        string s; getline(cin, s);
        for (ll i = 1; i <= n; i++)
        {
            getline(cin, s);
            stringstream ss;
            ss << s;
            ll x;
            while (ss >> x) {dd[i][x] = 1; sz[i]++;}
        }
        cout <<calc(0, 1)<<endl;
    }
}
