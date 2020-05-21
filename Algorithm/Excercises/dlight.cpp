/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pii pair<int, int>
#define sz(x) ((int) x.size())
#define PB push_back
#define PF push_front
#define MP make_pair
#define ll long long
#define F first
#define S second
#define maxc 1000000007
#define MOD 1000000007
#define base 107
#define eps 1e-6
#define maxn 200005
#define task "dlight"
#define remain(x) ((x > MOD) ? (x - MOD) : x)

using namespace std;

int n, t, dem = 0, all[maxn], res = 0;

pii q[maxn];

struct IT
{
    int t[maxn << 2], lazy[maxn << 2];

    void push(int l, int r, int id)
    {
        t[id] += lazy[id];
        int x = lazy[id];
        lazy[id] = 0;
        if (l == r) return;
        lazy[id*2] += x;
        lazy[id*2+1] += x;
    }

    void update(int l, int r, int id, int u, int v)
    {
        push(l, r, id);
        if (l > v || r < u) return;
        if (l >= u && r <= v)
        {
            lazy[id]++;
            push(l, r, id);
            return;
        }
        int mid = (l + r) >> 1;
        update(l, mid, id*2, u, v);
        update(mid+1, r, id*2+1, u, v);
    }

    int get(int l, int r, int id, int x)
    {
        push(l, r, id);
        if (l == r) return t[id];
        int mid = (l + r) >> 1;
        if (x <= mid) return get(l, mid, id*2, x);
        return get(mid+1, r, id*2+1, x);
    }

} Tree1, Tree2;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> t;
    int l = maxc, r = -maxc;
    FOR(i, 1, t)
    {
        int u, v;
        cin >> u >> v;
        q[i] = MP(u, v);
        all[++dem] = u;
        all[++dem] = v;
        l = min(l, u);
        r = max(r, v);
    }
    sort(all+1, all+dem+1);
    dem = unique(all+1, all+dem+1) - all - 1;
    FOR(i, 1, t)
    {
        q[i].F = lower_bound(all+1, all+dem+1, q[i].F) - all;
        q[i].S = lower_bound(all+1, all+dem+1, q[i].S) - all;
        Tree1.update(1, dem, 1, q[i].F, q[i].S-1);
        Tree2.update(1, dem, 1, q[i].F, q[i].S);
    }
    FOR(i, 1, dem)
    {
        int pos = Tree1.get(1, dem, 1, i);
        int dd = ((pos % 3) ? 0 : 1);
        res += (Tree2.get(1, dem, 1, i) % 3 == 0);
        if (i != dem) res += dd * (all[i+1] - all[i] - 1);
    }
    cout << res + l - 1 + n - r;
    return 0;
}
