#include <bits/stdc++.h>
#define N 1005
using namespace std;

int n, k, a[N][N], c[N][N], dp[N][N], l[N];
string s[N];
map<string, int> ma;

int calc1(int u, int v)
{
    string s1 = s[u];
    string s2 = s[v];
    int maxlen = min(l[u], l[v]);
    for (int i = maxlen-1; i >= 0; i--)
    {
        int pos = l[u] - i;
        string p = s1.substr(pos, i);
        string q = s2.substr(0, i);
        if (p == q) return i;
    }
}
int calc2(int u, int v)
{
    string s1 = s[u];
    for (int i = c[u][v]+1; i <= l[v]; i++)
        s1.push_back(s[v][i-1]);
    int ans = 0;
    for (int i = l[u]; i < l[u] + l[v] - c[u][v]; i++)
        for (int len = 1; len <= 20; len++)
        {
            if (i - len + 1 < 0) continue;
            int st = i - len + 1;
            string ww = s1.substr(st, len);
            ans += ma[ww];
        }
    return ans;
}
void nhap()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i], l[i] = s[i].size();
        ma[s[i]]++;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            c[i][j] = calc1(i, j);
            a[i][j] = calc2(i, j);
        }
}
void dpSolve()
{
    int res = 0;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++)
        {
            if (l[j] > i) continue;
            dp[i][j] = 1;
            for (int h = 1; h <= n; h++)
            {
                int pos = i - l[j] + c[h][j];
                if (l[h] > pos) continue;
                dp[i][j] = max(dp[i][j], dp[pos][h] + a[h][j]);
            }
            res = max(res, dp[i][j]);
        }
    cout << res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("SCORE.INP", "r", stdin);
    freopen("SCORE.OUT", "w", stdout);
    nhap();
    dpSolve();
}
