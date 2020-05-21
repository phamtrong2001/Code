#include <bits/stdc++.h>
#define maxn 100005
using namespace std;

int n, m, s, a[maxn], dem[maxn], next[maxn], kt[maxn], pos[maxn];
void upd(int u, int v)
{
    if (v > n) {dem[u] = 1; next[u] = -1; kt[u] = u;}
    else
    {
        if (pos[u] == pos[v]) {dem[u] = dem[v]+1; next[u] = next[v]; kt[u] = kt[v];}
        else {next[u] = v; dem[u] = 1; kt[u] = kt[v];}
    }
}
void xuli1(int x)
{
    int ans = 0, f;
    for (; x != -1; x = next[x])
    {
        ans += dem[x];
        f = kt[x];
    }
    printf("%d %d\n", f, ans);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("INP.TXT", "r", stdin);
    scanf("%d%d", &n, &m);
    s = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        pos[i] = (i-1)/s+1;
        scanf("%d", &a[i]);
    }
    for (int i = n; i >= 1; i--) upd(i, i+a[i]);
    while (m--)
    {
        int z, u, v;
        scanf("%d", &z);
        if (z == 1)
        {
            scanf("%d", &u);
            xuli1(u);
        }
        else
        {
            scanf("%d%d", &u, &v);
            a[u] = v;
            int r = min(n, pos[u]*s); int l = (pos[u]-1)*s+1;
            for (int i = r; i >= l; i--) upd(i, a[i]+i);
        }
    }
}
