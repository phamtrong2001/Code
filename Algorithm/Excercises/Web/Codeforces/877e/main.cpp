#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 400005
#define mid (r + l)/2
#define maxc 1000000007

using namespace std;

int n, tt[N], tin[N], tout[N], val[N], dem;
vector<int> a[N];

struct IT
{
    int t[N << 2], lazy[N << 2];
    void build(int l, int r, int id)
    {
        if (l == r)
        {
            t[id] = val[l];
            return;
        }
        build(l, mid, id*2);
        build(mid+1, r, id*2+1);
        t[id] = t[id*2] + t[id*2+1];
    }
    void push(int l, int r, int id)
    {
        if (!lazy[id]) return;
        t[id] = (r - l + 1) - t[id];
        lazy[id] = 0;
        if (l == r) return;
        lazy[id*2] ^= 1;
        lazy[id*2+1] ^= 1;
    }
    void update(int l, int r, int id, int x, int y)
    {
        push(l, r, id);
        if (l > y || r < x) return;
        if (l >= x && r <= y)
        {
            lazy[id] ^= 1;
            push(l, r, id);
            return;
        }
        update(l, mid, id*2, x, y);
        update(mid+1, r, id*2+1, x, y);
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

void DFS(int u, int p)
{
    tin[u] = ++dem;
    val[dem] = tt[u];
    for (auto v : a[u])
    {
        if (v == p) continue;
        DFS(v, u);
    }
    tout[u] = ++dem;
    val[dem] = tt[u];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int u; cin >> u;
        a[u].PB(i);
    }
    for (int i = 1; i <= n; i++) cin >> tt[i];
    DFS(1, -1);
    t.build(1, 2*n, 1);
    int q; cin >> q;
    while (q--)
    {
        string ss; int v;
        cin >> ss >> v;
        if (ss == "get") cout <<t.get(1, 2*n, 1, tin[v], tout[v])/2<<'\n';
        else t.update(1, 2*n, 1, tin[v], tout[v]);
    }
}
