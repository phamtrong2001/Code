#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define int long long
#define PB push_back
#define N 500005
#define maxc 1000000007

using namespace std;

int n, k, val[N], f[N], vMax;
vector<int> a[N];


int DFS(int u, int p, int vv)
{
    f[u] = val[u];
    int ans = 0;
    priority_queue<int> q;
    for (auto v : a[u])
    {
        if (v == p) continue;
        ans += DFS(v, u, vv);
        f[u] += f[v];
        if (ans > k) return ans;
        q.push(f[v]);
    }
    while (f[u] > vv)
    {
        int x = q.top();
        q.pop();
        ans++;
        f[u] -= x;
    }
    return ans;
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("TRCUT.INP", "r", stdin);
    freopen("TRCUT.OUT", "w", stdout);
    scanf("%d %d", &n, &k);
    int vSum = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &val[i]), vMax = max(vMax, val[i]), vSum += val[i];
    for (int i = 1; i < n; i++)
    {
        int u, v; scanf("%d %d", &u, &v);
        a[u].PB(v);
        a[v].PB(u);
    }
    int l = vMax-1, r = vSum;
    while (r - l > 1)
    {
        int mid = (r + l)/2;
        if (DFS(1, -1, mid) > k) l = mid;
        else r = mid;
    }
    printf("%d", r);
}
