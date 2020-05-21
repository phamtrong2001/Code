#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define PB push_back
#define F first
#define S second
#define N 400005
#define maxc 1000000007

using namespace std;

int n, m, f[N], tb[2*N], x[2*N], p[N][20], key[N][20], c[N];
pair<int, pii> a[N];
pii arr[N];
vector<int> b[N], luu[N];

struct IT
{
    vector<int> t;

    int ss(int r1, int r2)
    {
      int u1 = r1;
      int u2 = r2;
      int key1 = u1;
      int key2 = u2;
      for (int i = 19; i >= 0; i--)
        if (p[u1][i] != p[u2][i])
        {
          key1 = min(key1, key[u1][i]);
          key2 = min(key2, key[u2][i]);
          u1 = p[u1][i];
          u2 = p[u2][i];
        }
      return key1 < key2 ? r1 : r2;
    }

    void build(int l, int r, int id, int x)
    {
        if (l == r)
        {
            t[id] = b[x][l];
            return;
        }
        int mid = (r + l) >> 1;
        build(l, mid, id*2, x);
        build(mid+1, r, id*2+1, x);
        t[id] = ss(t[id*2], t[id*2+1]);
    }
    int get_max(int l, int r, int id, int u, int v)
    {
        if (l > v || r < u) return 0;
        if (l >= u && r <= v) return t[id];
        int mid = (r + l) >> 1;
        int a = get_max(l, mid, id*2, u, v);
        int b = get_max(mid+1, r, id*2+1, u, v);
        if (a == 0) return b;
        if (b == 0) return a;
        return ss(a, b);
    }
}t[N];

void add(int u)
{
    p[u][0] = c[u];
    key[u][0] = c[u];
    for (int i = 1; i <= 19; i++)
    {
        p[u][i] = p[p[u][i-1]][i-1];
        key[u][i] = min(key[u][i-1], key[p[u][i-1]][i-1]);
    }
}
void read()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].S.F >> a[i].F;
        arr[i] = mp(a[i].S.F, a[i].F);
        a[i].S.S = i;
        x[++m] = a[i].S.F;
        x[++m] = a[i].F;
    }
    sort(x+1, x+m+1); m = unique(x+1, x+m+1) - x;
    for (int i = 1; i <= n; i++)
    {
        a[i].F = lower_bound(x+1, x+m+1, a[i].F) - x;
        a[i].S.F = lower_bound(x+1, x+m+1, a[i].S.F) - x;
        arr[i].F = lower_bound(x+1, x+m+1, arr[i].F) - x;
        arr[i].S = lower_bound(x+1, x+m+1, arr[i].S) - x;
    }
    sort(a+1, a+n+1);
}

void upd(int x, int val)
{
    for (; x <= N; x += (x & -x)) tb[x] = max(tb[x], val);
}
int get(int x)
{
    int ans = 0;
    for (; x; x -= (x & -x)) ans = max(ans, tb[x]);
    return ans;
}

void prepare()
{
    for (int i = 1; i <= n; i++)
    {
        int id = a[i].S.S;
        f[id] = get(a[i].S.F - 1) + 1;
        upd(a[i].F, f[id]);
        b[f[id]].PB(id);
        luu[f[id]].PB(arr[id].S);
    }
}
void solve()
{
    int res = *max_element(f+1, f+n+1);
    cout <<res<<'\n';

    for (int i = 0; i < b[1].size(); i++)
    {
        c[b[1][i]] = n+1;
        add(b[1][i]);
    }
    int sz = b[1].size();
    t[1].t.resize(sz*4 + 5);
    t[1].build(0, sz-1, 1, 1);
    for (int k = 2; k <= res; k++)
    {
        for (int i = 0; i < b[k].size(); i++)
        {
            int id = b[k][i];
            int zz = upper_bound(luu[k-1].begin(), luu[k-1].end(), arr[id].F) - luu[k-1].begin() - 1;
            c[id] = t[k-1].get_max(0, b[k-1].size()-1, 1, 0, zz);
            add(id);
        }
        sz = b[k].size();
        t[k].t.resize(sz*4 + 5);
        t[k].build(0, sz-1, 1, k);
    }
    int zz = lower_bound(luu[res].begin(), luu[res].end(), N+5) - luu[res].begin();
    c[n+1] = t[res].get_max(0, b[res].size()-1, 1, 0, zz);
}
void inkq()
{
    vector<int> v;
    int u = n+1;
    u = c[u];
    while (u != n+1)
    {
        v.PB(u);
        u = c[u];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) cout <<v[i]<<" ";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("CONV_C.INP", "r", stdin);
    freopen("CONV_C.OUT", "w", stdout);
    read();
    prepare();
    solve();
    inkq();
}
