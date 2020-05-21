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
#define task "party"
#define maxc 1000000007
#define maxn 1003

using namespace std;

vector <pii> a[maxn], b[maxn];

int m, n, x, d1[maxn], d2[maxn], res = -maxc;

void IJK(vector <pii> ke[], int mang[])
{
    priority_queue <pii> q;
    q.push(MP(0, x));
    for (int i = 1; i <= n; i++)
        mang[i] = maxc;
    mang[x] = 0;
    while (!q.empty())
    {
        int u = q.top().S;
        int l = -q.top().F;
        q.pop();
        if (l > mang[u]) continue;
        for (auto p : ke[u])
        {
            int v = p.F;
            int t = p.S;
            if (mang[v] > mang[u] + t)
            {
                mang[v] = mang[u] + t;
                q.push(MP(-mang[v], v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> m >> x;
    for (int u, v, t, i = 1; i <= m; i++)
    {
        cin >> u >> v >> t;
        a[u].PB(MP(v, t));
        b[v].PB(MP(u, t));
    }
    IJK(a, d1);
    IJK(b, d2);
    for (int i = 1; i <= n; i++)
        res = max(res, d1[i] + d2[i]);
    cout << res;
    return 0;
}
