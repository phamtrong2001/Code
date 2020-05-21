#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define x first
#define y second
using namespace std;

pair<ll, ll> p[7];
ll S, bound;
ll dt()
{
    ll XX = p[1].x - p[2].x;
    ll YY = p[1].y - p[2].y;
    return XX*XX + YY*YY;
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    for (ll i = 1; i <= 4; i++)
    {
        ll x, y; cin >> x >> y;
        p[i] = mp(x, y);
    }
    ll S = dt();
    if (p[1].x == p[2].x || p[1].y == p[2].y) bound = sqrt(S);
    else
    {
        ll XX = abs(p[1].x - p[2].x);
        ll YY = abs(p[1].y - p[2].y);
        ll gcd = __gcd(XX, YY);
        ll xx = XX/gcd;
        ll yy = YY/gcd;
        bound = min(XX/xx, YY/yy);
    }
    cout <<S + 1 - bound * 2;
}
