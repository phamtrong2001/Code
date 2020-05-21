#include <bits/stdc++.h>
#define N 3005
#define PB push_back
using namespace std;

int n, m, d[N], res[N];
vector<int> a[N];
void nhap()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v; scanf("%d %d", &u, &v);
        a[u].PB(v);
        a[v].PB(u);
    }
}
void BFS(int u)
{
    memset(d, 60, sizeof d);
    d[u] = 0;
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : a[u])
        {
            if (d[v] > d[u] + 1)
            {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (d[i] <= 1) continue;
        int x = log2(d[i] - 1) + 1;
        res[x]++;
    }
}
void solve()
{
    for (int i = 1; i <= n; i++) BFS(i);
    int x = 1;
    while (res[x] != 0) printf("%d ", res[x++]/2);
    printf("0");
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    nhap();
    solve();
}
