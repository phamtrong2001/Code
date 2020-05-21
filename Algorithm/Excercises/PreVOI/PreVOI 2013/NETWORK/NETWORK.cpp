#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define mid (r + l)/2
#define LN 22
#define maxc 1000000007

using namespace std;

int n, m, query2[N], h[N], p[N][LN], sz[N], spe[N], ans[N];
int chainInd[N], curChain = 1, head[N], posInBase[N], tt, tt2,  tin[N], tout[N];
vector<int> a[N];

struct edge
{
    int u, v, w;
    edge(int u=0, int v=0, int w=0) : u(u), v(v), w(w) {}
}e[N], copyOfEdge[N];

struct query
{
    char type; int u, v, c, id;
    query(char type=0, int u=0, int v=0, int c=0, int id=0) : type(type), u(u), v(v), c(c), id(id) {}
}q[N];

bool cmp1(edge p, edge q) {return p.w < q.w;}
bool cmp2(query p, query q) {return p.c < q.c;}

struct IntervalTree
{
    int t[N << 2];
    void update(int l, int r, int id, int x)
    {
        if (l > x || r < x) return;
        if (l == r)
        {
            t[id]++;
            return;
        }
        if (x <= mid) update(l, mid, id*2, x);
        else update(mid+1, r, id*2+1, x);
        t[id] = t[id*2] + t[id*2+1];
    }
    int get(int l, int r, int id, int x, int y)
    {
        if (l > y || r < x) return 0;
        if (l >= x && r <= y) return t[id];
        int a = get(l, mid, id*2, x, y);
        int b = get(mid+1, r, id*2+1, x, y);
        return a + b;
    }
}t, t2;
void nhap()
{
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        e[i] = edge(u, v, w);
        copyOfEdge[i] = edge(u, v, w);
        a[u].PB(v); a[v].PB(u);
    }
    for (int i = 1; i <= m; i++)
    {
        char c; cin >> c; int u, v, w;
        cin >> u;
        if (c == 'P') cin >> v; cin >> w;
        q[i] = query(c, u, v, w, i);
    }
    sort(e+1, e+n, cmp1);
    sort(q+1, q+m+1, cmp2);
}

void preDFS(int u)
{
    tin[u] = ++tt2;
    sz[u] = 1; spe[u] = 0;
    for (auto v : a[u])
    {
        if (v == p[u][0]) continue;
        h[v] = h[u] + 1;
        p[v][0] = u;
        for (int i = 1; i < LN; i++) p[v][i] = p[p[v][i-1]][i-1];
        preDFS(v);
        if (sz[v] > sz[spe[u]]) spe[u] = v;
        sz[u] += sz[v];
    }
    tout[u] = tt2;
}
void HLD(int u)
{
    if (head[curChain] == 0) head[curChain] = u;
    posInBase[u] = ++tt;
    chainInd[u] = curChain;
    if (spe[u])
    {
        HLD(spe[u]);
        for (auto v : a[u])
        {
            if (v == spe[u] || v == p[u][0]) continue;
            curChain++;
            HLD(v);
        }
    }
}
void addEdge(int id)
{
    int u = e[id].u;
    int v = e[id].v;
    if (h[u] > h[v]) swap(u, v);
    t.update(1, n, 1, posInBase[v]);
    t2.update(1, n, 1, tin[v]);
}
int Up(int v, int delta)
{
    if (delta == -1) return -1;
    for (int i = 0; i < LN; i++)
        if ((delta >> i) & 1) v = p[v][i];
    return v;
}
int LCA(int u, int v)
{
    if (h[u] > h[v]) swap(u, v);
    int delta = h[v] - h[u];
    v = Up(v, delta);
    if (u == v) return u;
    for (int i = LN-1; i >= 0; i--)
        if (p[u][i] != p[v][i])
        {
            u = p[u][i];
            v = p[v][i];
        }
    return p[u][0];
}
int get_sum(int u, int v)
{
    int uchain, vchain = chainInd[v]; int res = 0;
    while (1)
    {
        uchain = chainInd[u];
        if (uchain == vchain)
        {
            res += t.get(1, n, 1, posInBase[v], posInBase[u]);
            break;
        }
        else
        {
            res += t.get(1, n, 1, posInBase[head[uchain]], posInBase[u]);
            u = head[uchain];
            u = p[u][0];
        }
    }
    return res;
}
int get_ans(int u, int v)
{
    int lca = LCA(u, v);
    int u1 = Up(u, h[u] - h[lca] - 1);
    int v1 = Up(v, h[v] - h[lca] - 1);
    int res = 0;
    if (u1 != -1) res += get_sum(u, u1);
    if (v1 != -1) res += get_sum(v, v1);
    return res;
}
int get_ans2(int u, int v)
{
    if (u == p[v][0]) return t2.get(1, n, 1, tin[v]+1, tout[v]);
    return t2.get(1, n, 1, tin[1], tout[1]) - t2.get(1, n, 1, tin[v], tout[v]);
}
void solve()
{
    preDFS(1);
    HLD(1);
    int j = 1;
    for (int i = 1; i <= m; i++)
    {
        while (j < n && e[j].w <= q[i].c)
        {
            addEdge(j);
            j++;
        }
        if (q[i].type == 'P') ans[q[i].id] = get_ans(q[i].u, q[i].v);
        else ans[q[i].id] = get_ans2(copyOfEdge[q[i].u].u, copyOfEdge[q[i].u].v);
    }
    for (int i = 1; i <= m; i++) cout <<ans[i]<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("NETWORK.INP", "r", stdin);
    nhap();
    solve();
    return 0;
}
