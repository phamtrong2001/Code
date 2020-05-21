#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1000005
#define maxc 1000000007

using namespace std;

int n, M, x[N], cnt[N];
ll gt[N], ans, dp[N][2];

ll Pow(int a, int b)
{
    if (b == 0) return 1;
    ll x = Pow(a, b/2);
    x = (x * x) % M;
    if (b % 2) return (x * a) % M;
    return x;
}
ll C (int n, int k)
{
    if (k > n || k < 0) return 0;
    int dem = cnt[n] - cnt[k] - cnt[n-k];
    if (dem) return 0;
    ll x = gt[n];
    ll y = (gt[k]*gt[n-k]) % M;
    return (x * Pow(y, M-2)) % M;
}
bool check()
{
    int cnt1 = 0;
    for (int i = 1; i <= n; i++)
        cnt1 += x[i];
    if (n % 2 == 0 && cnt1 == n/2) return 1;
    for (int i = 1; i < n; i++)
        if (x[i] == 1 && x[i+1] == 1) return 0;
    return 1;
}
void Try(int pos)
{
    if (pos > n)
    {
        ans += check();
        return;
    }
    x[pos] = 0;
    Try(pos+1);
    x[pos] = 1;
    Try(pos+1);
}
void inline add(ll &a, ll b) {a += b; if (a >= M) a -= M;}
int main()
{
    freopen("INP.TXT", "r", stdin);
    freopen("OUT.TXT", "w", stdout);
    int Tests;
    cin >>Tests;
    while (Tests--)
    {
        cin >> n >> M;
        if (n == 1)
        {
            cout <<2%M<<endl;
            continue;
        }
        gt[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            int x = i;
            cnt[i] = cnt[i-1];
            while (x % M == 0) {x /= M; cnt[i]++;}
            gt[i] = (gt[i-1]*x) % M;
        }
        ll res = 0;
        dp[1][0] = dp[1][1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % M;
            dp[i][1] = dp[i-1][0];
        }
        res = (dp[n][0] + dp[n][1]) % M;
        if (n % 2 == 0)
        {
            add(res, C(n, n/2));
            res = (res + M - 2) % M;
            res = (((res - n/2+1) % M) + M) % M;
        }
        cout <<res<<endl;
    }
}
