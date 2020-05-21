    /*Design by Dinh Viet Anh(JOKER)*/
#include <bits/stdc++.h>
#define p2 pair<int, int>
#define F first
#define S second
#define ll long long
#define pb push_back
#define fort(i, a, b) for(int i = (a); i <= (b); i++)
#define ford(i, a, b) for(int i = (a); i >= (b); i++)
#define Task "NUCLEAR"

using namespace std;

vector<int> tree[1010101];
int n, q;
p2 p_a, p_b;
p2 p[202020], d[202020];
int in_a[202020], in_b[202020], r_a, r_b;

double dist(p2 lhs, p2 rhs)
{
    return ceil(sqrt(1ll * (lhs.F - rhs.F) * (lhs.F - rhs.F) + 1ll * (lhs.S - rhs.S) * (lhs.S - rhs.S)));
}

void build(int idx, int l, int r) {
    if (l == r)
    {
        tree[idx].pb(d[l].S);
        return;
    }
    int idx_l = idx*2;
    int idx_r = idx*2+1;
    int mid = (l + r) >> 1;
    build(idx_l, l, mid);
    build(idx_r, mid + 1, r);
    int it_l = 0, it_r = 0;
    int sz_l = tree[idx_l].size();
    int sz_r = tree[idx_r].size();
    tree[idx].reserve(sz_l + sz_r);
    while (it_l < sz_l && it_r < sz_r)
    {
        if (tree[idx_l][it_l] < tree[idx_r][it_r]) tree[idx].pb(tree[idx_l][it_l++]);
        else tree[idx].pb(tree[idx_r][it_r++]);
    }
    while (it_l < sz_l) tree[idx].pb(tree[idx_l][it_l++]);
    while (it_r < sz_r) tree[idx].pb(tree[idx_r][it_r++]);
}

int query(int idx, int l, int r)
{
    if (d[r].F <= r_a)
        return upper_bound(tree[idx].begin(), tree[idx].end(), r_b) - tree[idx].begin();
    int idx_l = idx << 1;
    int idx_r = idx_l | 1;
    int m = (l + r) >> 1;
    int res = query(idx_l, l, m);
    if (d[m + 1].F <= r_a) res += query(idx_r, m + 1, r);
    return res;
}

void setup()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    scanf("%d %d", &p[i].F, &p[i].S);
}

void work()
{
    scanf("%d %d %d %d %d", &p_a.F, &p_a.S, &p_b.F, &p_b.S, &q);
    for (int i = 1; i <= n; ++i)
    {
        d[i].F = dist(p[i], p_a);
        d[i].S = dist(p[i], p_b);
        if (d[i].F <= 200000) ++in_a[d[i].F];
        if (d[i].S <= 200000) ++in_b[d[i].S];
    }
    sort(d + 1, d + n + 1);
    build(1, 1, n);
    for (int i = 1; i <= 200000; ++i)
    {
        in_a[i] += in_a[i - 1];
        in_b[i] += in_b[i - 1];
    }
    while (q--)
    {
        scanf("%d %d", &r_a, &r_b);
        int k;
        if (r_a < d[1].F) k = 0;
        else k = query(1, 1, n);
        printf("%d\n", in_a[r_a] + in_b[r_b] - k);
    }
}

int main()
{
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    work();
}
