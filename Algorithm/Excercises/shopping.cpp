#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define pii pair <int, int>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ll long long
#define maxn 200005
#define maxc 1000000007
#define MOD 1000000007
#define task "shopping"

using namespace std;

int m, n, f[maxn][20];
ll a[maxn];

void RMQ()
{
    FOR(i, 1, n) f[i][0] = i;
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) <= n; i++)
            f[i][j] = (a[f[i][j-1]] < a[f[i+(1<<(j-1))][j-1]] ? f[i][j-1] : f[i+(1<<(j-1))][j-1]);
}

void xuli(ll t, int l, int r)
{
    while (l <= r)
    {
        int x = log2(r - l + 1);
        for (int i = x; i >= 0; i--)
            if (a[f[l][i]] > t) l += (1 << i);
        if (l > r) break;
        t %= a[l];
    }
    cout << t << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    RMQ();
    FOR(i, 1, m)
    {
        int l, r;
        ll t;
        cin >> t >> l >> r;
        xuli(t, l, r);
    }
    return 0;
}
