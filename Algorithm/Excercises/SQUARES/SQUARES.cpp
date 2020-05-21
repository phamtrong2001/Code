#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define mod (1ll*1000000007)

using namespace std;

ll n, l, res;

ll Pow(ll a, ll b)
{
    if (b == 0) return 1;
    ll x = Pow(a, b/2);
    x = (x * x) % mod;
    if (b % 2) return (x * a) % mod;
    return x;
}
int main()
{
    freopen("SQUARES.INP", "r", stdin);
    freopen("SQUARES.OUT", "w", stdout);
    cin >> n >> l;
    res = (l*l) % mod;
    res = (res*Pow(3, mod-2)) % mod;
    ll cur = (Pow(4, n+1) + mod-1) % mod;
    cout <<(res*cur) % mod;
}
