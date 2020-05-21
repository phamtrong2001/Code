#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 2005
#define maxc 1000000007

using namespace std;

ll n, g, k, a[N], s[N], sumSquare[N];
ll c[N][N], dp[N][N];

ll preCalc(ll u, ll v)
{

    if (k == 1)
    {
        ll cost = 0;
        ll mid = (u + v)/2;
        cost += (mid-u+1)*a[mid] - (s[mid] - s[u-1]);
        cost += (s[v] - s[mid-1]) - (v-mid+1)*a[mid];
        return cost;
    }
    ll cost = sumSquare[v] - sumSquare[u-1];
    ll val = ((s[v] - s[u-1])) / (v - u + 1);
    ll addcost = maxc;
    for (ll i = val - 1; i <= val+1; i++)
        addcost = min(addcost, i*i*(v-u+1) - 2ll*(s[v] - s[u-1])*i);
    return cost + addcost;
}
void calc(ll id, ll l, ll r, ll x, ll y)
{
    if (l > r) return;
    ll mid = (r + l)/2;
    ll ans = maxc, pos;
    for (ll i = x; i <= min(y, mid); i++)
    {
        ll res = dp[id-1][i-1] + c[i][mid];
        if (res < ans)
        {
            ans = res;
            pos = i;
        }
    }
    dp[id][mid] = ans;
    calc(id, l, mid-1, x, pos);
    calc(id, mid+1, r, pos, y);
}

int main()
{
    freopen("INP.TXT", "r", stdin);
    cin >> n >> g >> k;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
        sumSquare[i] = sumSquare[i-1] + a[i]*a[i];
    }
    for (ll i = 1; i <= n; i++)
        for (ll j = i; j <= n; j++)
            c[i][j] = preCalc(i, j);
    for (ll i = 1; i <= n; i++) dp[1][i] = c[1][i];
    for (ll i = 2; i <= g; i++)
        calc(i, 1, n, 1, n);
    cout <<dp[g][n];
}
