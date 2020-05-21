#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define MOD 1000000007

using namespace std;

int n, m, d[N], dpTo[N], dpFrom[N], To[N], From[N], res[N];
vector<pair<int, pii> >a[N];
pii v[N];

inline void add(int &x, int y) {x += y; if (x >= MOD) x -= MOD;}

void IJK(int s)
{
    priority_queue<pair<int, int> >q;
    for (int i = 1; i <= n; i++) d[i] = MOD;
    d[s] = 0;
    q.push(mp(0, s));
    while (!q.empty())
    {
        int u = q.top().S;
        int l = -q.top().F;
        q.pop();
        if (d[u] < l) continue;
        for (auto z : a[u])
        {
            int v = z.F;
            int w = z.S.F;
            if (d[v] > l + w)
            {
                d[v] = l + w;
                q.push(mp(-d[v], v));
            }
        }
    }
}
void solve()
{
    for (int i = 1; i <= n; i++) v[i] = mp(d[i], i);
    sort(v+1, v+n+1);
    for (int i = 1; i <= n; i++)
    {
        int u = v[i].S;
        for (auto z : a[u])
        {
            int v = z.F;
            int w = z.S.F;
            int id = z.S.S;
            if (d[u] + w == d[v] && d[u] != MOD && d[v] != MOD)
            {
                add(dpTo[id], To[u]);
                add(To[v], dpTo[id]);
            }

        }
    }
    for (int i = n; i >= 1; i--)
    {
        int u = v[i].S;
        for (auto z : a[u])
        {
            int v = z.F;
            int w = z.S.F;
            int id = z.S.S;
            if (d[u] + w == d[v] && d[u] != MOD && d[v] != MOD)
            {
                add(dpFrom[id], From[v] + 1);
                add(From[u], dpFrom[id]);
            }
        }

    }
    for (int i = 1; i <= m; i++)
    {
        add(res[i], (dpTo[i]*dpFrom[i]) % MOD);
        dpTo[i] = dpFrom[i] = 0;
    }
    for (int i = 1; i <= n; i++) To[i] = From[i] = 0;
}
int main()
{
    freopen("PATHS.INP", "r", stdin);
    freopen("PATHS.OUT", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        a[u].PB(mp(v, mp(w, i)));
    }
    for (int i = 1; i <= n; i++)
    {
        add(To[i], 1);
        IJK(i);
        solve();
    }
    for (int i = 1; i <= m; i++) cout <<res[i]<<'\n';
}
