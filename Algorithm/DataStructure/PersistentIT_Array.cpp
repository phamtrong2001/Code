#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define pii pair <int, int>
#define ll long long
#define MOD 1000000007
#define N 200005

using namespace std;

int q, n, nVer, ver[N], a[N];

struct PersistentIT
{
    int nNode;

    struct Node
    {
        int l, r, val;

        Node() {}
        Node(int l, int r, int val) : l(l), r(r), val(val) {}
    } t[1000006];

    int Build(int l, int r)
    {
        if (l == r)
        {
            t[++nNode] = Node(0, 0, a[l]);
            return nNode;
        }
        int cur = ++nNode;
        int mid = (l + r) >> 1;
        t[cur].l = Build(l, mid);
        t[cur].r = Build(mid+1, r);
        t[cur].val = max(t[t[cur].l].val, t[t[cur].r].val);
        return cur;
    }

    int Upd(int l, int r, int x, int val, int oldID)
    {
        if (l == r)
        {
            t[++nNode] = Node(0, 0, val);
            return nNode;
        }
        int mid = (l + r) >> 1;
        int cur = ++nNode;
        if (x <= mid)
        {
            t[cur].l = Upd(l, mid, x, val, t[oldID].l);
            t[cur].r = t[oldID].r;
            t[cur].val = max(t[t[cur].l].val, t[t[cur].r].val);
        }
            else
            {
                t[cur].l = t[oldID].l;
                t[cur].r = Upd(mid+1, r, x, val, t[oldID].r);
                t[cur].val = max(t[t[cur].l].val, t[t[cur].r].val);
            }
        return cur;
    }

    int Get(int l, int r, int u, int v, int nodeID)
    {
        if (l > v || r < u) return -1;
        if (l >= u && r <= v) return t[nodeID].val;
        int mid = (l + r) >> 1;
        return max(Get(l, mid, u, v, t[nodeID].l), Get(mid+1, r, u, v, t[nodeID].r));
    }
} Tree;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    if (fopen(".inp", "r"))
    {
        freopen(".inp", "r", stdin);
        //freopen(".out", "w", stdout);
    }
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> a[i];
    }
    ver[0] = Tree.Build(1, n);
    cin >> q;
    FOR(i, 1, q)
    {
        int type; cin >> type;
        if (type == 1)
        {
            int x, val;
            cin >> x >> val;
            ++nVer;
            ver[nVer] = Tree.Upd(1, n, x, val, ver[nVer-1]);
        }
            else
            {
                int l, r, k;
                cin >> l >> r >> k;
                cout << Tree.Get(1, n, l, r, ver[k]) << '\n';
            }
    }
    return 0;
}
