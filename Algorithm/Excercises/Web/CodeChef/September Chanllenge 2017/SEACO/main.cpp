#include <bits/stdc++.h>
#define N 100005
#define mid (r + l)/2
#define mod 1000000007
using namespace std;

int n, m;
int val[N], res[N];
struct query
{
    int type, u, v;
    query(int type=0, int u=0, int v=0) : type(type), u(u), v(v) {}
}q[N];

struct IntervalTree
{
    int t[N << 2], lazy[N << 2];
    void reset(int l, int r, int id)
    {
        t[id] = lazy[id] = 0;
        if (l == r) return;
        reset(l, mid, id*2);
        reset(mid+1, r, id*2+1);
    }
    void push(int l, int r, int id)
    {
        if (lazy[id] == 0) return;
        int x = lazy[id]; lazy[id] = 0;
        t[id] = (t[id] + x) % mod;
        if (l == r) return;
        lazy[id*2] = (lazy[id*2] + x) % mod;
        lazy[id*2+1] = (lazy[id*2+1] + x) % mod;

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
        t[id] = (t[id*2] + t[id*2+1]) % mod;
    }
    int get(int l, int r, int id, int x)
    {
        push(l, r, id);
        if (l == r) return t[id];
        if (x <= mid) return get(l, mid, id*2, x);
        return get(mid+1, r, id*2+1, x);
    }
}t;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    int test; cin >> test;
    while (test--)
    {
        cin >> n >> m;
        t.reset(1, m, 1);
        memset(val, 0, sizeof val);
        memset(res, 0, sizeof res);
        for (int i = 1; i <= m; i++)
        {
            int type, u, v;
            cin >> type >> u >> v;
            q[i] = query(type, u, v);
        }
        for (int i = m; i >= 1; i--)
        {
            int dem = t.get(1, m, 1, i);
            if (q[i].type == 1)
                val[i] = dem + 1;
            else t.update(1, m, 1, q[i].u, q[i].v, dem+1);
        }
        for (int i = 1; i <= m; i++)
        {
            if (q[i].type == 2) continue;

            res[q[i].u] = (res[q[i].u] + val[i]) % mod;
            res[q[i].v+1] = (res[q[i].v+1] - val[i]) % mod;
        }
        for (int i = 1; i <= n; i++)
        {
            res[i] = (res[i] + res[i-1]) % mod;
            if (res[i] < 0) res[i] += mod;
            cout <<res[i]<<" ";
        }
        cout <<endl;
    }
}
