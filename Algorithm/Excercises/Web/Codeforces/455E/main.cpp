#include <bits/stdc++.h>
#define N 100005
#define ll long long
#define maxc 1000000007
#define mid (r + l)/2
#define PB push_back

using namespace std;
ll n, a[N], vx[N], vy[N], s[N];
struct CHT
{
    vector<ll> U, V;

    bool bad(ll l1, ll l2, ll l3)
    {
        return (V[l3] - V[l1])*(U[l1] - U[l2]) > (V[l2] - V[l1])*(U[l1] - U[l3]);
    }
    void add(ll u, ll v)
    {
        if (U.size() > 0 && U[U.size()-1] == u) return;
        U.PB(u); V.PB(v);
        while (U.size() >= 3 && bad(U.size()-3, U.size()-2, U.size()-1))
        {
            U.erase(U.end()-2);
            V.erase(V.end()-2);
        }
    }
    ll get(ll x)
    {
        ll l = 0, r = U.size()-1;
        while (r > l)
        {
            if (U[mid]*x + V[mid] <= U[mid+1]*x + V[mid+1]) r = mid;
            else l = mid+1;
        }
        if (r > 0 && U[r-1]*x + V[r-1] < U[r]*x + V[r]) --r;
        if (r < U.size() - 1 && U[r+1]*x + V[r+1] < U[r]*x + V[r]) ++r;
        return U[r]*x + V[r];
    }
};

struct llervalTree
{
    CHT t[N << 2];

    void Merge(ll id)
    {
        ll i = 0, j = 0;
        while (i < t[id*2].U.size() && j < t[id*2+1].U.size())
        {
            if (t[id*2].U[i] > t[id*2+1].U[j] || (t[id*2].U[i] == t[id*2+1].U[j] && t[id*2].V[i] > t[id*2+1].V[j]))
                t[id].add(t[id*2+1].U[j], t[id*2+1].V[j]), j++;
            else
                t[id].add(t[id*2].U[i], t[id*2].V[i]), i++;
        }
        while (i < t[id*2].U.size()) t[id].add(t[id*2].U[i], t[id*2].V[i]), i++;
        while (j < t[id*2+1].U.size()) t[id].add(t[id*2+1].U[j], t[id*2+1].V[j]), j++;
    }
    void build(ll l, ll r, ll id)
    {
        if (l == r)
        {
            t[id].add(vx[l], vy[l]);
            return;
        }
        build(l, mid, id*2);
        build(mid+1, r, id*2+1);
        Merge(id);
    }
    ll get_ans(ll l, ll r, ll id, ll x, ll y, ll val)
    {
        if (l > y || r < x) return 1ll*maxc*maxc;
        if (l >= x && r <= y) return t[id].get(val);
        ll a = get_ans(l, mid, id*2, x, y, val);
        ll b = get_ans(mid+1, r, id*2+1, x, y, val);
        return min(a, b);
    }
}t;
int main()
{
    //freopen("INP.TXT", "r", stdin);
    scanf("%I64d", &n);
    for (ll i = 1; i <= n; i++) scanf("%I64d", &a[i]), s[i] = s[i-1] + a[i];
    for (ll i = 1; i <= n; i++)
    {
        vx[i] = a[i];
        vy[i] = i*a[i] - s[i];
    }
    t.build(1, n, 1);
    ll m; scanf("%I64d", &m);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v; scanf("%I64d %I64d", &u, &v);
        printf("%I64d\n", s[v] + t.get_ans(1, n, 1, v-u+1, v, u-v));
    }
}
