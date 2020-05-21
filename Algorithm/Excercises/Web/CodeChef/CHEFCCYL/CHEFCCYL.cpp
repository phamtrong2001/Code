#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define N 100005
#define maxc 1000000007ll
#define PB push_back
using namespace std;

vector <ii> a[N];
vector <ll> b[N];


ll T, n, Q;
ll d[N], e[N], vertex[N][2];

ll calcInCycle(ll x, ll y, ll id)
{
    if (y > x) swap(y, x);
    ll k = b[id][x - 1] - b[id][y - 1];
    return max(0ll, min(k, b[id][b[id].size() - 1] - k));
}

ll calcCycle(ll x, ll y, bool dir)
{
    if (x > y) swap(x, y);
    if (dir == 1) return max(0ll, e[y - 1] - e[x - 1]);
    return max(0ll, e[n] - (e[y - 1] - e[x - 1]));
}

void nhap()
{
    scanf("%lld%lld", &n, &Q);
    for (int i = 1; i <= n; i++)
    {
        b[i].clear(); b[i].PB(0);
        ll m; scanf("%lld", &m);
        while (m--)
        {
            ll x; scanf("%lld", &x);
            b[i].PB(x);
        }
        for (int j = 1; j < b[i].size(); j++)
            b[i][j] += b[i][j - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        ll v1, v2, cost; scanf("%lld %lld %lld", &v1, &v2, &cost);
        e[i] = cost;
        if (i < n) vertex[i][0] = v1, vertex[i + 1][1] = v2;
        else vertex[i][0] = v1, vertex[1][1] = v2;
    }
}
ll solve(ll v1, ll c1, ll v2, ll c2)
{
    ll ans = calcInCycle(v1, vertex[c1][0], c1) + calcInCycle(v2, vertex[c2][1], c2)
    + d[c2 - 1] - d[c1] + calcCycle(c1, c2, 1ll);
    ans = min(ans, calcInCycle(v1, vertex[c1][1], c1) + calcInCycle(v2, vertex[c2][0], c2)
    + d[n] - (d[c2 - 1] - d[c1]) - (d[c1] - d[c1 - 1]) - (d[c2] - d[c2 - 1]) + calcCycle(c1, c2, 0ll));
    return ans;
}
int main()
{
    scanf("%lld", &T);
    while (T--)
    {
        nhap();
        for (int i = 1; i <= n; i++) e[i] += e[i - 1];
        for (int i = 1; i <= n; i++)
        {
            d[i] = d[i - 1];
            d[i] += calcInCycle(vertex[i][0], vertex[i][1], 1ll*i);
        }
        while (Q--)
        {
            int v1, c1, v2, c2;
            scanf("%lld %lld %lld %lld", &v1, &c1, &v2, &c2);
            if (c1 > c2) {swap(v1, v2); swap(c1, c2);}
            printf("%lld\n", solve(v1, c1, v2, c2));
        }
    }
    return 0;
}
