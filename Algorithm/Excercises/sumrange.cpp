#include <bits/stdc++.h>
#define maxn 100005
#define maxc 1000000007

using namespace std;

int m, n, a[maxn];

long long t[4*maxn];

void make(int l, int r, int id)
{
    if (l == r) {t[id] = a[l]; return;}
    int mid = (l+r) >> 1;
    make(l, mid, id*2);
    make(mid+1, r, id*2+1);
    t[id] = t[id*2] + t[id*2+1];
}

void update(int l, int r, int id, int x)
{
    if (l > x || r < x) return;
    if (l == r) {t[id] = a[x]; return;}
    int mid = (l+r) >> 1;
    update(l, mid, id*2, x);
    update(mid+1, r, id*2+1, x);
    t[id] = t[id*2] + t[id*2+1];
}

void tinh1()
{
    int x, y;
    cin >> x >> y;
    a[x] = y;
    update(1, n, 1, x);
}

long long get_sum(int l, int r, int id, int u, int v)
{
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return t[id];
    int mid = (l+r) >> 1;
    long long m1 = get_sum(l, mid, id*2, u, v);
    long long m2 = get_sum(mid+1, r, id*2+1, u, v);
    return m1+m2;
}

void tinh2()
{
    int l, r;
    cin >> l >> r;
    cout << get_sum(1, n, 1, l, r) << endl;
}

int main()
{
    freopen("sumrange.inp", "r", stdin);
    freopen("sumrange.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    make(1, n, 1);
    for (int i = 1; i <= m; i++)
    {
        int type;
        cin >> type;
        if (type == 1) tinh1();
            else tinh2();
    }
    return 0;
}
