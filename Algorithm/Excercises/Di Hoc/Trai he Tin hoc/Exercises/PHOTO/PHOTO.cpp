#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1000005
#define mod 1000000007
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, m, k, p[N], f[N];
void prepare()
{
    cin >> n >> m >> k;
    p[0] = 1; f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = (p[i-1]*2) % mod;
        f[i] = (f[i-1]*i) % mod;
    }
}
ll power(ll a, ll b)
{
    if (b == 0) return 1;
    ll x = power(a, b/2);
    x = (x * x) % mod;
    if (b % 2) return (x * a) % mod;
    return x;
}
long long chia(long long x, long long y)
{
    long long z = power(y, mod-2);
    return (x * z) % mod;
}
long long C(long long n, long long k)
{
    long long z = (f[k]*f[n-k]) % mod;
    long long res = chia(f[n], z);
    return res;
}

int main()
{
    prepare();
    if (n + 1 != k || m > n) {cout <<0; return 0;}
    ll res = C(n, m);
    res = (res * p[m]) % mod;
    cout <<res<<endl;
}
