#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>
#define piii pair<pii, int>
#define maxn 100005

using namespace std;

int n, m, a[maxn], res[maxn], s, cur, dem[maxn];
pair<pii, int> q[maxn];
bool cmp(piii p, piii q)
{
    if (p.F.F/s != q.F.F/s) return p.F.F/s < q.F.F/s;
    return p.F.S < q.F.S;
}
void upd(int x, int val)
{
    if (x > n) return;
    if (dem[x] == x) cur--;
    dem[x] += val;
    if (dem[x] == x) cur++;
}
void nhap()
{
    cin >> n >> m;
    s = sqrt(n);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        q[i] = mp(mp(u, v), i);
    }
    sort(q+1, q+m+1, cmp);
}
void solve()
{
    int l = 1; int r = 0;
    for (int i = 1; i <= m; i++)
    {
        int x = q[i].F.F;
        int y = q[i].F.S;
        int id = q[i].S;
        while (l > x) upd(a[--l], 1);
        while (r < y) upd(a[++r], 1);
        while (l < x) upd(a[l++], -1);
        while (r > y) upd(a[r--], -1);
        res[id] = cur;
    }
}
int main()
{
    //freopen("INP.TXT", "r", stdin);
    nhap();
    solve();
    for (int i = 1; i <= m; i++) cout <<res[i]<<endl;
}
