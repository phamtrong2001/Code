#include <bits/stdc++.h>
#define N 100005
#define ll unsigned long long
#define PB push_back
using namespace std;

ll n, a[N], b[N], poller, trace[N];

ll dp[N];
vector<ll> u, v, id;

void nhap()
{
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    for (ll i = 1; i <= n; i++) cin >> b[i];
}

bool check(ll l1, ll l2, ll l3)
{
    return (v[l3] - v[l1])*(u[l1] - u[l2]) < (v[l2] - v[l1])*(u[l1] - u[l3]);
}
void add(ll U, ll V, ll ID)
{
    u.PB(U);
    v.PB(V);
    id.PB(ID);
    while (u.size() >= 3 && check(u.size()-3, u.size()-2, u.size()-1))
    {
        u.erase(u.end()-2);
        v.erase(v.end()-2);
        id.erase(id.end()-2);
    }
}

ll get(ll x)
{
    if (poller >= u.size()) poller = u.size()-1;
    while (poller < u.size()-1 && u[poller+1]*x + v[poller+1] < u[poller]*x + v[poller])
        poller++;
    return u[poller]*x + v[poller];
}
void solve()
{
    dp[1] = 0;
    add(b[1], dp[1],1);
    for (ll i = 2; i <= n; i++)
    {
        dp[i] = get(a[i]);
        trace[i] = id[poller];
        add(b[i], dp[i],i);
    }
    cout <<dp[n];
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    nhap();
    solve();
}
