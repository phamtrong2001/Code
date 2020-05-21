#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 100005
#define maxm 1000006
 
using namespace std;
 
int n, m, q, T, root[maxn];
 
struct data
{
    int u, v, w;
};
 
data a[maxm], b[maxm];
 
void nhap()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
        cin >> a[i].u >> a[i].v >> a[i].w;
}
 
int get_root(int u)
{
    return (root[u] ? root[u] = get_root(root[u]) : u);
}
 
void kruskal(int k)
{
	memset(root, 0, sizeof(root));
    for (int i = 1; i <= m; i++)
    {
        if (b[i].w >= b[k].w) continue;
        int p = get_root(b[i].u);
        int q = get_root(b[i].v);
        if (p == q) continue;
        root[p] = q;
    }
}
 
void xuli(int k, int t)
{
    for (int i = 1; i <= m; i++)
        b[i] = a[i];
    for (int i = 1; i <= t; i++)
    {
        int s, c;
        cin >> s >> c;
        b[s].w = c;
    }
    kruskal(k);
    cout << ((get_root(b[k].u) != get_root(b[k].v)) ? "NO\n" : "YES\n");
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("comnet.inp", "r", stdin);
    freopen("comnet.out", "w", stdout);
    cin >> T;
    for (int i = 1; i <= T; i++)
        {
            nhap();
            for (int j = 1; j <= q; j++)
            {
                int k, t;
                cin >> k >> t;
                xuli(k, t);
            }
        }
    return 0;
}