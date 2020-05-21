#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define maxn 100005
#define mod 100003

using namespace std;

ll n, m, p[maxn];

vector<ll> getRepresentation(ll N)
{
    vector<ll> res;
    while (N > 0)
    {
        res.PB(N % mod);
        N /= mod;
    }
    return res;
}
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
    if (k > n) return 0;
    return (((p[n]*Pow(p[k], mod-2)) % mod)*Pow(p[n-k], mod-2)) % mod;
}
ll calc(ll N, ll K)
{
    if (K > N) return 0;
    vector<ll> a = getRepresentation(N);
    vector<ll> b = getRepresentation(K);
    ll res = 1;
    for (ll i = 0; i < b.size(); i++)
        res = (res * C(a[i], b[i])) % mod;
    return res;
}
int main()
{
    freopen("C11TCT.INP", "r", stdin);
    ll Tests; cin >> Tests;
    p[0] = 1;
    for (ll i = 1; i < maxn; i++) p[i] = (p[i-1]*i) % mod;
    while (Tests--)
    {
        cin >> m >> n;
        ll ans = (calc(m-n, n) + calc(m-1-(n-1), n-1)) % mod;
        cout <<ans<<endl;
    }
}
