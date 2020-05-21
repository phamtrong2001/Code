#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 15
#define maxc 1000000007
#define bit(x, i) ((x >> i) & 1)

using namespace std;

int n, k, X[N], Y[N], dp[1 << 13][13], C[1 << 13];
vector<int> allX, allY;
int main()
{
    freopen("BGAME.INP", "r", stdin);
    freopen("BGAME.OUT", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> X[i] >> Y[i];
    for (int x = 0; x < (1 << n); x++)
    {
        allX.clear(); allY.clear();
        for (int i = 1; i <= n; i++)
            if (bit(x, i-1))
            {
                allX.PB(X[i]);
                allY.PB(Y[i]);
            }
        sort(allX.begin(), allX.end());
        sort(allY.begin(), allY.end());
        int sz = allX.size()/2;
        for (int i = 0; i < allX.size(); i++)
            C[x] += abs(allX[sz] - allX[i]) + abs(allY[sz] - allY[i]);
    }
    memset(dp, 60, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++)
        for (int s = 1; s < (1 << n); s++)
            for (int m = s; m; m = (m-1) & s)
                dp[s][i] = min(dp[s][i], dp[s ^ m][i-1] + C[m]);
    cout <<*min_element(dp[(1 << n) - 1] + 1, dp[(1 << n)-1] + k + 1);
}
