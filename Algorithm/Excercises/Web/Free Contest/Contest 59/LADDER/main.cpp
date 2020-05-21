#include <bits/stdc++.h>
#define N 100005
using namespace std;

int n, m, a[N], f[N];
void nhap()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
}
void solve()
{
    for (int i = 1; i < n; i++)
        f[i] = f[i-1] + (a[i] <= a[i+1]);
    for (int i = 1; i <= m; i++)
    {
        int u, v; scanf("%d %d", &u, &v);
        if (v - u <= 1)
        {
            printf("Yes\n");
            continue;
        }
        int l = u, r = v;
        while (r - l > 1)
        {
            int mid = (r + l) >> 1;
            if (f[mid-1] - f[u-1] == mid - u) l = mid;
            else r = mid;
        }
        if (f[v-1] - f[l] == 0) printf("Yes\n");
        else printf("No\n");
    }
}
int main()
{
    //freopen("INP.TXT", "r", stdin);
    nhap();
    solve();
}
