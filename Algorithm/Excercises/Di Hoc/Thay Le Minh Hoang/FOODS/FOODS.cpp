#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 300005
#define maxc 1000000007

using namespace std;

int n, m, k, Visited[N], dd[N], Assigned[N], cnt;
vector<int> a[N];

void nhap()
{
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 1; i <= k; i++)
    {
        int u, v; scanf("%d %d", &u, &v);
        a[u].PB(v+m);
        a[v+m].PB(u);
    }
}

bool visit(int u)
{
    if (Visited[u] == cnt) return 0;
    Visited[u] = cnt;
    for (auto v : a[u])
        if (!Assigned[v] || visit(Assigned[v]))
        {
            Assigned[u] = v;
            Assigned[v] = u;
            return 1;
        }
    return 0;
}

void Konig()
{
    queue<int> q;
    for (int i = 1; i <= n+m; i++)
        if (!Assigned[i]) q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : a[u])
        {
            if (dd[v]) continue;
            dd[v] = 1;
            q.push(Assigned[v]);
        }
    }
    for (int i = 1; i <= n+m; i++)
        if (Assigned[i] && !dd[i] && !dd[Assigned[i]]) dd[i] = 1;
}
void solve()
{
    for (int i = 1; i <= m; i++)
        if (!Assigned[i])
        {
            cnt++;
            visit(i);
        }
    Konig();
    int res1 = 0, res2 = 0;
    for (int i = 1; i <= m; i++) if (!dd[i]) res1++;
    for (int i = m+1; i <= m+n; i++) if (!dd[i]) res2++;
    printf("%d %d\n", res1, res2);

    for (int i = 1; i <= m; i++) if (!dd[i]) printf("%d ", i);
    printf("\n");
    for (int i = m+1; i <= m+n; i++) if (!dd[i]) printf("%d ", i-m);
}
int main()
{
    freopen("FOODS.INP", "r", stdin);
    freopen("FOODS.OUT", "w", stdout);
    nhap();
    solve();
}

