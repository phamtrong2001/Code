#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

long long n, m, q, res1, b[N], x[N];
long long solve(long long val)
{
    long long pos = lower_bound(x, x+m-n+1, val) - x;
    if (pos == 0) return abs(res1 - x[pos]);
    if (pos == m-n+1) return abs(res1 - x[pos-1]);
    return min(abs(res1-x[pos]), abs(res1-x[pos-1]));
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    cin >> n >> m >> q;
    for (long long i = 1; i <= n; i++)
    {
        long long x; cin >> x;
        if (i % 2) res1 += x;
        else res1 -= x;
    }
    for (long long i = 1; i <= m; i++)
    {
        cin >> b[i];
        if (i % 2) b[i] = b[i-1] + b[i];
        else b[i] = b[i-1] - b[i];
    }
    for (long long i = 0; i <= m-n; i++)
    {
        if (i % 2) x[i] = -b[i+n] + b[i];
        else x[i] = b[i+n] - b[i];
    }
    sort(x, x+m-n+1);
    cout <<solve(res1)<<endl;
    for (long long i = 1; i <= q; i++)
    {
        long long l, r, val; cin >> l >> r >> val;
        long long len = r - l + 1;
        if (len % 2 == 0)
        {
            cout <<solve(res1)<<endl;
            continue;
        }
        if (l % 2) res1 += val;
        else res1 -= val;
        cout <<solve(res1)<<endl;
    }
}
