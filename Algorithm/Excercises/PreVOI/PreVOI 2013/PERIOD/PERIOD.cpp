#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 10000005
#define maxc 1ll*1000000000000000007

using namespace std;

ll n, delta, p, q, m, b[N], lef[N];
ll a[N];

ll solve()
{
    for (int i = 1; i <= 2*n; i++) a[i] = b[i] + 1ll*i*delta;
    deque<ll> q;
    for (int i = 1; i <= 2*n; i++)
    {
        while (!q.empty() && q.back() <= i-n) q.pop_back();
        while (!q.empty() && a[q.front()] <= a[i]) q.pop_front();
        q.push_front(i);
        lef[i] = q.back();
    }
    ll res = maxc;
    for (int i = n; i <= 2*n; i++)
        res = min(res, a[lef[i]]-1ll*(i-n)*delta);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("PERIOD.INP", "r", stdin);
    cin >> n >> delta >> p >> q >> m;
    for (int i = 1; i <= n; i++)
        b[i] = (p*i) % m + q;
    for (int i = n+1; i <= 2*n; i++) b[i] = b[i-n];
    ll res = solve();
    cout <<res;
}
