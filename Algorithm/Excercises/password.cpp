/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define pii pair<int, int>
#define PB push_back
#define MP make_pair
#define ll long long
#define F first
#define S second
#define task "password"
#define maxc 1000000007
#define maxn 2003

using namespace std;

int n, f[maxn][maxn], g[maxn][maxn], vt[maxn], nex[maxn][maxn], dnex[maxn][maxn], res[maxn], pre[maxn][maxn], dpre[maxn][maxn];

string s;

void chuanbi()
{
    for (int i = 'a'; i <= 'z'; i++) vt[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        vt[s[i]] = i;
        for (int j = 'a'; j <= 'z'; j++)
        {
            pre[i][j] = vt[j];
            dpre[i][j] = 0;
            for (int k = 'a'; k <= 'z'; k++)
                if (j != k) dpre[i][j] = max(dpre[i][j], vt[k]);
        }
    }
    for (int i = 'a'; i <= 'z'; i++) vt[i] = n+1;
    for (int i = n; i >= 1; i--)
    {
        vt[s[i]] = i;
        for (int j = 'a'; j <= 'z'; j++)
        {
            nex[i][j] = vt[j];
            dnex[i][j] = n+1;
            for (int k = 'a'; k <= 'z'; k++)
                if (j != k) dnex[i][j] = min(dnex[i][j], vt[k]);
        }
    }
}

void tim1(int k, int l, int r, int id)
{
    if (id == 1)
        for (int i = 'a'; i <= 'z'; i++)
        {
            int p = nex[l][i];
            int q = pre[r][i];
            if (f[p][q] == k)
            {
                res[f[1][n]-k+1] = p;
                tim1(k-1, p+1, q-1, id^1);
                return;
            }
        }
    for (int i = 'a'; i <= 'z'; i++)
    {
        int p = nex[l][i];
        int q = dpre[r][i];
        if (g[p][q] == k)
        {
            res[f[1][n]-k+1] = p;
            tim1(k-1, p+1, q-1, id^1);
            return;
        }
    }
}

void tim2()
{
    int cur = f[1][n];
    int pos = n;
    for (int i = 1; i <= cur; i++)
    {
        if (i % 2) vt[i] = pre[pos][s[res[i]]];
            else vt[i] = dpre[pos][s[res[i]]];
        pos = vt[i] - 1;
    }
    pos = res[cur] + 1;
    for (int i = cur; i >= 1; i--)
    {
        if (i % 2) res[2*cur-i+1] = nex[pos][s[res[i]]];
            else
            {
                for (int j = 'a'; j <= 'z'; j++)
                    if (j != s[res[i]] && nex[pos][j] <= vt[i])
                    {
                        res[2*cur-i+1] = nex[pos][j];
                        break;
                    }
            }
        pos = res[2*cur-i+1] + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> s;
    s = " " + s;
    for (int l = 2; l <= n; l++)
        for (int i = 1; i <= n-l+1; i++)
        {
            int j = i + l - 1;
            f[i][j] = max(f[i+1][j], f[i][j-1]);
            g[i][j] = max(g[i+1][j], g[i][j-1]);
            if (s[i] == s[j]) f[i][j] = max(f[i][j], g[i+1][j-1] + 1);
                else g[i][j] = max(g[i][j], f[i+1][j-1] + 1);
        }
    chuanbi();
    tim1(f[1][n], 1, n, 1);
    tim2();
    for (int i = 1; i <= 2*f[1][n]; i++)
        cout << s[res[i]];
    return 0;
}
