#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1005
#define M 1000005
#define maxc 1000000007

using namespace std;

int n, dd[M], root[M], sz[M], res, tt, a[N][N], cur;

struct edge
{
    int u, v, w;
    edge(int u=0, int v=0, int w=0) : u(u), v(v), w(w) {}
}e[M*4];
bool cmp(edge p, edge q) {return p.w < q.w; }

void reset(int u)
{
    if (dd[u] == tt+1) return;
    dd[u] = tt+1;
    root[u] = 0;
    sz[u] = 1;
}
int get_root(int u)
{
    reset(u);
    return (root[u] == 0) ? u : root[u] = get_root(root[u]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("PVOI14_2.INP", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int u = i+1;
            if (u <= n) e[++cur] = edge((i-1)*n+j, (u-1)*n+j, abs(a[i][j] - a[u][j]));
            int v = j+1;
            if (v <= n) e[++cur] = edge((i-1)*n+j, (i-1)*n+v, abs(a[i][j] - a[i][v]));
        }
    sort(e+1, e+cur+1, cmp);

    int j = 1;
    for (tt = 0; tt < N*N; tt++)
    {
        while (j <= cur && e[j].w == tt)
        {
            int p = get_root(e[j].u);
            int q = get_root(e[j].v);
            res = max(res, max(sz[p], sz[q]));
            if (p != q)
            {
                root[p] = q;
                sz[q] += sz[p];
                res = max(res, sz[q]);
            }
            j++;
        }
    }
    cout <<res;
}
