#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1005
#define maxc 1000000007

using namespace std;

int n, m, ans[N][N];
char c[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("QUEEN.INP", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> c[i][j];
    for (int i = 1; i <= n; i++)
    {
        vector<pii> v;
        int st = 1;
        for (int j = 1; j <= m+1; j++)
            if (c[i][j] != '.')
            {
                if (st <= j-1) v.PB(mp(st, j-st));
                st = j+1;
            }
        for (auto z : v)
            for (int j = z.F; j <= z.F + z.S - 1; j++)
                ans[i][j] += z.S - 1;
    }
    for (int i = 1; i <= m; i++)
    {
        vector<pii> v;
        int st = 1;
        for (int j = 1; j <= n+1; j++)
            if (c[j][i] != '.')
            {
                if (st <= j-1) v.PB(mp(st, j-st));
                st = j+1;
            }
        for (auto z : v)
            for (int j = z.F; j <= z.F + z.S - 1; j++)
                ans[j][i] += z.S - 1;
    }
    for (int s = 2; s <= n+m; s++)
    {
        vector<pii> v;
        int st = 1;
        for (int i = 1; i <= n+1; i++)
        {
            int j = s - i;
            if (j > m) {st = i+1; continue;}
            if (c[i][j] != '.' || j == 0)
            {
                if (st <= i-1) v.PB(mp(st, i-st));
                st = i+1;
            }
            if (j == 0) break;
        }
        for (auto z : v)
            for (int i = z.F; i <= z.F + z.S - 1; i++)
                ans[i][s-i] += z.S - 1;
    }
    for (int s = 1-m; s <= n-1; s++)
    {
        vector<pii> v;
        int st = 1;
        for (int i = 1; i <= n+1; i++)
        {
            int j = i - s;
            if (j < 1) {st = i+1; continue;}
            if (c[i][j] != '.' || j == m+1)
            {
                if (st <= i-1) v.PB(mp(st, i-st));
                st = i+1;
            }
            if (j == m+1) break;
        }
        for (auto z : v)
            for (int i = z.F; i <= z.F + z.S - 1; i++)
                ans[i][i-s] += z.S - 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout <<ans[i][j] + (c[i][j] == '.')<<" ";
        cout <<endl;
    }
}
