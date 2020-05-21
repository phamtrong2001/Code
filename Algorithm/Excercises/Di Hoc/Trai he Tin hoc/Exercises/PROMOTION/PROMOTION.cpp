#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1005
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, f[N], dd[N];
double ep = 1e-7;
double d[N];
vector<pair<int, pii> >a[N];

void nhap()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> f[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        a[u].PB(mp(v, mp(w, f[v])));
    }
}

bool Bell(double x)
{
    bool flag = 0;
    memset(dd, 0, sizeof dd);
    for (int s = 1; s <= n; s++)
    {
        if (dd[s]) continue;
        dd[s] = 1;
        for (int i = 1; i <= n; i++) d[i] = 1.*maxc;
        d[s] = 0;
        for (int i = 1; i <= n; i++)
        {
            flag = 0;
            for (int u = 1; u <= n; u++)
                for (int j = 0; j < a[u].size(); j++)
                {
                    int v = a[u][j].F;
                    double w = 1.*a[u][j].S.F - x*a[u][j].S.S;
                    if (d[v] > d[u] + w + ep)
                    {
                        dd[v] = 1;
                        d[v] = d[u] + w;
                        flag = 1;
                    }
                }
        }
        if (flag) return 1;
    }
    return 0;
}

void solve()
{
    double l = 0, r = 1e5+ep;
    while (r - l > ep)
    {
        double mid = (r + l)/2;
        if (Bell(mid)) r = mid;
        else l = mid;
    }
    printf("%0.2f", 1./r);
}
int main()
{
    freopen("PROMOTION.INP", "r", stdin);
    //freopen("PROMOTION.OUT", "w", stdout);
    nhap();
    solve();
}
