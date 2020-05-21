/******** Kho kinh nguoi ********/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define MP make_pair
#define pii pair <int, int>
#define F first
#define S second
#define ll long long
#define maxc 1ll*1000000000000000007
#define MOD
#define maxn 100005
#define task "walk"

using namespace std;

int m, n;

ll d[maxn], tr[maxn], res = 0, p[maxn];

bool kt[3][maxn], check;

vector <pii> a[maxn];

vector <int> trace[3];

map <pii, bool> dd;

void nhap()
{
    scanf("%d%d", &n, &m);
    FOR(i, 1, m)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        a[u].PB(MP(v, w));
        a[v].PB(MP(u, w));
    }
}

void IJK()
{
    for (int i = 1; i <= n; i++)
        d[i] = maxc;
    d[1] = 0;
    priority_queue <pair <ll, int> > q;
    q.push(MP(-d[1], 1));
    while (!q.empty())
    {
        int u = q.top().S;
        int l = -q.top().F;
        q.pop();
        if (l > d[u]) continue;
        for (pii &pi : a[u])
        {
            int v = pi.F;
            if (!pi.S) continue;
            ll w = pi.S + p[u] - p[v];
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                tr[v] = u;
                q.push(MP(-d[v], v));
            }
        }
    }
}

void chuanbi()
{
    IJK();
    if (d[n] == maxc) check = 1;
    res = d[n];
    FOR(i, 1, n)
        if (d[i] != maxc)
            p[i] += d[i];
    int u = n;
    trace[1].PB(n);
    while (u != 1)
    {
        int v = tr[u];
        trace[1].PB(v);;
        for (pii &t : a[v])
            if (t.F == u) t.S = 0;
        for (pii &t : a[u])
            if (t.F == v) t.S = -t.S;
        u = tr[u];
    }
    IJK();
    if (d[n] == maxc) check = 1;
    res += d[n] - p[1] + p[n];
    u = n;
    trace[2].PB(n);
    while (u != 1)
    {
        int v = tr[u];
        trace[2].PB(v);
        u = tr[u];
    }
}

void xuli()
{
    if (check) {printf("-1"); exit(0);}
    printf("%lld\n", res);
    reverse(trace[1].begin(), trace[1].end());
    reverse(trace[2].begin(), trace[2].end());
    FOR(i, 1, n) a[i].clear();
    FOR(i, 1, 2)
        FOR(j, 0, trace[i].size()-2)
        {
            int u = trace[i][j];
            int v = trace[i][j+1];
            dd[MP(u, v)] = 1;
        }
    FOR(i, 1, 2)
        FOR(j, 0, trace[i].size()-2)
        {
            int u = trace[i][j];
            int v = trace[i][j+1];
            if (dd[MP(v, u)]) kt[i][j] = 1;
            if (!kt[i][j]) a[u].PB(MP(v, 1));
        }
    memset(p, 0, sizeof (p));
    trace[1].clear(); trace[2].clear();
    chuanbi();
    FORD(i, trace[1].size()-1, 0) printf("%d ", trace[1][i]);
    FOR(i, 1, trace[2].size()-1) printf("%d ", trace[2][i]);
}

int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    nhap();
    chuanbi();
    xuli();
    return 0;
}
