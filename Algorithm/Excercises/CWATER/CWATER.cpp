#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a, b, c;
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
    freopen("CWATER.INP", "r", stdin);
    freopen("CWATER.OUT", "w", stdout);
    ll t; scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld %lld %lld", &a, &b, &c);
        ll x0, y0;
        ll g = gcd(a, b, x0, y0);

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
        ll res = abs(x0) + abs(y0);

        if (x0 < 0) {x0 += diffa; y0 -= diffb;}
        else {x0 -= diffa; y0 += diffb;}

        y0 += (x0 / diffa) * diffb;
        x0 %= diffa;
        res = min(res, abs(x0) + abs(y0));


        x0 += (y0 / diffb) * diffa;
        y0 %= diffb;
        res = min(res, abs(x0) + abs(y0));

        if (y0 < 0) {x0 -= diffa; y0 += diffb;}
        else {x0 += diffa; y0 -= diffb;}

        x0 += (y0 / diffb) * diffa;
        y0 %= diffb;
        res = min(res, abs(x0) + abs(y0));

        printf("%lld\n", res);
    }
}
