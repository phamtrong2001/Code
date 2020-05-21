#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define ll long long
#define maxc 1ll*1000000000000000007

using namespace std;

int n, m, k, s, t;
long long res, d[3][N];
pii city[N];
vector<pii> a[N];
void nhap()
{
    scanf("%d %d %d %d %d", &n, &m, &k, &s, &t);
    for (int i = 1; i <= k; i++)
    {
        int u, c; scanf("%d %d", &u, &c);
        city[i] = mp(u, c);
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        a[u].PB(mp(v, w));
        a[v].PB(mp(u, w));
    }
}

void IJK(int id)
{
    for (int i = 1; i <= n; i++) d[id][i] = maxc;
    priority_queue<pair<long long, int> >q;
    d[id][s] = 0;
    q.push(mp(0, s));
    while (!q.empty())
    {
        int u = q.top().S;
        ll l = -q.top().F;
        q.pop();
        if (d[id][u] < l) continue;
        for (auto z : a[u])
        {
            int v = z.F;
            ll w = z.S;
            if (d[id][v] > l + w)
            {
                d[id][v] = l + w;
                q.push(mp(-d[id][v], v));
            }
        }
    }
}
void solve()
{
    IJK(1); swap(s, t);
    IJK(2); swap(s, t);
    res = maxc;
    for (int i = 1; i <= k; i++)
    {
        int u = city[i].F;
        ll cost = city[i].S;
        if (d[1][u] == maxc || d[2][u] == maxc) continue;
        res = min(res, d[1][u] + d[2][u] + cost);
    }
    printf("%lld", res);
}
int main()
{
    freopen("MONEY.INP", "r", stdin);
    freopen("MONEY.OUT", "w", stdout);
    nhap();
    solve();
}
