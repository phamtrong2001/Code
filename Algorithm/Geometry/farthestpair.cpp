/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define PB push_back
#define MP make_pair
#define ll long long
#define F first
#define S second
#define task "farthestpair"
#define maxc 1000000007
#define maxn 200005

using namespace std;

int n, j, k;

pii a[maxn];
vector <pii> u, d;

pii vect(pii p, pii q)
{
    return MP(q.F - p.F, q.S - p.S);
}

long long CCW(pii p, pii q, pii r)
{
    pii u = vect(p, q);
    pii v = vect(q, r);
    return (1ll * u.F * v.S - 1ll * u.S * v.F);
}

void make_convex(pii a[], vector <pii> &u, vector <pii> &d)
{
    sort(a, a+n);
    int j = 0, k = 0;
    u.resize(2*n);
    d.resize(2*n);
    for (int i = 0; i < n; i++)
    {
        while (k >= 2 && CCW(u[k-2], u[k-1], a[i]) >= 0) k--;
        u[k++] = a[i];
        while (j >= 2 && CCW(d[j-2], d[j-1], a[i]) <= 0) j--;
        d[j++] = a[i];
    }
    u.resize(k);
    d.resize(j);
}

ll dist(pii p, pii q)
{
    return ((p.F-q.F)*(p.F-q.F) + (p.S-q.S)*(p.S-q.S));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].F >> a[i].S;
    if (n == 1)
    {
        cout << 0 << '\n';
        return 0;
    }
    u.clear();
    d.clear();
    make_convex(a, u, d);
//    for (int i = 0; i < u.size(); i++)
//        cout << u[i].F << " " << u[i].S << '\n';
//    for (int i = 0; i < d.size(); i++)
//        cout << d[i].F << " " << d[i].S << '\n';
    ll res = LONG_MIN;
    int i = 0;
    j = u.size()-1;
    k = d.size()-1;
    while (i < j || k > 0)
    {
        res = max(res, dist(u[i], d[k]));
        if (i == j) k--;
            else if (k == 0) i++;
                else
                {
                    if ((u[i+1].S-u[i].S)*(d[k].F-d[k-1].F) > (d[k].S - d[k-1].S)*(u[i+1].F-u[i].F)) i++;
                        else k--;
                }
    }
    cout << res << '\n';
    return 0;
}
