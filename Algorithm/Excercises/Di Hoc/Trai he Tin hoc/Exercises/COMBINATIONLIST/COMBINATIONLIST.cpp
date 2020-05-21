#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 10004
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long n, m, k, c[N][N], luu[N], zz;
void nhap()
{
    cin >> n >> m >> k;
}

int main()
{
    freopen("INP.TXT", "r", stdin);
    nhap();
    c[0][0] = 1;
    for (long long i = 1; i <= n; i++)
        for (long long j = 0; j <= i; j++) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;

    if (c[n][m] < k) {cout <<-1; return 0;}
    for (long long i = 1; i <= m; i++)
    {
        for (long long j = luu[i-1]+1; j <= n; j++)
        {
            if (k > c[n-j][m-i]) k = (k - c[n-j][m-i] + mod) % mod;
            else
            {
                luu[i] = j;
                break;
            }
        }
    }
    for (long long i = 1; i <= m; i++) cout <<luu[i]<<" ";
}
