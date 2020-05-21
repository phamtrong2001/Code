#include <bits/stdc++.h>
#define PB push_back
#define N 100005
#define ll long long
using namespace std;

ll n, B;
ll sum1[N], sum2[N];
ll sum3[N], dp[N];
ll poller;
vector<ll> u, v;

struct pizza
{
    ll t, b, a;
}val[N];

bool cmp(pizza p, pizza q)
{
    return p.t < q.t;
}
void nhap()
{
    cin >> n >> B;
    for (ll i = 1; i <= n; i++)
        cin >> val[i].t >> val[i].a >> val[i].b;
    sort(val+1, val+n+1, cmp);
    for (ll i = 1; i <= n; i++)
    {
        sum1[i] = sum1[i-1] + val[i].a;
        sum2[i] = sum2[i-1] + val[i].b;
        sum3[i] = sum3[i-1] + val[i].t*val[i].b;
    }
}

bool check(ll l1, ll l2, ll l3)
{
    return (v[l3] - v[l1])*(u[l1] - u[l2]) < (v[l2] - v[l1])*(u[l1] - u[l3]);
}
void add(ll U, ll V)
{
    u.PB(U);
    v.PB(V);
    while (u.size() >= 3 && check(u.size()-3, u.size()-2, u.size()-1))
    {
        u.erase(u.end()-2);
        v.erase(v.end()-2);
    }
}

ll get(ll x)
{
    if (poller >= u.size()) poller = u.size()-1;
    while (poller < u.size()-1 && u[poller+1]*x + v[poller+1] > u[poller]*x + v[poller])
        poller++;
    return u[poller]*x + v[poller];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);

    nhap();
    add(0, 0);

    for (ll i = 1; i <= n; i++)
    {
        dp[i] = sum1[i] - val[i].t * sum2[i] + sum3[i] + get(val[i].t) - B;
        add(sum2[i], dp[i] - sum1[i] - sum3[i]);
    }
    cout <<dp[n];
}
