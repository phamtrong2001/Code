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
#define task "metarain"
#define maxc 1000000007
#define maxn 5003

using namespace std;

int n, m;

pii a[maxn];

void nhap()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].F >> a[i].S;
}

pii vect(pii u, pii v)
{
    return MP(u.F - v.F, u.S - v.S);
}

long long CCW(pii p, pii q, pii r)
{
    pii u = vect(p, q);
    pii v = vect(p, r);
    return (1ll * u.F * v.S - 1ll * u.S * v.F);
}

long long SS(pii p, pii q, pii r)
{
    return (p.F - q.F)*(p.S + q.S) + (q.F - r.F)*(q.S + r.S) + (r.F - p.F)*(r.S + p.S);
}

bool check(pii b)
{
    int l = 2;
    int r = n;
    while (r - l > 1)
    {
        int mid = (l + r) >> 1;
        if (CCW(a[1], a[mid], b) > 0) l = mid;
            else r = mid;
    }
    if (l == 2 && CCW(a[1], a[2], b) <= 0) return 0;
    if (r == n && CCW(a[1], a[n], b) >= 0) return 0;
    long long s1 = abs(SS(a[1], a[l], b));
    long long s2 = abs(SS(a[l], a[r], b));
    long long s3 = abs(SS(a[1], a[r], b));
    long long s = abs(SS(a[1], a[l], a[r]));
    if (s2 == 0) return 0;
    if (s1 + s2 + s3 == s) return 1;
    return 0;
}

void xuli()
{
    pii b;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> b.F >> b.S;
        if (check(b)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    nhap();
    xuli();
    return 0;
}
