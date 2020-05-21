#include <bits/stdc++.h>
#define maxn 100005
#define minC 2
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define F first
#define S second

using namespace std;

int n, m, l, luu[minC][maxn];
long long max1, max2, max3, max4, d[minC][maxn];
bool dd[minC][maxn];
vector < pair<int, int>> a[maxn];

void enter()
{
    scanf("%d %d %d", &n, &m, &l);

    int u, v, w;
    FOR(i, 1, m)
    {
        scanf("%d %d %d", &u, &v, &w);
        a[u + 1].push_back(make_pair(v + 1, w));
        a[v + 1].push_back(make_pair(u + 1, w));
    }
    max1 = max2 = max3 = -1;
}

void DFS(int u, int key)
{
    dd[key][u] = true;
    for (pair <int, int> p: a[u])
    {
        int v = p.F, w = p.S;
        if (dd[key][v]) continue;
        DFS(v, key);

        if (d[key][v] + w > d[key][u]) {
            luu[key][u] = v;
            d[key][u] = d[key][v] + w;
        }
    }
}

void update(int x)
{
    if (max3 < x && x <= max2)
        max3 = x;
    if (max2 < x && x <= max1)
        max3 = max2, max2 = x;
    if (max1 < x)
        max3 = max2, max2 = max1, max1 = x;
}

void check()
{
    if (max1 > -1 && max2 > -1) max1 = max1 + max2 + l;
    if (max2 > -1 && max3 > -1) max2 = max2 + max3 + 2 * l;
}

void operate(int i)
{
    DFS(i, 0);
    int u = i;
    while (luu[0][u])
        u = luu[0][u];

    DFS(u, 1);
    long long x, answer;
    max4 = max(max4, d[1][u]);
    x = answer = d[1][u];

    while (luu[1][u])
    {
        u = luu[1][u];
        answer = min(answer, max(d[1][u], x - d[1][u]));
    }
    update(answer);
}

void write()
{
    check();
    printf("%lld", max(max1, max(max2, max4)));
}

int main()
{
    freopen("dreaming.inp", "r", stdin);
    freopen("dreaming.out", "w", stdout);
    enter();
    FOR(i, 1, n)
        if (!dd[0][i])
            operate(i);
    write();
}
