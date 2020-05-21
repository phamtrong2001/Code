#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, a[N], f[N], g[N], b[N];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("BEADS.INP", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int m = 0;
    for (int i = n; i >= 1; i--)
    {
        f[i] = lower_bound(b+1, b+m+1, a[i]) - b;
        m = max(m, f[i]);
        b[f[i]] = a[i];
    }
    for (int i = n; i >= 1; i--) a[i] = -a[i], b[i] = 0;

    m = 0;
    for (int i = n; i >= 1; i--)
    {
        g[i] = lower_bound(b+1, b+m+1, a[i]) - b;
        m = max(m, g[i]);
        b[g[i]] = a[i];
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, f[i] + g[i] - 1);
    cout <<res;
}
