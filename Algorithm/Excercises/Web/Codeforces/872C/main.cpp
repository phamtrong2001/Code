#include <bits/stdc++.h>
#define N 1004
#define maxc 1000000007
using namespace std;

int d[8] = {4, 6, 8, 9, 10, 12, 14, 15};
int q, dp[N];
int main()
{
    //freopen("INP.TXT", "r", stdin);
    for (int i = 1; i <= 1000; i++)
    {
        dp[i] = -maxc;
        for (int j = 0; j < 8; j++)
            if (i >= d[j]) dp[i] = max(dp[i], dp[i-d[j]] + 1);
    }
    cin >> q;
    while (q--)
    {
        int x; cin >> x; int res = -maxc;
        for (int i = 0; i <= min(1000, x); i++)
            if ((x - i) % 4 == 0)
                res = max(res, (x - i)/4 + dp[i]);
        if (res <= 0) res = -1;
        cout <<res<<'\n';
    }
}
