#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define ll long long
#define K 25
#define maxc 1ll*1000000000000000007

using namespace std;

ll n, k, a[N], curLeft = 0, curRight, curAns, dem[N], dp[K][N];

void upd(ll x, ll val)
{
    if (val == -1) curAns -= (dem[x] - 1);
    dem[x] += val;
    if (val == 1) curAns += (dem[x] - 1);
}
void moveLR(ll l, ll r)
{
    while (curLeft < l) upd(a[curLeft++], -1);
    while (curLeft > l) upd(a[--curLeft], 1);
    while (curRight > r) upd(a[curRight--], -1);
    while (curRight < r)
        upd(a[++curRight], 1);
}
void calc(ll id, ll l, ll r, ll x, ll y)
{
    if (l > r) return;
    ll mid = (r + l)/2;
    ll ans = maxc, pos;

    for (ll i = x; i <= min(y, mid); i++)
    {
        moveLR(i, mid);
        ll cur = dp[id-1][i-1] + curAns;
        if (cur < ans)
        {
            ans = cur;
            pos = i;
        }
    }
    dp[id][mid] = ans;
    calc(id, l, mid-1, x, pos);
    calc(id, mid+1, r, pos, y);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    cin >> n >> k;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    for (ll i = 1; i <= n; i++) dp[0][i] = maxc;
    dem[0] = 1;
    for (ll i = 1; i <= k; i++)
        calc(i, 1, n, 1, n);
    cout <<dp[k][n];
}
