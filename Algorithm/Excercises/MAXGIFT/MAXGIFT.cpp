#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 305
#define ll long long
#define maxc 1ll*1000000000000000007

using namespace std;

ll n, k, a[N], c[N][N], dp[N][N], tr[N][N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("MAXGIFT.INP", "r", stdin);
    freopen("MAXGIFT.OUT", "w", stdout);

    cin >> n >> k;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    for (ll i = 1; i <= n; i++)
    {
        c[i][i] = a[i];
        for (ll j = i+1; j <= n; j++) c[i][j] = min(c[i][j-1], a[j]);
    }
    for (ll i = 1; i <= n; i++) dp[i][0] = -maxc;
    for (ll j = 1; j <= k; j++)
        for (ll i = 1; i <= n; i++)
            for (ll h = i; h >= j; h--)
                if (dp[i][j] < dp[h-1][j-1] + c[h][i])
                {
                    dp[i][j] = dp[h-1][j-1] + c[h][i];
                    tr[i][j] = h-1;
                }
    cout <<dp[n][k]<<endl;
    ll i = k; ll j = n;
    vector<ll> ans;
    while (i > 0)
    {
        j = tr[j][i];
        i--;
        ans.PB(j);
    }
    for (ll i = ans.size()-2; i >= 0; i--) cout <<ans[i]<<' ';
}
