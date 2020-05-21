#include <bits/stdc++.h>
#define N 100005
#define mid (l + r)/2
#define ll long long

using namespace std;

long long n, q, a[N], f[N], d[N];

map<long long, ll> dd;
struct llervalTree
{
    ll t[N << 2];
    void build(ll l, ll r, ll id)
    {
        if (l == r)
        {
            t[id] = d[l];
            return;
        }
        build(l, mid, id*2);
        build(mid+1, r, id*2+1);
        t[id] = max(t[id*2], t[id*2+1]);
    }
    ll get_max(ll l, ll r, ll id, ll x, ll y)
    {
        if (l > y || r < x) return 0;
        if (l >= x && r <= y) return t[id];
        ll a = get_max(l, mid, id*2, x, y);
        ll b = get_max(mid+1, r, id*2+1, x, y);
        return max(a, b);
    }
}t;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("INP.TXT", "r", stdin);
    cin >> n >> q;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    f[1] = 1; dd[a[1]] = 1;
    for (ll i = 2; i <= n; i++)
    {
        f[i] = max(f[i-1], dd[a[i]] + 1);
        dd[a[i]] = i;
    }
    for (ll i = 1; i <= n; i++) d[i] = i - f[i] + 1;
    t.build(1, n, 1);
    for (ll i = 1; i <= q; i++)
    {
        ll u, v; cin >> u >> v;
        u++; v++;
        ll pos = lower_bound(f+1, f+n+1, u) - f;
        if (pos > v)
        {
            cout <<v - u + 1<<'\n';
            continue;
        }
        cout <<max(pos - u, t.get_max(1, n, 1, pos, v))<<'\n';
    }
}
