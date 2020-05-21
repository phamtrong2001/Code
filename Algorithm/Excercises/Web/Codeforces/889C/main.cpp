#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1000005
#define mod 1000000007

using namespace std;

ll n, k, gt[N], dp[N], sum[N];
ll Pow(ll a, ll b)
{
    if (b == 0) return 1;
    ll x = Pow(a, b/2);
    x = (x * x) % mod;
    if (b % 2) return (x * a) % mod;
    return x;
}
int main()
{
    cin >> n >> k;
    if (k >= n)
    {
        cout <<0;
        return 0;
    }
    gt[0] = 1;
    for (int i = 1; i < N; i++) gt[i] = (gt[i-1]*i) % mod;
    for (int i = 1; i <= k+1; i++) dp[i] = 0;
    for (int i = k+2; i <= n; i++)
    {
        dp[i] = ((gt[i-2]*(i-k-1)) % mod + (gt[i-2]*(sum[i-1] - sum[i-k-1])) % mod + mod) % mod;
        sum[i] = (sum[i-1] + (dp[i]*Pow(gt[i-1], mod-2)) % mod) % mod;
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res = (res + (((dp[i]*gt[n-1]) % mod) * Pow(gt[i-1], mod-2)) % mod) % mod;
    cout <<res;
}
