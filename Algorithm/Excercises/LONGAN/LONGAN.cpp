#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 200005
#define mid (r + l)/2
#define maxc 1000000007

using namespace std;

int n, m, dd[N], lef[N], rig[N], dp[N];
pii a[N];

struct IntervalTree
{
    int t[N << 2];
    void update(int l, int r, int id, int x, int val)
    {
        if (l > x || r < x) return;
        if (l == r)
        {
            t[id] = val;
            return;
        }
        update(l, mid, id*2, x, val);
        update(mid+1, r, id*2+1, x, val);
        t[id] = max(t[id*2], t[id*2+1]);
    }
    int get(int l, int r, int id, int x, int y)
    {
        if (l > y || r < x) return -maxc;
        if (l >= x && r <= y) return t[id];
        int a = get(l, mid, id*2, x, y);
        int b = get(mid+1, r, id*2+1, x, y);
        return max(a, b);
    }
}t;
void nhap()
{
    cin >> n >> m;
    memset(rig, 60, sizeof rig);
    memset(lef, -60, sizeof lef);
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        a[i] = mp(u, v);
        lef[v] = max(lef[v], u);
        rig[v] = min(rig[v], u);
    }
    lef[0] = 0;
    for (int i = 1; i <= n; i++)
        lef[i] = max(0, max(lef[i], lef[i-1]));
    rig[n+1] = n+1;
    for (int i = n; i >= 1; i--)
        rig[i] = min(i, min(rig[i], rig[i+1]));

    //for (int i = 1; i <= n+1; i++) cout <<lef[i-1]<<" "<< rig[i]-1<<endl;
}
void solve()
{
    for (int i = 1; i <= n+1; i++)
    {
        int l = lef[i-1], r = rig[i]-1;
        if (l > r) dp[i] = -maxc;
        else dp[i] = t.get(0, n, 1, l, r) + 1;
        t.update(0, n, 1, i, dp[i]);
    }
    dp[n+1] = max(dp[n+1], 0);
    cout <<dp[n+1] - 1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("LONGAN.INP", "r", stdin);
    freopen("LONGAN.OUT", "w", stdout);
    nhap();
    solve();
}
