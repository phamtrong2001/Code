#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 105
#define maxc 1000000007

using namespace std;

int n, a[N];
long long dp[50005];

int main()
{
    freopen("TEAMSEL.INP", "r", stdin);
    int testCase; cin >> testCase;
    while (testCase--)
    {
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
        memset(dp, 0, sizeof dp);

        dp[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = sum; j >= 0; j--)
                if (j >= a[i])
                    dp[j] |= (dp[j-a[i]] << 1);

        int res = maxc;
        for (int i = 0; i <= sum; i++)
            if ((dp[i] >> (n/2)) & 1) res = min(res, abs(i*2 - sum));
        cout <<sum - (res + sum)/2<<" "<<(res + sum)/2<<'\n'<<'\n';
    }
}
