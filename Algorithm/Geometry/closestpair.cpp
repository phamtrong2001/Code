/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define pii pair<int, int>
#define PB push_back
#define MP make_pair
#define ll long long
#define F first
#define S second
#define task "closestpair"
#define maxc 10000000007
#define maxn 200005

using namespace std;

int n;

pii a[maxn];

set <pii> s;

double dist(pii p, pii q)
{
    ll x = p.F - q.F;
    ll y = p.S - q.S;
    return 1.0*sqrt(x*x + y*y);
}

bool comp(pii p, pii q)
{
    return (p.S < q.S || (p.S == q.S && p.F < q.F));
}

double closest(pii a[], int n)
{
    sort(a, a+n, comp);
    s.insert(a[0]);
    int l = 0;
    double res = 1e10;
    for (int i = 1; i < n; i++)
    {
        pii p = MP(a[i].S, a[i].F);
        while (a[l].S < (p.F - res)) s.erase(a[l++]);
        for (set <pii> :: iterator it = s.lower_bound(MP(1.0*p.S-res, 1.0*p.F-res)); it != s.end() && it->F < (res + p.S); it++)
            res = min(res, dist(*it, a[i]));
        s.insert(a[i]);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].F >> a[i].S;
    printf("%0.5f", closest(a, n));
    return 0;
}
