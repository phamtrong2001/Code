#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define mid (r + l)/2
#define ll long long
#define maxc 1000000007

using namespace std;

ll n, a[N], dp[N], lmin[N], lmax[N];

struct llervalTree
{
    ll t[N << 2];
    void update(ll l, ll r, ll id, ll x, ll val)
    {
        if (l == r)
        {
            t[id] = val;
            return;
        }
        if (x <= mid) update(l, mid, id*2, x, val);
        else update(mid+1, r, id*2+1, x, val);
        t[id] = max(t[id*2], t[id*2+1]);
    }
    ll get_max(ll l, ll r, ll id, ll x, ll y)
    {
        if (x > y) return -maxc;
        if (l > y || r < x) return -maxc;
        if (l >= x && r <= y) return t[id];
        ll a = get_max(l, mid, id*2, x, y);
        ll b = get_max(mid+1, r, id*2+1, x, y);
        return max(a, b);
    }
}t1, t2;

void prepare()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    stack<ll> s;
    a[0] = maxc;
    s.push(0);
    for (ll i = 1; i <= n; i++)
    {
        while (!s.empty() && a[s.top()] < a[i]) s.pop();
        lmax[i] = s.top();
        s.push(i);
    }
    a[0] = -maxc;
    while (!s.empty()) s.pop(); s.push(0);
    for (ll i = 1; i <= n; i++)
    {
        while (!s.empty() && a[s.top()] > a[i]) s.pop();
        lmin[i] = s.top();
        s.push(i);
    }
    memset(dp, -60, sizeof dp);
    dp[0] = 0;
    t1.update(1, n, 1, 1, -a[1]);
    t2.update(1, n, 1, 1, a[1]);
    for (ll i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i], dp[i-1]);
        dp[i] = max(dp[i], t1.get_max(1, n, 1, lmax[i]+1, i-1) + a[i]);
        dp[i] = max(dp[i], t2.get_max(1, n, 1, lmin[i]+1, i-1) - a[i]);
        t1.update(1, n, 1, i+1, dp[i] - a[i+1]);
        t2.update(1, n, 1, i+1, dp[i] + a[i+1]);
    }
    cout <<dp[n];
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    prepare();
}
