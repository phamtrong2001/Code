#include <bits/stdc++.h>
#define maxn 100005
#define maxc 1000000007

using namespace std;

int m, n, a[maxn], t[4*maxn], f[4*maxn];

void make(int l, int r, int id)
{
    if (l == r) {t[id] = a[l]; return;}
    int mid = (l+r) >> 1;
    make(l, mid, id*2);
    make(mid+1, r, id*2+1);
    t[id] = min(t[id*2], t[id*2+1]);
}

void push(int i)
{
    f[i*2] = f[i*2+1] = t[i*2] = t[i*2+1] = f[i];
    f[i] = 0;
}

void update(int l, int r, int id, int u, int v, int w)
{
    if (l > v || r < u) return;
    if (l >= u && r <= v)
    {
        f[id] = t[id] = w;
        return;
    }
    if (f[id]) push(id);
    int mid = (l+r) >> 1;
    update(l, mid, id*2, u, v, w);
    update(mid+1, r, id*2+1, u, v, w);
    t[id] = min(t[id*2], t[id*2+1]);
}

void solve1()
{
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    update(1, n, 1, u, v, w);
}

int get_min(int l, int r, int id, int u, int v)
{
    if (l > v || r < u) return maxc;
    if (l >= u && r <= v) return t[id];
    if (f[id]) push(id);
    int mid = (l+r) >> 1;
    int m1 = get_min(l, mid, id*2, u, v);
    int m2 = get_min(mid+1, r, id*2+1, u, v);
    return min(m1, m2);
}

void solve2()
{
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", get_min(1, n, 1, l, r));
}

int main()
{
    freopen("minrange2.inp", "r", stdin);
    freopen("minrange2.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    make(1, n, 1);
    for (int i = 1; i <= m; i++)
    {
        int type;
        scanf("%d", &type);
        if (type == 1) solve1();
            else solve2();
    }
    return 0;
}
