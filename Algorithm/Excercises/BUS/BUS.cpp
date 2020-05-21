#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a, b, c, t1, t2;

ll gcd(ll a, ll b, ll &x, ll &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return d;
}
int main()
{
    freopen("BUS.INP", "r", stdin);
    freopen("BUS.OUT", "w", stdout);
    ll t; scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld %lld %lld %lld", &a, &b, &t1, &t2);
        if (t2 < t1) {swap(a, b); swap(t1, t2);}
        c = t2 - t1;
        b = -b;
        ll x0, y0;
        ll g = gcd(a, -b, x0, y0);

        y0 = -y0;
        if (c % g)
        {
            printf("-1\n");
            continue;
        }
        x0 *= c/g;
        y0 *= c/g;
        ll diffa = b/g; ll diffb = a/g;

        y0 += (x0 / diffa) * diffb;
        x0 %= diffa;

        if (x0 < 0) {x0 += diffa; y0 -= diffb;}

        x0 += (y0 / diffb) * diffa;
        y0 %= diffb;
        if (y0 < 0) {x0 -= diffa; y0 += diffb;}

        ll res = x0*a;

        printf("%lld\n", t1 + res);
    }
}
