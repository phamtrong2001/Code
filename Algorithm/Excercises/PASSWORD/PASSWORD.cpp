#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 2005
#define maxc 1000000007

using namespace std;

int n, pos[N], sau[N][N], dsau[N][N], trc[N][N], dtrc[N][N], ans[N], res;
int f[N][N], g[N][N], pmin[N];
string s;

void prepare()
{
    for (int i = 0; i <= 'z' - 'a'; i++) pos[i] = n+1;
    for (int i = n; i >= 1; i--)
    {
        pos[s[i]-'a'] = i;
        for (int j = 0; j <= 'z' - 'a'; j++)
        {
            sau[i][j] = pos[j];
            dsau[i][j] = n+1;
            for (int k = 0; k <= 'z' - 'a'; k++)
                if (k != j) dsau[i][j] = min(dsau[i][j], pos[k]);
        }
    }
    for (int i = 0; i <= 'z' - 'a'; i++) pos[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        pos[s[i]-'a'] = i;
        for (int j = 0; j <= 'z' - 'a'; j++)
        {
            trc[i][j] = pos[j];
            dtrc[i][j] = 0;
            for (int k = 0; k <= 'z' - 'a'; k++)
                if (k != j) dtrc[i][j] = max(dtrc[i][j], pos[k]);
        }
    }
}
void truyvet1(int k, int l, int r, int id)
{
    if (id == 1)
    {
        for (int c = 0; c <= 'z' - 'a'; c++)
        {
            int p = sau[l][c];
            int q = trc[r][c];
            if (f[p][q] == k)
            {
                ans[res - k + 1] = p;
                truyvet1(k-1, p+1, q-1, 2);
                return;
            }
        }
    }
    for (int c = 0; c <= 'z' - 'a'; c++)
    {
        int p = sau[l][c];
        int q = dtrc[r][c];
        if (g[p][q] == k)
        {
            ans[res - k + 1] = p;
            truyvet1(k-1, p+1, q-1, 1);
            return;
        }
    }
}
void truyvet2()
{
    int curpos = n;
    for (int i = 1; i <= res; i++)
    {
        if (i % 2) pmin[i] = trc[curpos][s[ans[i]]-'a'];
        else pmin[i] = dtrc[curpos][s[ans[i]]-'a'];
        curpos = pmin[i] - 1;
    }
    curpos = ans[res] + 1;
    for (int i = res; i >= 1; i--)
    {
        if (i % 2) ans[2*res - i + 1] = sau[curpos][s[ans[i]] - 'a'];
        else
        {
            for (int c = 0; c <= 'z' - 'a'; c++)
                if (c != s[ans[i]] - 'a' && sau[curpos][c] <= pmin[i])
                {
                    ans[2*res - i + 1] = sau[curpos][c];
                    break;
                }
        }
        curpos = ans[2*res - i + 1] + 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("PASSWORD.INP", "r", stdin);
    freopen("PASSWORD.OUT", "w", stdout);
    cin >> n >> s; s = "#" + s;
    for (int len = 2; len <= n; len++)
        for (int i = 1; i <= n-len+1; i++)
        {
            int j = i + len - 1;
            f[i][j] = max(f[i+1][j], f[i][j-1]);
            g[i][j] = max(g[i+1][j], g[i][j-1]);
            if (s[i] == s[j]) f[i][j] = max(f[i][j], g[i+1][j-1] + 1);
            else g[i][j] = max(g[i][j], f[i+1][j-1] + 1);
        }
    res = f[1][n];
    prepare();

    truyvet1(res, 1, n, 1);
    truyvet2();
    for (int i = 1; i <= 2*res; i++) cout <<s[ans[i]];
}
