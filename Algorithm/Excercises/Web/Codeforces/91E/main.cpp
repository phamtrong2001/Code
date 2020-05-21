#include <bits/stdc++.h>
#define ll long long
#define mid (l + r)/2
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1ll*1000000000000000007

using namespace std;

ll n, m, da[N], db[N], res[N];
pair<pii, ll> all[N];

struct ITConvexHull
{
    vector<ll> U[N << 2], V[N << 2], ID[N << 2];
    ll poller[N << 2];

    bool bad(ll id, ll l1, ll l2, ll l3)
    {
        return (V[id][l2] - V[id][l1])*(U[id][l1] - U[id][l3]) > (V[id][l3] - V[id][l1])*(U[id][l1] - U[id][l2]);
    }
    void add(ll u, ll v, ll Id, ll id)
    {
        U[id].PB(u); V[id].PB(v); ID[id].PB(Id);
        while (U[id].size() >= 3 && bad(id, U[id].size()-3, U[id].size()-2, U[id].size()-1))
        {
            U[id].erase(U[id].end()-2);
            V[id].erase(V[id].end()-2);
            ID[id].erase(ID[id].end()-2);
        }
    }
    void build(ll l, ll r, ll id)
    {
        if (l == r)
        {
            add(da[l], db[l], l, id);
            return;
        }
        ll cur = 0;
        for (int i = l; i <= r; i++)
            all[++cur] = mp(mp(da[i], -db[i]), i);
        sort(all+1, all+cur+1);
        for (int i = 1; i <= cur; i++)
            if (all[i].F.F != all[i-1].F.F)
                add(all[i].F.F, -all[i].F.S, all[i].S, id);
        build(l, mid, id*2);
        build(mid+1, r, id*2+1);
    }
    pii getans(ll id, ll val)
    {
        if (poller[id] >= U[id].size()) poller[id] = U[id].size()-1;
        while (poller[id] < U[id].size()-1 && U[id][poller[id]]*val + V[id][poller[id]] < U[id][poller[id]+1]*val + V[id][poller[id]+1])
            poller[id]++;
        return mp(U[id][poller[id]]*val + V[id][poller[id]], ID[id][poller[id]]);
    }
    pii get(ll l, ll r, ll id, ll x, ll y, ll val)
    {
        if (l > y || r < x)
            return mp(-maxc, 0);
        if (l >= x && r <= y)
            return getans(id, val);
        pii a = get(l, mid, id*2, x, y, val);
        pii b = get(mid+1, r, id*2+1, x, y, val);
        return max(a, b);
    }
}t;

struct query
{
    ll l, r, t, id;
    void nhap(ll x)
    {
        cin >> l >> r >> t;
        id = x;
    }

    bool operator < (const query &foo) const
    {
        return t < foo.t;
    }
}q[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("INP.TXT", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> db[i] >> da[i];
    t.build(1, n, 1);
    for (int i = 1; i <= m; i++)
        q[i].nhap(i);
    sort(q+1, q+m+1);
    for (int i = 1; i <= m; i++)
        res[q[i].id] = t.get(1, n, 1, q[i].l, q[i].r, q[i].t).S;
    for (int i = 1; i <= m; i++)
        cout <<res[i]<<'\n';
}
