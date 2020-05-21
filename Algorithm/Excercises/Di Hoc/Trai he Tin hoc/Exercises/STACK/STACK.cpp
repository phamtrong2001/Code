#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 3000
#define maxc 1000000007
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, dp[N][N];
pii a[N];
void nhap()
{
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> a[i].F;
    for (ll i = 1; i <= n; i++) cin >> a[i].S;
}
bool cmp(pii p, pii q)
{
    return p.F+p.S < q.F+q.S;
}
void solve()
{
    sort(a+1, a+n+1, cmp);
    for (ll i = 0; i <= n; i++)
        for (ll j = 0; j <= i; j++) dp[i][j] = 1ll*maxc*maxc;
    //dp[1][1] = a[1].F;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= i; j++)
        {
            dp[i][j] = dp[i-1][j];
            ll z;
            if (i == 1) z = 0;
            else z = dp[i-1][j-1];
            if (a[i].S >= z) dp[i][j] = min(dp[i][j], z + a[i].F);
        }
    ll res = 0;
    for (ll i = 1; i <= n; i++)
        if (dp[n][i] != 1ll*maxc*maxc) res = i;
    cout <<res;
}
int main()
{
    //freopen("STACK.INP", "r", stdin);
    //freopen("STACK.OUT", "w", stdout);
    nhap();
    solve();

}
