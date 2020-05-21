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
#define task "road"
#define maxc 1000000007
#define maxm 20004
#define maxn 5003

using namespace std;

ll m, n, d[maxn], dem[maxn];

vector <pii> a[maxn];

void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int type, u, v, w;
        cin >> type >> u >> v >> w;
        if (type == 1) a[u].PB(MP(v, w));
            else
            {
                a[u].PB(MP(v, w));
                a[v].PB(MP(u, w));
            }
    }
}

void IJK()
{
    dem[1] = 1;
    for (int i = 1; i <= n; i++)
        d[i] = 1ll*maxc*maxc;
    d[1] = 0;
    priority_queue <pii> q;
    q.push(MP(-d[1], 1));
    while (!q.empty())
    {
        int u = q.top().S;
        int l = -q.top().F;
        q.pop();
        if (l > d[u]) continue;
        for (pii &p : a[u])
        {
            int v = p.F;
            int w = p.S;
            if (d[v] == d[u] + w) dem[v] += dem[u];
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                dem[v] = dem[u];
                q.push(MP(-d[v], v));
            }
        }
    }
    cout << d[n] << " " << dem[n];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    nhap();
    IJK();
    return 0;
}
