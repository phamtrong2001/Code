#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, len, cnt[N][4][2];
pii dp[N];
string s;
string w = " ab?";

int sum(int u, int v, int ch, int parity)
{
    return cnt[v][ch][parity] - cnt[u-1][ch][parity];
}
bool check(int st)
{
    int par = 0;
    if (st % 2) par = 1;
    if (sum(st, st+len-1, 1, par) + sum(st, st+len-1, 3, par) < (len - 1)/2+1) return 0;
    if (sum(st, st+len-1, 2, 1-par) + sum(st, st+len-1, 3, 1-par) < len/2) return 0;
    return 1;
}

int cost(int st)
{
    return sum(st, st+len-1, 3, 0) + sum(st, st+len-1, 3, 1);
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    cin >> n; cin >> s;
    s = "#" + s;
    cin >> len;
    for (int i = 1; i <= n; i++)
        for (int ch = 1; ch <= 3; ch++)
            for (int parity = 0; parity <= 1; parity++)
            {
                cnt[i][ch][parity] += cnt[i-1][ch][parity];
                if (w[ch] == s[i] && i % 2 == parity) cnt[i][ch][parity]++;
            }
    //dp[0] = mp(0, 0);
    for (int i = len; i <= n; i++)
    {
        int st = i - len + 1;
        dp[i] = dp[i-1];
        if (!check(st)) continue;
        if (dp[i].F < dp[st-1].F + 1)
            dp[i] = mp(dp[st-1].F + 1, dp[st-1].S + cost(st));
        else if (dp[i].F == dp[st-1].F + 1 && dp[st-1].S + cost(st) < dp[i].S)
            dp[i].S = dp[st-1].S + cost(st);
    }
    cout <<dp[n].S;
}
