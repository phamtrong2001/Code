#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1000005
#define maxc 1000000007

using namespace std;

int m, n, k, delta[N], s[N], q[2*N], cur;
vector<int> a[N];

void nhap()
{
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 1; i <= n; i++) a[i].resize(m);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) scanf("%d", &a[j][i-1]);
    for (int i = 1; i <= n; i++)
    {
        sort(a[i].begin(), a[i].end());
        reverse(a[i].begin(), a[i].end());
        delta[i] = a[i][0];
        for (int j = 0; j < m; j++) a[i][j] -= delta[i];
        s[i] = s[i-1] + delta[i];
    }
}
bool check(int row, int val)
{
    if (row > n) return 0;
    for (int i = 1; i < m; i++)
    {
        if (val - a[row][i] > 0) break;
        int zz = val - a[row][i];
        q[++cur] = zz;
    }
    if (cur >= k) return 1;
    for (int i = 0; i < m; i++)
    {
        if (val - a[row][i] > 0) break;
        int zz = val - a[row][i];
        if (check(row+1, zz)) return 1;
    }
    return 0;
}
void solve()
{
    int l = -maxc, r = 1;
    while (r - l > 1)
    {
        int mid = (r + l)/2;
        q[1] = mid; cur = 1;
        if (check(1, mid)) l = mid;
        else r = mid;
    }
    q[1] = l+1; cur = 1;
    check(1, l+1);
    sort(q+1, q+cur+1);
    int pos = cur + 1;
    ll res = 0;
    for (int i = 1; i <= cur; i++)
        res -= q[i];

    res += (s[n] + l + 1)*cur;
    for (int i = cur+1; i <= k; i++)
        res += l + s[n];
    cout <<res;
}
int main()
{
    freopen("LANDSEL.INP", "r", stdin);
    freopen("LANDSEL.OUT", "w", stdout);
    nhap();
    solve();
}
