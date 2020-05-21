#include <bits/stdc++.h>
#define N 205
#define PB push_back
using namespace std;

int n, m, a[N][N], res;
vector<int> path;
void solve()
{
    printf("%d\n", m);
    stack<int> s;
    s.push(1);
    while (!s.empty())
    {
        int u = s.top();
        bool flag = 1;
        for (int v = 1; v <= n; v++)
            if (a[u][v])
            {
                s.push(v);
                a[u][v]--; a[v][u]--;
                flag = 0;
                break;
            }
        if (flag)
        {
            printf("%d ", u);
            s.pop();
        }
    }
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    scanf("%d %d", &n, &m);
    int x;
    for (int i = 1; i <= n; i++) scanf("%d", &x);
    for (int i = 1; i <= m; i++)
    {
        int u, v; scanf("%d %d", &u, &v);
        a[u][v]++;
        a[v][u]++;
    }
    solve();
}
