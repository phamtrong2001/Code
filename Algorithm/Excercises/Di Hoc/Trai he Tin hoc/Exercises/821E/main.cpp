#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 105
#define ll long long
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, k, l[N], r[N], c[N], xx;

struct matrix
{
    ll a[16][16];
    matrix()
    {
        memset(a, 0, sizeof a);
    }
};

matrix nhan(matrix p, matrix q)
{
    matrix kk = matrix();
    for (ll i = 0; i <= xx; i++)
        for (ll j = 0; j <= xx; j++)
            for (ll k = 0; k <= xx; k++)
                kk.a[i][j] = (kk.a[i][j] + p.a[i][k]*q.a[k][j] % mod) % mod;
    return kk;
}
matrix power(matrix a, ll b)
{
    if (b == 1) return a;
    matrix x = power(a, b/2);
    x = nhan(x, x);
    if (b % 2) return nhan(x, a);
    return x;
}
void nhap()
{
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
        cin >> l[i] >> r[i] >> c[i];
    r[n] = k;
}
void solve()
{
    matrix res = matrix();
    res.a[0][0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        matrix zz = matrix();

        for (ll j = 0; j <= c[i]; j++)
            for (ll z = max(0ll, j-1); z <= min(c[i], j+1); z++) zz.a[j][z] = 1;
        xx = c[i];
        if (r[i] - l[i] > 0)
        {
            zz = power(zz, r[i] - l[i]);
            res = nhan(res, zz);
        }
    }
    cout <<res.a[0][0];
}

int main()
{
    freopen("INP.TXT", "r", stdin);
    nhap();
    solve();
    return 0;
}
