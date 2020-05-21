#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 105
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long n, m, k, cnt;
vector<long long> a[N];
map<long long, long long> dd;


void nhap()
{
    cin >> n >> m >> k;
    for (long long i = 1; i <= k; i++)
    {
        long long u, v; cin >> u >> v;
        if (!dd[u]) dd[u] = ++cnt;
        long long id = dd[u];
        a[id].PB(v);
    }
}

void solve()
{
    long long res = (m-1)*(n-cnt);
    for (long long i = 1; i <= cnt; i++)
    {
        sort(a[i].begin(), a[i].end());
        a[i].PB(m+1);
    }
    for (long long i = 1; i <= cnt; i++)
    {
        long long pos = 0;
        for (long long &v : a[i])
        {
            res += max(0ll, v - pos - 2);
            pos = v;
        }
    }
    cout <<res;
}
int main()
{
    nhap();
    solve();

}
