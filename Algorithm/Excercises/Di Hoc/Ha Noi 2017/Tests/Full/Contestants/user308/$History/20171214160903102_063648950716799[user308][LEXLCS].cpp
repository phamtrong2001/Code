#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 2005
#define maxc 1000000007

using namespace std;

int n, m;
char ans[N];
string s, w;
int dp[N][N], pos[30], suf1[N][30], suf2[N][30];
vector<int> res1, res2;

void prepare()
{
    cin >> s >> w;
    n = s.size(); s = "#" + s;
    m = w.size(); w = "#" + w;
    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--)
        {
            if (s[i] == w[j]) dp[i][j] = dp[i+1][j+1] + 1;
            else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    for (int i = n; i >= 1; i--)
    {
        pos[s[i] - 'a'] = i;
        for (int j = 0; j <= 'z' - 'a'; j++)
            suf1[i][j] = pos[j];
    }
    memset(pos, 0, sizeof pos);
    for (int i = m; i >= 1; i--)
    {
        pos[w[i] - 'a'] = i;
        for (int j = 0; j <= 'z' - 'a'; j++)
            suf2[i][j] = pos[j];
    }
}

void OutChar(char ch)
{
    cout << (int)ch << ' ';
}

void traceSolve1()
{
    int len = dp[1][1];
    int u = 1, v = 1;
    int z = 0;
    res1.PB(0); res2.PB(0);
    while (len--)
    {
        for (int i = 'z' - 'a'; i >= 0; i--)
        {
            int x = suf1[u][i];
            int y = suf2[v][i];
            if (dp[x][y] == len+1)
            {
                ans[++z] = 'a' + i;
                u = x+1; v = y+1;
                res1.PB(x); res2.PB(y);
            }
        }
    }
    res1.PB(n+1); res2.PB(m+1);
    for (int i= 1; i<= z; i++) OutChar(ans[i]);//cout <<ans[i];
    cout <<endl;
}
void traceSolve2()
{
    for (int i = 0; i < res1.size()-1; i++)
    {
        int u = res1[i]+1, v = res2[i] + 1;
        while (u < res1[i+1] && v < res2[i+1])
        {
            if (s[u] > w[v]) {OutChar(w[v]); v++;}
            else {OutChar (s[u]); u++;}
        }
        while (u < res1[i+1]) {OutChar(s[u]); u++;}
        while (v < res2[i+1]) {OutChar (w[v]); v++;}
        if (i != res1.size()-1) OutChar(s[res1[i+1]]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("LEXLCS.INP", "r", stdin);
    freopen("LEXLCS.OUT", "w", stdout);
    prepare();
    traceSolve1();
    traceSolve2();
}
