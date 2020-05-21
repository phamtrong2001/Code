#include <bits/stdc++.h>
#define PB push_back
#define N 300005
using namespace std;

int n, dem[N], belong[N], in[N];
vector<int> a[N];

void nhap()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int sz; scanf("%d", &sz);
        a[i].resize(sz);
        for (int j = 1; j <= sz; j++)
        {
            int x; scanf("%d", &x);
            a[i][j-1] = x;
        }
    }
}

void solve()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        dem[i] = a[i].size();
        if (dem[i] >= 2)
        {
            q.push(i);
            in[i] = 1;
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        in[u] = 0;
        if (dem[u] < 2) continue;

        int count = 0;
        for (auto v : a[u])
        {
            if (belong[u] == belong[v]) dem[v]--;
            else
            {
                dem[v]++;
                count++;
                if (dem[v] == 2 && !in[v])
                {
                    q.push(v);
                    in[v] = 1;
                }
            }
        }
        dem[u] = count;
        belong[u] ^= 1;
    }
}

void inkq()
{
    printf("YES\n");
    for (int i = 1; i <= n; i++)
        if (!belong[i]) printf("%d ", i);
    printf("\n");

    for (int i = 1; i <= n; i++)
        if (belong[i]) printf("%d ", i);
}
int main()
{
    freopen("GROUPDIV.INP", "r", stdin);
    freopen("GROUPDIV.OUT", "w", stdout);
    nhap();
    solve();
    inkq();
}
