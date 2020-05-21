#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define MM 300
#define ll long long
#define maxc 1000000007

using namespace std;


ll n, k, type[N], s[N], RR[3*N], dem[3*N], res[N], lef[N], rig[N], cur, curAns;
pair<pii, ll> q[N];

bool cmpQuery(pair<pii, ll> u, pair<pii, ll> v)
{
    if (u.F.F / MM != v.F.F / MM) return u.F.F < v.F.F;
    return u.F.S < v.F.S;
}
void upd(ll id, ll val, ll tt)
{
    ll z = lef[id];
    if (tt == 2) z = rig[id];
    if (val == 1)
    {
        curAns += dem[z];
        dem[s[id]]++;
    }
    else
    {
        dem[s[id]]--;
        curAns -= dem[z];
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    cin >> n >> k;
    for (ll i = 1; i <= n; i++) cin >> type[i];
    for (ll i = 1; i <= n; i++)
    {
        ll x; cin >> x;
        if (type[i] == 2) x = -x;
        s[i] = s[i-1] + x;
        RR[++cur] = s[i];
        RR[++cur] = s[i] - k;
        RR[++cur] = s[i] + k;
    }
    RR[++cur] = 0; RR[++cur] = -k; RR[++cur] = k;
    sort(RR+1, RR+cur+1);
    cur = unique(RR+1, RR+cur+1) - RR - 1;
    for (ll i = 0; i <= n; i++)
    {
        lef[i] = lower_bound(RR+1, RR+cur+1, s[i] - k) - RR;
        rig[i] = lower_bound(RR+1, RR+cur+1, s[i] + k) - RR;
        s[i] = lower_bound(RR+1, RR+cur+1, s[i]) - RR;
    }
    ll numQuery; cin >> numQuery;
    for (ll i = 1; i <= numQuery; i++)
    {
        cin >> q[i].F.F >> q[i].F.S; q[i].F.F--;
        q[i].S = i;
    }
    sort(q+1, q+numQuery+1, cmpQuery);
    ll l = 0, r = -1;
    for (ll i = 1; i <= numQuery; i++)
    {
        while (l > q[i].F.F) upd(--l, 1, 2);
        while (r < q[i].F.S) upd(++r, 1, 1);
        while (l < q[i].F.F) upd(l++, -1, 2);
        while (r > q[i].F.S) upd(r--, -1, 1);
        res[q[i].S] = curAns;

    }
    for (ll i = 1; i <= numQuery; i++) cout <<res[i]<<'\n';
}
