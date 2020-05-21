#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, p, d[N], dd[N];
vector<pii> a[N];
void reset()
{
    for (int i = 1; i <= n; i++) a[i].clear();
    memset(dd, 0, sizeof dd);
}
void nhap()
{
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        a[u].PB(mp(v, w));
        a[v].PB(mp(u, w));
    }
    for (int i = 1; i <= p; i++)
    {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        a[u].PB(mp(v, -w));
    }
}
void Bell()
{
    bool flag = 0;
    for (int s = 1; s <= n; s++)
    {
        if (dd[s]) continue;
        dd[s] = 1;
        for (int i = 1; i <= n; i++) d[i] = maxc;
        d[s] = 0;
        for (int i = 1; i <= n; i++)
        {
            flag = 0;
            for (int u = 1; u <= n; u++)
                for (int j = 0; j < a[u].size(); j++)
                {
                    int v = a[u][j].F;
                    int w = a[u][j].S;
                    if (d[v] > d[u] + w)
                    {
                        dd[v] = 1;
                        d[v] = d[u] + w;
                        flag = 1;
                    }
                }
        }
        if (flag) {printf("YES \n"); return;}
    }
    printf("NO \n");
}

int main()
{
    freopen("WORMHOLE.INP", "r", stdin);
    freopen("WORMHOLE.OUT", "w", stdout);
    int t; scanf("%d", &t);
    while (t--)
    {
        reset();
        nhap();
        Bell();
    }

}
