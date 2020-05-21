#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1000005
#define maxc 1000000007

using namespace std;

int n, sz[N];
vector<long long> b[N], f[N], g[N], h[N];
vector<pair<long long, int> >a[N];

void solve()
{
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < sz[i]; j++)
        {
            f[i][j] = g[i][j] = h[i][j] = 0;
            int k = (a[i][j].S + 1) % sz[i];
            int pos1 = upper_bound(a[i-1].begin(), a[i-1].end(), mp(b[i][k], maxc)) - a[i-1].begin() - 1;
            if (pos1 < 0) pos1 = 0;
            if (pos1 < a[i-1].size()) f[i][j] = (i-1)*b[i][k] + f[i-1][pos1];

            int pos2 = lower_bound(a[i-1].begin(), a[i-1].end(), mp(b[i][k], 0)) - a[i-1].begin();
            if (pos2 >= a[i-1].size()) pos2 = a[i-1].size()-1;
            if (pos2 >= 0) g[i][j] = (1-i)*b[i][k] + g[i-1][pos2];

            if (i == n) res = max(res, max(f[i][j], g[i][j]));
        }
        for (int j = 0; j < sz[i]; j++) h[i][j] = f[i][j];
        f[i][0] = max(f[i][0] - i*a[i][0].F, g[i][0] - i*a[i][0].F);
        for (int j = 1; j < sz[i]; j++)
            f[i][j] = max(max(h[i][j] - i*a[i][j].F, g[i][j] - i*a[i][j].F), f[i][j-1]);
        g[i][sz[i]-1] = max(h[i][sz[i]-1] + i*a[i][sz[i]-1].F, g[i][sz[i]-1] + i*a[i][sz[i]-1].F);
        for (int j = sz[i]-2; j >= 0; j--)
            g[i][j] = max(max(h[i][j] + i*a[i][j].F, g[i][j] + i*a[i][j].F), g[i][j+1]);

    }
    cout <<res<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("INP.TXT", "r", stdin);
    int Tests; cin >> Tests;
    a[0].resize(1); f[0].resize(1); g[0].resize(1); h[0].resize(1);
    while (Tests--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int m; cin >> m; sz[i] = m;
            a[i].resize(m);
            b[i].resize(m);
            f[i].resize(m);
            g[i].resize(m);
            h[i].resize(m);
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j].F;
                b[i][j] = a[i][j].F;
                a[i][j].S = j;
            }
            sort(a[i].begin(), a[i].end());
        }
        solve();
    }
    return 0;
}
