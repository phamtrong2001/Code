#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007
#define ll long long
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n;
pii a[N];
void nhap()
{
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> a[i].F >> a[i].S;
}
bool cmp(pii p, pii q)
{
    return p.F*q.S < p.S*q.F;
}
void solve()
{
    sort(a+1, a+n+1, cmp);
    ll time = 0; ll res = 0;
    for (ll i = 1; i <= n; i++)
    {
        res += time*a[i].S;
        time += a[i].F;
    }
    cout <<res*2;
}
int main()
{
    freopen("FLOWERS.INP", "r", stdin);
    freopen("FLOWERS.OUT", "w", stdout);
    nhap();
    solve();
}
