#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n;
struct node
{
    int lef, rig;
    int sum;
    node(int lef = 0, int rig = 0, int sum = 0) : lef(lef), rig(rig), sum(sum) {}
}it[11000111];
int nNode = 0;

inline void refine(int cur)
{
    it[cur].sum = it[it[cur].lef].sum + it[it[cur].rig].sum;
}
int update(int l, int r, int u, int oldId)
{
    if (l > u || r < u) return 0;
    if (l == r)
    {
        ++nNode;
        it[nNode] = node(0, 0, it[oldId].sum + 1);
        return nNode;
    }
    int mid = (r + l) / 2;
    int cur = ++nNode;
    if (u <= mid)
    {
        it[cur].lef = update(l, mid, u, it[oldId].lef);
        it[cur].rig = it[oldId].rig;
        refine(cur);
    }
    else
    {
        it[cur].lef = it[oldId].lef;
        it[cur].rig = update(mid+1, r, u, it[oldId].rig);
        refine(cur);
    }
}
int build(int l, int r)
{
    if (l == r)
    {
        ++nNode;
        it[nNode] = node(0, 0, 0);
        return nNode;
    }
    int mid = (r + l)/2;
    int cur = ++nNode;

    it[cur].lef = build(l, mid);
    it[cur].rig = build(mid+1, r);

    refine(cur);
     return cur;
}
int query(int l, int r, int x, int y, int id)
{
    if (l > y || r < x) return 0;
    if (l >= x && r <= y) return it[id].sum;
    int mid = (r + l)/2;
    return query(l, mid, x, y, it[id].lef) + query(mid+1, r, x, y, it[id].rig);
}
int main()
{
    cin >> n >> q;
    root[0] = build(1, n);
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        root[i] = update(1, n, x, root[i-1]);
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> l >> u >> r >> v;
        res = 0;

    }
}
