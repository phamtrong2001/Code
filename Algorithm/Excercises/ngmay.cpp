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
#define task "ngmay"
#define maxc 1000000007
#define maxn 502
#define maxm 30004

using namespace std;

int n, m, t[maxn], c[maxn][maxn], tr[maxn];

ll d[maxn], res = -maxc;

vector <pii> a[maxn];

void nhap()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    cin >> m;
    while (m--)
    {
        int u, v, t, x;
        cin >> u >> v >> t >> x;
        a[u].PB(MP(v, t));
        a[v].PB(MP(u, t));
        c[v][u] = c[u][v] = x;
    }
}

void IJK()
{
    memset(tr, 0, sizeof (tr));
    for (int i = 1; i <= n; i++)
        d[i] = maxc;
    d[1] = 0;
    priority_queue <pii> q;
    q.push(MP(-d[1], 1));
    while (!q.empty())
    {
        int u = q.top().S;
        int t = q.top().F;
        q.pop();
        if (t > d[u]) continue;
        for (pii &p : a[u])
        {
            int v = p.F;
            int t = p.S;
            if (d[v] >= d[u] + t)
            {
                d[v] = d[u] + t;
                tr[v] = u;
                q.push(MP(-d[v], v));
            }
        }
    }
    ll pos = 0;
    while (n != 1)
    {
        pos += c[n][tr[n]];
        if (t[tr[n]])
        {
            res = max(res, pos);
            pos = 0;
        }
        n = tr[n];
    }
    cout << max(res, pos);
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
