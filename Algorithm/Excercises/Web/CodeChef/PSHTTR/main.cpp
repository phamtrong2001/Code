#include <bits/stdc++.h>
#define mid (r + l)/2
#define N 100005
#define LN 25
#define PB push_back

using namespace std;


struct edge
{
    int u, v, w;
    edge(int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}
}e[N];

struct Query
{
    int u, v, k, id;
    Query(int u = 0, int v = 0, int k = 0, int id = 0) : u(u), v(v), k(k), id(id) {}
}query[N];

bool cmp1(edge p, edge q)
{
    return p.w < q.w;
}
bool cmp2(Query p, Query q)
{
    return p.k < q.k;
}
vector<int> g[N];

int chainInd[N], posInBase[N], pos[N], head[N], h[N], p[N][LN], res[N], sz[N], spe[N];
int n, m, curChain, dem;

void nhap()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        e[i] = edge(u, v, w);
    }
    sort(e+1, e+n, cmp1);
    for (int i = 1; i < n; i++)
    {
        int u = e[i].u;
        int v = e[i].v;
        g[u].PB(i);
        g[v].PB(i);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, k; scanf("%d %d %d", &u, &v, &k);
        query[i] = Query(u, v, k, i);
    }
    sort(query+1, query+m+1, cmp2);
}

struct IntervalTree
{
    int t[N << 2];
    void build(int l, int r, int id)
    {
        if (l == r)
        {
            t[id] = 0;
            return;
        }
        build(l, mid, id*2);
        build(mid+1, r, id*2+1);
        t[id] = 0;
    }
    void add(int l, int r, int id, int x, int val)
    {
        if (l > x || r < x) return;
        if (l == r)
        {
            t[id] = val;
            return;
        }
        add(l, mid, id*2, x, val);
        add(mid+1, r, id*2+1, x, val);
        t[id] = t[id*2] ^ t[id*2+1];
    }
    int get(int l, int r, int id, int x, int y)
    {
        if (l > y || r < x) return 0;
        if (l >= x && r <= y) return t[id];
        int a = get(l, mid, id*2, x, y);
        int b = get(mid+1, r, id*2+1, x, y);
        return a ^ b;
    }
}t;
void DFS(int u)
{
    sz[u] = 1; spe[u] = 0;
    for (int &id : g[u])
    {
        int v = e[id].v;
        if (v == u) v = e[id].u;
        if (v == p[u][0]) continue;
        p[v][0] = u;
        for (int i = 1; i < LN; i++) p[v][i] = p[p[v][i-1]][i-1];
        h[v] = h[u] + 1;
        DFS(v);
        if (sz[v] > sz[spe[u]]) spe[u] = v;
        sz[u] += sz[v];
    }
}
void HLD(int u)
{
    if (head[curChain] == 0) head[curChain] = u;
    chainInd[u] = curChain;
    posInBase[u] = ++dem;
    pos[dem] = u;
    if (spe[u])
    {
        HLD(spe[u]);
        for (int &id : g[u])
        {
            int v = e[id].v;
            if (v == u) v = e[id].u;
            if (v == p[u][0] || v == spe[u]) continue;
            curChain++;
            HLD(v);
        }
    }
}
int LCA(int u, int v)
{
    if (h[u] < h[v]) swap (u, v);
    int d = h[u] - h[v];
    for (int i = LN-1; i >= 0; i--) if ((d >> i) & 1) u = p[u][i];
    if (u == v) return u;
    for (int i = LN-1; i >= 0; i--)
        if (p[u][i] != p[v][i])
        {
            u= p[u][i];
            v= p[v][i];
        }
    return p[u][0];
}
void add(int id)
{
    int u = e[id].u;
    int v = e[id].v;
    int w = e[id].w;
    if (u == p[v][0]) swap(u, v);
    t.add(1, n, 1, posInBase[u], w);
}

int getans(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    //if (u == v) return 0;
    int uchain, vchain = chainInd[v], res = 0;
    while (1)
    {
        uchain = chainInd[u];
        if (uchain == vchain)
        {
            res = res ^ t.get(1, n, 1, posInBase[v], posInBase[u]);
            break;
        }
        res = res ^ t.get(1, n, 1, posInBase[head[uchain]], posInBase[u]);
        u = head[uchain];
        u = p[u][0];
    }
    return res;
}

void solve()
{
    DFS(1);
    HLD(1);
    t.build(1, n, 1);
    int cur = 1;
    for (int i = 1; i <= m; i++)
    {
        int id = query[i].id;
        int u = query[i].u;
        int v = query[i].v;
        int k = query[i].k;

        while (e[cur].w <= k && cur < n) add(cur++);

        int lca = LCA(u, v);
        int a = getans(u, lca);
        int b = getans(v, lca);
        res[id] = a ^ b;

    }
    for (int i = 1; i <= m; i++) printf("%d\n", res[i]);
}
void setup()
{
    for (int i = 1; i < N; i++) g[i].clear();
    memset(head, 0, sizeof head);
    memset(chainInd, 0, sizeof chainInd);
    memset(posInBase, 0, sizeof posInBase);
    curChain = 0; dem = 0;
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    int t; scanf("%d", &t);
    while (t--)
    {
        setup();
        nhap();
        solve();
    }
}
