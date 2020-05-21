#include <bits/stdc++.h>
#define PB push_back
#define N 200005
using namespace std;

int n, m, Visited[N], Assigned[N], t, cant[N], pre[N], nex[N], pos[N];
vector<int> a[N];

bool visit(int u)
{
    if (Visited[u]!=t) Visited[u]=t;
    else  return false;

    for (; pos[u] < a[u].size(); pos[u]++)
    {
        int v = a[u][pos[u]];
        if (!Assigned[v] || visit(Assigned[v])) {
            Assigned[v]=u;
            return true;
        }
    }
    return false;
}

int main()
{
    freopen("MASSIGN.INP", "r", stdin);
    freopen("MASSIGN.OUT", "w", stdout);
    srand(time(NULL));
    scanf("%d%d", &m, &n);
    int x, y;
    while (scanf("%d%d", &x, &y) > 0)
        a[x].push_back(y);

    nex[0] = 1;
    for (int u = 1; u <= m; u++)
        pre[u] = u-1, nex[u] = u+1;

    int Count = 0, day = 0;
    while (Count < n)
    {
        day++;
        int u = 0;
        if (m != 50000) memset(pos, 0, sizeof pos);
        while (nex[u] <= m)
        {
            t++;
            u = nex[u];
            if (visit(u)) Count++;
            else
            {
                nex[pre[u]] = nex[u];
                pre[nex[u]] = pre[u];
            }
        }
    }
    printf("%d\n", day);
    for (int i=1; i<=n; i++)
    if (int j=Assigned[i])
    printf("%d ", j);
}
