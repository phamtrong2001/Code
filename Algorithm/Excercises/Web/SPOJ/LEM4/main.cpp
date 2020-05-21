#include <bits/stdc++.h>
#define N 10005
#define mid (r + l) / 2
using namespace std;

int n, m;
struct IntervalTree
{
    int lef[N << 4], rig[N << 4], res[N << 4], lazy[N << 4];

    void push(int l, int r, int id)
    {
        if (!lazy[id]) return;
        if (lazy[id] == 1)
            lef[id] = rig[id] = res[id] = r - l + 1;
        else
            lef[id] = rig[id] = res[id] = 0;
        lazy[id*2] = lazy[id*2+1] = lazy[id];
        lazy[id] = 0;
    }
    void uptopar(int l, int r, int id)
    {
        int len1 = mid - l + 1;
        int len2 = r - mid;
        int u = lef[id*2];
        int v = rig[id*2+1];
        if (u == len1) lef[id] = u + lef[id*2+1];
        else lef[id] = u;
        if (v == len2) rig[id] = rig[id*2] + v;
        else rig[id] = v;
        res[id] = max(max(max(res[id*2], res[id*2+1]), rig[id*2] + lef[id*2+1]), max(lef[id], rig[id]));
    }
    void build(int l, int r, int id)
    {
        if (l == r)
        {
            lef[id] = rig[id] = res[id] = 1;
            return;
        }
        build(l, mid, id*2);
        build(mid+1, r, id*2+1);
        lef[id] = rig[id] = res[id] = r - l + 1;
    }
    void update(int l, int r, int id, int x, int y, int val)
    {
        push(l, r, id);
        if (l > y || r < x) return;
        if (l >= x && r <= y)
        {
            lazy[id] = val;
            push(l, r, id);
            return;
        }
        update(l, mid, id*2, x, y, val);
        update(mid+1, r, id*2+1, x, y, val);
        uptopar(l, r, id);
    }
}t;
void nhap()
{
    scanf("%d %d", &n, &m);
    t.build(1, n, 1);
    for (int i = 1; i <= m; i++)
    {
        int type, u, v;
        scanf("%d", &type);
        if (type == 3)
        {
            printf("%d\n", t.res[1]);
            continue;
        }
        scanf("%d %d", &u, &v);
        t.update(1, n, 1, u, v, type);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    nhap();
}
