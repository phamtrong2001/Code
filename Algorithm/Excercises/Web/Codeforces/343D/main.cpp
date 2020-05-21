#include <bits/stdc++.h>
#define mid (r + l)/2
#define PB push_back
#define N 1000005

using namespace std;

struct IntervalTree
{
    int t[N << 2], lazy[N << 2];

    void push(int l, int r, int id)
    {
        if (lazy[id] == 0) return;
        t[id] = r - l + 1;
        lazy[id] = 0;
        if (l == r) return;
        lazy[id*2] = lazy[id*2+1] = 1;
    }
    void update(int l, int r, int id, int x, int y)
    {
        push(l, r, id);
        if (l > y || r < x) return;
        if (l >= x && r <= y)
        {
            lazy[id] = 1;
            push(l, r, id);
            return;
        }
        update(l, mid, id*2, x, y);
        update(mid+1, r, id*2+1, x, y);
        t[id] = t[id*2] + t[id*2+1];
    }
    void add(int l, int r, int id, int x)
    {
        push(l, r, id);
        if (l == r)
        {
            t[id] = 0;
            return;
        }
        if (mid >= x) add(l, mid, id*2, x);
        else add(mid+1, r, id*2+1, x);
        t[id] = t[id*2] + t[id*2+1];
    }
    int get(int l, int r, int id, int x, int y)
    {
        push(l, r, id);
        if (l > y || r < x) return 0;
        if (l >= x && r <= y) return t[id];
        int a = get(l, mid, id*2, x, y);
        int b = get(mid+1, r, id*2+1, x, y);
        return a + b;
    }

}t;

int n, m, pa[N], tin[N], tout[N], tt;
vector<int> a[N];

void DFS(int u, int p)
{
    tin[u] = ++tt;
    for (auto v : a[u])
    {
        if (v == p) continue;
        DFS(v, u);
        pa[v] = u;
    }
    tout[u] = ++tt;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        a[u].PB(v); a[v].PB(u);
    }
    DFS(1, -1);
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int c, u; cin >> c >> u;
        if (c == 1)
        {
            if (t.get(1, tt, 1, tin[u], tout[u]) < tout[u] - tin[u] + 1)
                t.add(1, tt, 1, tin[pa[u]]);
            t.update(1, tt, 1, tin[u], tout[u]);
        }
        else if (c == 2) t.add(1, tt, 1, tin[u]);
        else
        {
            if (t.get(1, tt, 1, tin[u], tout[u]) < tout[u] - tin[u] + 1)
                cout <<0<<'\n';
            else cout <<1<<'\n';
        }
    }
}
