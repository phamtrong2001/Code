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

int n, m, vetex[N], edge[N], cur, dd[N];
long long k;
vector<int> a[N];
void stop(int x)
{
    cout <<x;
    exit(0);
}
void DFS(int u)
{
    dd[u] = 1;
    for (int &v : a[u])
    {
        if (dd[v]) continue;
        vetex[cur]++;
        DFS(v);
    }
    edge[cur] += a[u].size();
}
void nhap()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].PB(v);
        a[v].PB(u);
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        if (dd[i]) continue;
        cur++;
        vetex[cur] = 1;
        DFS(i);
        edge[cur]/=2;
    }
    int dem = 0;
    for (int i = 1; i <= cur; i++)
        dem += (vetex[i]*(vetex[i]-1)/2) - edge[i];
    int res1 = 0;
    if (k >= cur-1) res1 = 1;
    else res1 = cur-k;
    cout <<res1<<" ";

    k -= dem;
    int res2 = cur;
    if (k <= 0) stop(res2);
    sort(vetex+1, vetex+cur+1);
    reverse(vetex+1, vetex+cur+1);
    res2--;
    int now = vetex[1];
    for (int i = 2; i <= cur; i++)
    {
        k -= 1ll*vetex[i]*now;
        if (k <= 0) stop(res2);
        else res2--;
    }
    if (res2 == 0) res2 == 1;
    stop(res2);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("REGIONS.INP", "r", stdin);
    freopen("REGIONS.OUT", "w", stdout);
    nhap();
    solve();

}
