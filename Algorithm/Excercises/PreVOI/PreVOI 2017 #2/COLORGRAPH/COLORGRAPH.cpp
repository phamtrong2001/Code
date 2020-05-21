#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, col[N], dd[N], cnt[N], partAns, step, sz[N];
ll curAns, up[N], down[N];
vector<int> a[N];

struct IntervalTree
{
    ll t[N << 2], lazy[N << 2];
    void update(int l, int r, int id, int x, int y, int val)
    {
        push(l, r, id);
        if (l > y || r < x) return;
        if (l >= x & r <= y)
        {
            lazy[id] += val;
            push(l, r, id);
            return;
        }
        update(l, mid, id*2, x, y, val);
        update(mid+1, r, id*2+1, x, y, val);
        t[id] = t[id*2] + t[id*2+1];
    }
    ll get(int l, int r, int id, int x)
    {
        push(l, r, id);
        if (l > x || r < x) return 0;
        if (l == r) return t[id];
        if (x <= mid) return get(l, mid, id*2, x);
        return get(mid+1, r, id*2+1, x);
    }
};
void dfsPre(int u, int p)
{
    tin[u] = ++tt; sz[u] = 1;
    ver[tt] = u;
    pa[u] = st[col[u]].top();
    g[pa[u]].PB(u);
    in[pa[u]]++;
    st[col[u]].push(u);
    for (auto v : a[u])
    {
        if (v == p) continue;
        dfsPre(v, u);
        sz[u] += sz[v];
    }
    st[col[u]].pop();
    tout[u] = tt;
}
void solve(int u)
{
    int temp = n - sz[u];
    for (auto v : g[u]) temp += sz[v];

}
int main()
{
    freopen("COLORGRAPH.INP", "r", stdin);
    freopen("COLORGRAPH.OUT", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &col[i]);
    for (int i = 1; i < n; i++)
    {
        int u, v; scanf("%d %d", &u, &v);
        a[u].PB(v); a[v].PB(u);
    }
    for (int i = 1; i < N; i++) st[i].push(n+i);
    dfsPre(1, -1);
    for (int i = 1; i < N; i++) solve(n+i);
}
