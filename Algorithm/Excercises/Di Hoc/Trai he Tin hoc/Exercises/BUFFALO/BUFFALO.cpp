#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 3005
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long n, k, c[N][N];
void prepare()
{
    c[0][0] = 1;
    for (long long i = 1; i < N; i++)
        for (long long j = 0; j <= i; j++) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
}
void solve()
{
    long long res = 0;
    for (long long i = 0; i <= n; i++)
        for (long long j = 0; j <= i; j++)
        {
            long long x = i - j;
            if (x > k) continue;
            res = (res + c[i][j]*c[n-i][x] % mod) % mod;
        }
    cout <<res<<endl;
}
int main()
{
    prepare();
    while (cin >> n >> k)
    {
        solve();
    }
}
