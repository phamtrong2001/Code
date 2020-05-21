#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 25005
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, p, s, d[N], dd[N];
vector<pii> a[N], g[N];


void nhap()
{
    scanf("%d %d %d %d", &n, &m, &p, &s);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        a[u].PB(mp(v, w));
        a[v].PB(mp(u, w));
    }
    for (int i = 1; i <= p; i++)
    {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        g[u].PB(mp(v, w));
    }
}

void IJK()
{
    for (int i = 1; i <= n; i++) d[i] = maxc;
    d[s] = 0;
    priority_queue<pair<pii, int> > q;
    q.push(mp(mp(0, 0), s));
    int dem = 0;
    while (!q.empty())
    {
        int u = q.top().S;
        int l = -q.top().F.S;
        int id = -q.top().F.F;
        q.pop();
        if (d[u] < l) continue;
        for (pii z : a[u])
        {
            int v = z.F;
            int w = z.S;
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                q.push(mp(mp(-id, -d[v]), v));
            }
        }
        for (pii z : g[u])
        {
            int v = z.F;
            int w = z.S;
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                q.push(mp(mp(-id-1, -d[v]), v));
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (d[i] == maxc) printf("NO PATH \n");
        else printf("%d \n", d[i]);
}
int main()
{
    freopen("NONNEG.INP", "r", stdin);
    freopen("NONNEG.OUT", "w", stdout);
    nhap();
    IJK();
}
