/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxc 1000000007
#define task "arithmetic"
#define maxn 100005

using namespace std;

int m, n, a[maxn];
long long t[maxn*4];

void make(int l, int r, int id)
{
    if (l == r)
        {
            t[id] = a[l];
            return;
        }
    int mid = (l + r) >> 1;
    make(l, mid, id*2);
    make(mid+1, r, id*2+1);
}

struct IT
{
    void update1(int l, int r, int id, int u, int v, int w)
    {
        if (l > v || r < u) return;
        if (l == r)
            {
                t[id] = (t[id] + w) % maxc;
                return;
            }
        int mid = (l + r) >> 1;
        update1(l, mid, id*2, u, v, w);
        update1(mid+1, r, id*2+1, u, v, w);
    }
    void update2(int l, int r, int id, int u, int v, int w)
    {
        if (l > v || r < u) return;
        if (l == r)
            {
                t[id] = (t[id] * w) % maxc;
                return;
            }
        int mid = (l + r) >> 1;
        update2(l, mid, id*2, u, v, w);
        update2(mid+1, r, id*2+1, u, v, w);
    }
    long long get(int l, int r, int id, int x)
    {
        if (l  == r) return t[id];
        int mid = (l + r) >> 1;
        if (mid >= x) return get(l ,mid, id*2, x);
            else return get(mid+1, r, id*2+1, x);
    }
}tree;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    make(1, n, 1);
    cin >> m;
    while (m--)
    {
        char type;
        cin >> type;
        if (type == '+')
        {
            int u, v, d;
            cin >> u >> v >> d;
            tree.update1(1, n, 1, u, v, d);
        }
        else if (type == '*')
            {
                int u, v, d;
                cin >> u >> v >> d;
                tree.update2(1, n, 1, u, v, d);
            }
            else
            {
                int p;
                cin >> p;
                cout << tree.get(1, n, 1, p) % maxc << endl;
            }
    }
    return 0;
}
