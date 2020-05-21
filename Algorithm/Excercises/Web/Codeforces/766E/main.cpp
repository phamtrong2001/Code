#include <bits/stdc++.h>
#define N 100005
#define LN 27
#define PB push_back

using namespace std;

long long n, a[N], luu[LN][2], dd[N], spe[N], sz[N], dem;
long long res;
vector<long long> g[N];
void nhap()
{
    scanf("%d", &n);
    for (long long i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (long long i = 1; i < n; i++)
    {
        long long u, v; scanf("%d %d", &u, &v);
        g[u].PB(v);
        g[v].PB(u);
    }
}
bool bit(long long x, long long i)
{
    return (x >> i) & 1;
}

void dfsCentroid(long long u)
{
    spe[u] = 0; sz[u] = 1;
    dd[u] = 1;
    for (auto v : g[u])
    {
        if (dd[v]) continue;
        dfsCentroid(v);
        if (sz[v] > sz[spe[u]]) spe[u] = v;
        sz[u] += sz[v];
    }
    dd[u] = 0;
}
long long centroid(long long u)
{
    long long siz = sz[u] / 2;
    while (sz[spe[u]] > siz)
        u = spe[u];
    return u;
}
long long get_ans(long long x)
{
    long long res = 0;
    for (long long i = 0; i < LN; i++)
        res += (1ll << i) * (luu[i][bit(x, i) ^ 1]);
    return res;
}
void update(long long x, long long val)
{
    for (long long i = 0; i < LN; i++)
        luu[i][bit(x, i)] += val;
}
void DFS1(long long u, long long dis)
{
    dd[u] = 1;
    res += get_ans(dis);
    for (auto v : g[u])
    {
        if (dd[v]) continue;
        DFS1(v, dis ^ a[v]);
    }
    dd[u] = 0;
}
void DFS2(long long u, long long dis, long long x)
{
    dd[u] = 1;
    update(dis, x);
    for (auto v : g[u])
    {
        if (dd[v]) continue;
        DFS2(v, dis ^ a[v], x);
    }
    dd[u] = 0;
}
void solve(long long u)
{
    dfsCentroid(u);
    u = centroid(u);
    dd[u] = 1;
    dem++;

    long long p = 0;
    for (auto v : g[u])
        if (!dd[v]) p = v;
    dd[p] = 1;
    if (p == 0) {res += a[u]; return;}

    res += a[u];
    //update(a[u], 1);
    DFS1(p, a[u] ^ a[p]);
    DFS2(p, a[p], 1);
    //
    dd[p] = 1;
    for (auto v : g[u])
    {
        if (dd[v]) continue;
        //cerr<<v<<" "<<a[v]<<endl;
        DFS1(v, a[u] ^ a[v]);
        DFS2(v, a[v], 1);
    }
    dd[p] = 1;
    DFS2(p, a[p], -1);
    //update(a[u], -1);
    dd[p] = 1;
    for (auto v : g[u])
    {
        if (dd[v]) continue;
        DFS2(v, a[v], -1);
    }
    dd[p] = 0;

    for (auto v : g[u])
        if (!dd[v]) solve(v);
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    nhap();
    for (long long i = 0; i < LN; i++) luu[i][0] = 1;
    solve(1);
    cout <<res;
}
