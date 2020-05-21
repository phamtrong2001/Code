#include <bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;

int n, S, sl[N];
ll slPizza;
struct people
{
    int s, a, b;
}v[N];
bool cmp(people p, people q)
{
    return (p.a - p.b > q.a - q.b);
}
ll calc(ll X)
{
    ll ans = 0;
    ll Y = (slPizza * S) - X;
    memset(sl, 0, sizeof sl);
    for (int i = 1; i <= n; i++)
    {
        if (X >= v[i].s && v[i].a >= v[i].b)
        {
            ans += 1ll*v[i].s * v[i].a;
            sl[i] = v[i].s;
            X -= v[i].s;
        }
        else
        {
            if (v[i].a >= v[i].b)
            {
                ans += 1ll*X*v[i].a;
                sl[i] = X;
                for (int i = 1; i <= n; i++) ans += 1ll*(v[i].s - sl[i])*v[i].b;
                return ans;
            }
            else
            {
                for (int i = n; i >= 1; i--)
                {
                    if (Y >= (v[i].s - sl[i]))
                    {
                        ans += 1ll*(v[i].s - sl[i])*v[i].b;
                        Y -= (v[i].s - sl[i]);
                        sl[i] = v[i].s;

                    }
                    else
                    {
                        ans += 1ll*Y*v[i].b;
                        sl[i] += Y;
                        Y = 0;
                        for (int i = 1; i <= n; i++) ans += 1ll*(v[i].s - sl[i])*v[i].a;
                        return ans;
                    }
                }
                return ans;
            }
        }
    }

    return ans;
}

int main()
{
    freopen("INP.TXT", "r", stdin);
    scanf("%d %d", &n, &S);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &v[i].s, &v[i].a, &v[i].b);
        sum += 1ll*v[i].s;
    }
    sort(v+1, v+n+1, cmp);
    ll res = 0;
    slPizza = (sum - 1) / S + 1;
    ll l = -1, r = slPizza+1;
    while (r >= l)
    {
        ll mid1 = (l + l + r) / 3;
        ll mid2 = (l + r + r) / 3;
        ll xx = calc(mid1*S);
        ll yy = calc(mid2*S);
        if (xx > yy)
        {
            r = mid2-1;
            res = max(res, xx);
        }
        else
        {
            l = mid1+1;
            res = max(res, yy);
        }
    }
    printf("%I64d", res);
}
