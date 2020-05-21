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
#define task "friends"
#define maxc 1000000007
#define maxn 20
#define maxx 2000006

using namespace std;

int f, r, n, m, a[maxn][maxn], dp[maxx];

pair <int, int> tr[maxx];

void nhap()
{
    cin >> f >> r >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        a[u][v] += c;
        a[v][u] += c;
        dp[0] += 1ll * c * r;
    }
}

void xuli()
{
    int pos = (1 << n);
    for (int i = 1; i < pos; i++) dp[i] = maxc;
    for (int i = 0; i < pos; i++)
    {
        int dem = __builtin_popcount(i);
        if (dem % 2 == 0)
            for (int j = 0; j < n; j++)
            {
                if (((i >> j) & 1) == 0)
                    for (int k = 0; k < n; k++)
                        if (k != j && ((i >> k) & 1) == 0)
                        {
                            int x = i + (1 << j) + (1 << k);
                            if (dp[x] > dp[i] - a[j+1][k+1] * (r - f))
                            {
                                dp[x] = dp[i] - a[j+1][k+1] * (r - f);
                                tr[x] = MP(j+1, k+1);
                            }
                        }
            }
    }
    cout << dp[--pos] << '\n';
    while (pos)
    {
        cout << tr[pos].F << " " << tr[pos].S << '\n';
        pos -= (1 << (tr[pos].F-1)) + (1 << (tr[pos].S-1));
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    nhap();
    xuli();
    return 0;
}
