#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 50
#define maxc 1000000007

using namespace std;

long long n, mod, curS, a[N], b[N], res;
vector<long long> v[3];

void duyet(long long pos, long long pMax, long long id)
{
    if (pos > pMax)
    {
        v[id].PB(curS % mod);
        return;
    }
    curS += b[pos];
    duyet(pos+1, pMax, id);
    curS -= b[pos];
    duyet(pos+1, pMax, id);
}

void solve(long long id1, long long id2)
{
    for (auto x : v[id1])
    {
        int pos = lower_bound(v[id2].begin(), v[id2].end(), mod-x) - v[id2].begin() - 1;
        if (pos >= 0) res = max(res, x + v[id2][pos]);
    }
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    cin >> n >> mod;
    for (long long i = 1; i <= n; i++) cin >> a[i];

    long long cur = 0;
    for (long long i = 1; i <= n/2; i++) b[++cur] = a[i];
    duyet(1, cur, 1);
    cur = 0;
    for (long long i = n/2+1; i <= n; i++) b[++cur] = a[i];
    duyet(1, cur, 2);
    sort(v[1].begin(), v[1].end());
    sort(v[2].begin(), v[2].end());
    solve(1, 2);
    solve(2, 1);
    cout <<res;
}
