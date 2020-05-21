#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 2005
#define maxc 1000000007

using namespace std;

int n, m, dd[N][N];
char ans[N];
string s, w;
int dp[N][N], f[N][N],pos[30], suf1[N][30], suf2[N][30];
int strRes[2*N];

void prepare()
{
    cin >> s >> w;
    n = s.size(); s = "#" + s; s.push_back((char)('z' + 1));
    m = w.size(); w = "#" + w; w.push_back((char)('z' + 1));
    for (int i = 1; i <= m+1; i++) f[n+1][i] = m-i+1;
    for (int i = 1; i <= n+1; i++) f[i][m+1] = n-i+1;
    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--)
        {
            if (s[i] == w[j]) dp[i][j] = dp[i+1][j+1] + 1;
            else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            f[i][j] = (n-i+m-j+2) - dp[i][j];
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

void traceSolve1()
{
    int len = dp[1][1];
    int u = 1, v = 1;
    int z = 0;
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
                break;
            }
        }
    }
    for (int i= 1; i<= z; i++) cout <<ans[i];
    cout <<endl;
}
void traceSolve2()
{
    queue<pair<pii, int> > p, q;
    int len = f[1][1];
    memset(strRes, 60, sizeof strRes);
    dd[1][1] = len+1;
    q.push(mp(mp(1, 1), 0));
    dd[1][1] = 1;
    for (int i = len; i >= 1; i--)
    {
        while (!q.empty())
        {
            int u = q.front().F.F;
            int v = q.front().F.S;
            int ch = q.front().S;
            q.pop();
            if (ch > strRes[i]) continue;
            if (f[u+1][v] == i-1)
            {
                if (dd[u+1][v] != len)
                {
                    dd[u+1][v] = len;
                    p.push(mp(mp(u+1, v), s[u]));
                    strRes[i-1] = min(strRes[i-1], (int)s[u]);
                }
            }
            if (f[u][v+1] == i-1)
            {
                if (dd[u][v+1] != len)
                {
                    dd[u][v+1] = len;
                    p.push(mp(mp(u, v+1), w[v]));
                    strRes[i-1] = min(strRes[i-1], (int)w[v]);
                }
            }
            if (s[u] == w[v] && f[u+1][v+1] == i-1)
            {
                if (dd[u+1][v+1] != len)
                {
                    dd[u+1][v+1] = len;
                    p.push(mp(mp(u+1, v+1), s[u]));
                    strRes[i-1] = min(strRes[i-1], (int)s[u]);
                }
            }
        }
        //cerr<<p.size()<<endl;
        swap(p, q);
        //if (q.size() == 1) cout <<i-1<<" "<<q.front().F.F<<" "<<q.front().F.S <<" "<<q.front().S<<endl;
        //while (!p.empty()) p.pop();
    }
    for (int i = len-1; i >= 0; i--) cout <<(char)strRes[i];

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
