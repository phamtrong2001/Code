#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1000005
#define BASE 97
#define maxc

using namespace std;

int n, k, dp[N], f[N];
ll b[N], h[N], res;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    cin >> k >> s;
    n = s.size(); s = "#" + s;
    for (int i = n; i >= n-k+1; i--)
        dp[i] = n - i + 1;
    for (int i = n-k; i >= 1; i--)
    {
        if (s[i] == s[i+k]) f[i] = f[i+1] + 1;
        if (f[i] >= k) dp[i] = k + dp[i+k];
        else dp[i] = k + f[i];
        res += dp[i] - k;
    }
    cout <<res;
}
