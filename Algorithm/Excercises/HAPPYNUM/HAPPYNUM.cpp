#include <bits/stdc++.h>
#define ll long long
#define N 104
#define mod 1000000007

using namespace std;

ll n, k, S, f[N][N][N*82], g[N][N][N*82], a[N], half[N];
string s[N];

void inline add(ll &a, ll b) {a += b; if (a >= mod) a -= mod;}
void preDynamic()
{
    for (ll i = 0; i <= n+1; i++) f[i][0][0] = g[i][0][0] = 1;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= i; j++)
            for (ll k = S; k >= 0; k--)
            {
                add(f[i][j][k], f[i-1][j][k]);
                if (k >= a[i]) add(f[i][j][k], f[i-1][j-1][k-a[i]]);
            }
    for (ll i = n; i >= 1; i--)
        for (ll j = 1; j <= n-i+1; j++)
            for (ll k = S; k >= 0; k--)
            {
                add(g[i][j][k], g[i+1][j][k]);
                if (k >= a[i]) add(g[i][j][k], g[i+1][j-1][k-a[i]]);
            }
}
ll get(ll id, ll sum)
{
    ll ans = 0;
    for (ll i = 0; i <= sum; i++)
        for (ll j = 0; j <= n/2; j++)
            add(ans, (f[id-1][j][i]*g[id+1][n/2-j][sum-i]) % mod);
    return ans;
}
void solve()
{
    ll res = 0;
    if ((n*k % 2 == 0) && (S % 2 == 1)) {cout <<0; exit(0);}
    if (n % 2)
    {
        if (k % 2)
        {
            for (ll i = 1; i <= n; i++)
            {
                if ((S - s[i][k/2] + '0') % 2) continue;
                add(res, get(i, (S - s[i][k/2] + '0')/2 - half[i]));
            }
        }
        else
        {
            for (ll i = 1; i <= n; i++) add(res, get(i, S/2 - half[i]));
        }
    }
    else add(res, f[n][n/2][S/2]);

    ll ans = 1;
    for (ll i = 1; i <= n/2; i++) ans = (ans*i) % mod;
    cout << (res * ((ans*ans) % mod)) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("HAPPYNUM.INP", "r", stdin);
    freopen("HAPPYNUM.OUT", "w", stdout);
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
    {
        cin >> s[i];
        for (ll j = 0; j < k; j++) a[i] += (ll)(s[i][j] - '0');
        for (ll j = 0; j < k/2; j++) half[i] += (ll)(s[i][j] - '0');
        S += a[i];
    }
    preDynamic();
    solve();
}
