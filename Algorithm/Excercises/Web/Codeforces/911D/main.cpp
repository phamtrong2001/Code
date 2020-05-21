#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1555
#define maxc 1000000007

using namespace std;

int n, m, a[N], res, t[N];

int get(int x)
{
    int ans = 0;
    for (; x; x -= (x & -x)) ans += t[x];
    return ans;
}
void upd(int x, int val)
{
    for (; x < N; x += (x & -x)) t[x] += val;
}

int main()
{
    freopen("INP.TXT", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        res = (res + i-1 - get(a[i])) % 2;
        upd(a[i], 1);
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int l, r; cin >> l >> r;
        int len = r - l + 1;
        int z = len*(len-1)/2;
        if (z % 2 == 1) res ^= 1;
        if (res == 0) cout <<"even"<<endl;
        else cout <<"odd"<<endl;
    }
}
