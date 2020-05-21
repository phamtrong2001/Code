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

int n, q, a[N], nVer;

struct PersistentIT
{
    struct Node
    {
        int val;
        Node *l, *r;
    } *ver[1000006];

    void Build(Node *&p, int l, int r)
    {
        p = new Node();
        if (l == r)
        {
            p->val = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        Build(p->l, l, mid);
        Build(p->r, mid+1, r);
        p->val = max(p->l->val, p->r->val);
    }

    void Upd(Node *&p, int l, int r, int x, int val)
    {
        p = new Node(*p);
        if (l == r)
        {
            p->val = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            Upd(p->l, l, mid, x, val);
            p->val = max(p->l->val, p->r->val);
        }
            else
            {
                Upd(p->r, mid+1, r, x, val);
                p->val = max(p->l->val, p->r->val);
            }
    }

    int Get(Node *p, int l, int r, int u, int v)
    {
        if (l > u || r < v) return -1;
        if (l >= u && r <= v) return p->val;
        int mid = (l + r) >> 1;
        return max(Get(p->l, l, mid, u, v), Get(p->r, mid+1, r, u, v));
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
    FOR(i, 1, n) cin >> a[i];
    Tree.Build(Tree.ver[0], 1, n);
    cin >> q;
    FOR(i, 1, q)
    {
        int type; cin >> type;
        if (type == 1)
        {
            int x, val;
            cin >> x >> val;
            nVer++;
            Tree.ver[nVer] = Tree.ver[nVer-1];
            Tree.Upd(Tree.ver[nVer], 1, n, x, val);
        }
            else
            {
                int l, r, k;
                cin >> l >> r >> k;
                cout << Tree.Get(Tree.ver[k], 1, n, l, r) << '\n';
            }
    }
    return 0;
}
