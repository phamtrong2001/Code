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
#define task "quadrant"
#define maxc 1000000007
#define maxn 10004

using namespace std;

int n, k, d[maxn], luu;

ll res = 0;

bool dd[maxn];

vector <pii> ke[maxn];

pii pos;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> k;
    for (int u, v, w, i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        ke[u].PB(MP(v, w));
        ke[v].PB(MP(u, w));
        res += w;
    }
    for (int i = 0; i < n; i++) d[i] = ke[i].size();
    while (k--)
    {
        pos = MP(0, 0);
        for (int u = 0; u < n; u++)
            if (d[u] == 1)
                for (auto p : ke[u])
                {
                    int v = p.F;
                    int c = p.S;
                    if (c > pos.S && !dd[v])
                        pos = p, luu = u;
                }
        res -= pos.S;
        dd[luu] = 1;
        d[luu]--;
        d[pos.S]--;
    }
    cout << res*2;
    return 0;
}
