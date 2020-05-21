#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, dem[N], dp[2601][2601];
pii trc[2601][2601];
string s;
char ans[N];


int main()
{
    freopen("INP.TXT", "r", stdin);
    cin >> s;
    n = s.size(); s = "#" + s + "#";
    for (int i = 1; i <= n; i++) dem[s[i]-'a']++;
    for (int i = 0; i <= 'z' - 'a'; i++)
        if (dem[i] >= 100)
        {
            for (int j = 1; j <= 100; j++)
                cout <<(char)('a' + i);
            return 0;
        }
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 1;
        trc[i][i] = mp(i+1, i-1);
    }
    for (int i = 2; i <= n+2; i++)
        for (int u = 0; u <= n-i+2; u++)
        {
            int v = u + i - 1;
            if (s[u] == s[v])
            {
                dp[u][v] = dp[u+1][v-1] + 2;
                trc[u][v] = mp(u+1, v-1);
            }
            else if (dp[u+1][v] > dp[u][v-1])
            {
                dp[u][v] = dp[u+1][v];
                trc[u][v] = mp(u+1, v);
            }
            else
            {
                dp[u][v] = dp[u][v-1];
                trc[u][v] = mp(u, v-1);
            }
        }
    int u = 0, v = n+1;
    int res = dp[u][v];
    int cur = 0;
    while (1)
    {
        if (u > v) break;
        if (s[u] == s[v])
        {
            ans[++cur] = s[u];
            ans[res - cur + 1] = s[u];
        }
        int u1 = trc[u][v].F;
        v = trc[u][v].S;
        u = u1;
    }
    if (res >= 102)
    {
        for (int i = 2; i <= 51; i++)
            cout <<ans[i];
        for (int i = 51; i >= 2; i--)
            cout <<ans[i];
        return 0;
    }
    for (int i = 2; i < res; i++) cout <<ans[i];
}
