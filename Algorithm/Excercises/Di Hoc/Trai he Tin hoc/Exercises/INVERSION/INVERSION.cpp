#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1000005
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long n, m, res[N], p[N];
void solve(long long x, long long y)
{
    long long pos = n;
    for (long long i = 1; i < n; i++)
    {
        if (y >= i) y -= i;
        else
        {
            pos = i;
            break;
        }
    }
    for (long long i = 1; i <= n-pos; i++) res[i] = i;
    long long dd = n;
    for (long long i = n-pos+1; i <= n; i++)
        res[i] = dd--;
    for (long long i = n; i >= 1; i--)
    {
        if (y-- == 0) break;
        swap(res[i], res[n-pos]);
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++) ans = (ans + (res[i]*p[i-1]) % mod) % mod;
    cout <<ans<<'\n';
    //cout <<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INVERSION.INP", "r", stdin);
    freopen("INVERSION.OUT", "w", stdout);
    p[0] = 1;
    for (long long i = 1; i < N; i++) p[i] = (p[i-1]*2) % mod;
    long long t; cin >> t;
    while (t--)
    {
        cin >> n >> m;
        if (m > (n*(n-1))/2) {cout <<-1<<'\n'; continue;}
        solve(n, m);
    }

}
