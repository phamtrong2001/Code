#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 10005
#define mod 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

long long n, k, x, sum[N], dp[N][N];
vector<long long> v;
int main()
{
    freopen("INP.TXT", "r", stdin);
    cin >> n >> k >> x;
    dp[0][0] = 1;
    sum[0] = 1;
    x--;
    for (long long i = 1; i <= n; i++)
    {
        dp[i][0] = (dp[i][0] + sum[i-1]) % mod;
        sum[i] = (sum[i] + dp[i][0]) % mod;
        for (long long j = 1; j <= x; j++)
        {
            dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
            sum[i] = (sum[i] + dp[i][j]) % mod;
        }
    }
    long long pos = n;
    while (pos > 0)
    {
        for (long long i = x; i >= 0; i--)
        {
            if (dp[pos][i] < k) k -= dp[pos][i];
            else
            {
                v.PB(i);
                pos -= i+1;
                break;
            }
        }
    }
    int dem = 0;
    for (long long i = 0; i < v.size(); i++)
    {
        dem += v[i];
        for (long long j = 1; j <= v[i]; j++) cout <<0<<" ";
        if (i != v.size()-1 || dem < n) {cout <<1<<" "; dem++;}
    }
}
