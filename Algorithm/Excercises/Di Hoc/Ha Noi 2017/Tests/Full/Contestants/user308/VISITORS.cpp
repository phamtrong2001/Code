#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1ll*1000000000000000007

using namespace std;

long long n, x[N], dist[N], dp[N], posIn[N];
pii a[N];

struct IntervalTree
{
    long long t[N];
    long long get(long long x)
    {
        long long ans = maxc;
        for (; x; x -= (x & -x)) ans = min(ans, t[x]);
        return ans;
    }
    void upd(long long x, long long val)
    {
        for (; x < N; x += (x & -x)) t[x] = min(t[x], val);
    }
}t1, t2;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("VISITORS.INP", "r", stdin);
    freopen("VISITORS.OUT", "w", stdout);
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> x[i];
        dist[i] = dist[i-1] + abs(x[i] - x[i-1]);
        a[i] = mp(x[i], i);
    }
    a[n+1] = mp(0, n+1);
    sort(a+1, a+n+2);
    for (long long i = 1; i <= n+1; i++) posIn[a[i].S] = i;
    memset(dp, 60, sizeof dp);
    dp[1] = abs(x[1]);
    for (long long i = 1; i <= n; i++)
    {
        t1.t[i] = t2.t[i] = maxc;
    }
    t1.upd(posIn[n+1], dp[1] - dist[1]);
    t2.upd(n-posIn[n+1]+2, dp[1] - dist[1]);
    for (long long i = 2; i <= n; i++)
    {
        long long id = posIn[i];
        dp[i] = min(dp[i], dist[i-1] + x[i] + t1.get(id-1));
        dp[i] = min(dp[i], dist[i-1] - x[i] + t2.get(n-id+1));
        long long id2 = posIn[i-1];
        t1.upd(id2, dp[i] - dist[i] - x[i-1]);
        t2.upd(n-id2+2, dp[i] - dist[i] + x[i-1]);
    }
    long long res = maxc;
    for (long long i = 1; i <= n; i++)
    {
        res = min(res, dp[i] + dist[n] - dist[i]);
    }
    cout <<res;
}
