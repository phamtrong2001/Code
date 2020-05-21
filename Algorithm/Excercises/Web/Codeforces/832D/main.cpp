#include <bits/stdc++.h>
#define N 100005
#define PB push_back
#define mid (l + r) / 2
#define LN 25
using namespace std;

int n, q, spe[N], sz[N], h[N], p[N][LN];
int curChain = 1, chainInd[N], posInBase[N], head[N], dem;
int val[4], per[4];
vector<int> a[N];

struct interval
{
    int l, r, val, f, dd;
    interval* lc;
    interval* rc;

    interval(int l = 0, int r = 0): l(l), r(r)
    {
        if (l == r)
            lc = rc = NULL, val = f = dd = 0;
        else
        {
            val = f = dd = 0;
            lc = new interval(l, mid);
            rc = new interval(mid + 1, r);
        }
    }

    void push()
    {
        if (!dd || l == r) return;
        lc -> val = f*(lc->r - lc->l + 1);
        rc -> val = f*(rc->r - rc->l + 1);
        lc -> f = rc -> f = f;
        f = 0;
        lc -> dd = rc -> dd = 1;
        dd = 0;
    }

    void update(int x, int y, int v)
    {
        push();
        if (l > y || r < x)
            return;
        if (x <= l && r <= y)
        {
            val = v*(r - l + 1);
            f = v;
            dd = 1;
            return;
        }
        lc -> update(x, y, v);
        rc -> update(x, y, v);
        val = lc->val + rc -> val;
    }
    int get(int x, int y)
    {
        push();
        if (l > y || r < x) return 0;
        if (x <= l && r <= y) return val;
        int a = lc -> get(x, y);
        int b = rc -> get(x, y);
        return a + b;
    }
} t;
void DFS1(int u)
{
    spe[u] = 0; sz[u] = 1;
    for (auto v : a[u])
    {
        h[v] = h[u] + 1;
        p[v][0] = u;
        for (int i = 1; i < LN; i++) p[v][i] = p[p[v][i-1]][i-1];
        DFS1(v);
        if (sz[v] > sz[spe[u]]) spe[u] = v;
        sz[u] += sz[v];
    }
}
void HLD(int u)
{
    if (head[curChain] == 0) head[curChain] = u;
    chainInd[u] = curChain;
    posInBase[u] = ++dem;

    if (spe[u])
    {
        HLD(spe[u]);
        for (auto v : a[u])
            if (v != spe[u])
            {
                curChain++;
                HLD(v);
            }
    }
}
int LCA(int u, int v)
{
    if (h[u] > h[v]) swap(u, v);
    int diff = h[v] - h[u];
    for (int i = LN-1; i >= 0; i--)
        if ((diff >> i) & 1) v = p[v][i];
    if (u == v) return u;
    for (int i = LN-1; i >= 0; i--)
        if (p[u][i] != p[v][i])
        {
            u = p[u][i];
            v = p[v][i];
        }
    return p[u][0];
}
void update(int u, int v, int x)
{
    if (h[u] < h[v]) swap(u, v);
    int uchain, vchain = chainInd[v];
    while (1)
    {
        uchain = chainInd[u];
        if (uchain == vchain)
        {
            t.update(posInBase[v], posInBase[u], x);
            break;
        }
        t.update(posInBase[head[uchain]], posInBase[u], x);
        u = head[uchain];
        u = p[u][0];
    }
}
int get_res(int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    int uchain, vchain = chainInd[v], res = 0;
    while (1)
    {
        uchain = chainInd[u];
        if (uchain == vchain)
        {
            res += t.get(posInBase[v], posInBase[u]);
            break;
        }
        res += t.get(posInBase[head[uchain]], posInBase[u]);
        u = head[uchain];
        u = p[u][0];
    }
    return res;
}
int get_ans()
{
    //if (val[per[1]] == val[per[2]] || val[per[2]] == val[per[3]]) return 1e9;
    int lca1 = LCA(val[per[1]], val[per[2]]);
    update(val[per[1]], lca1, 1);
    update(val[per[2]], lca1, 1);
    int lca2 = LCA(val[per[2]], val[per[3]]);

    int u = val[per[2]]; int v = val[per[3]];
    int res;
    if (u == lca2) res = get_res(lca2, v);
    else if (v == lca2) res = get_res(lca2, u);
    else res = get_res(lca2, u) + get_res(lca2, v)-1;
    update(val[per[1]], lca1, 0);
    update(val[per[2]], lca1, 0);
    return res;
}
int main()
{
    //freopen("INP.TXT", "r", stdin);
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++)
    {
        int u; scanf("%d", &u);
        a[u].PB(i);
    }
    DFS1(1);
    HLD(1);
    t = interval(1, n);
    for (int i = 1; i <= q; i++)
    {
        for (int j = 1; j <= 3; j++) scanf("%d", &val[j]), per[j] = j;

        int res = get_ans();
        per[2] = 1; per[1] = 2; per[3] = 3;
        res = max(res, get_ans());
        per[2] = 3; per[1] = 1; per[2] = 2;
        res = max(res, get_ans());
        printf("%d\n", res);
    }
}
