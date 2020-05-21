#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1000005
#define maxc 1000000007

using namespace std;

int n, a[N], M, res;

int main()
{
    freopen("GRAB.INP", "r", stdin);
    freopen("GRAB.OUT", "w", stdout);
    scanf("%d %d", &n, &M);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    res = n;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] + n - 1 > M) break;
        int pos = upper_bound(a+1, a+n+1, a[i] + n - 1) - a - 1;
        res = min(res, n - (pos - i + 1));
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] - n + 1 < 0) continue;
        int pos = lower_bound(a+1, a+n+1, a[i] - n + 1) - a;
        res = min(res, n - (i - pos + 1));
    }
    cout <<res;
}
