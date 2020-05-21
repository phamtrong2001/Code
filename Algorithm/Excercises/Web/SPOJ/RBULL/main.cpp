#include <bits/stdc++.h>
#define N 2005
using namespace std;

int n, m, n_new, m_new, res, u_res, v_res, r_res;
int a[N][N], b[N<<1][N<<1], s[N<<1][N<<1], F1[N][N], F2[N][N], F3[N][N], F4[N][N];

int calc(int u, int v, int r)
{
    int lef = v - r + 1;
    int rig = v + r - 1;
    int xx = rig + u - 1;
    int yy = n - u + rig;
    int XX = lef + u - 1;
    int YY = n - u + lef;
    return s[xx][yy] - s[XX-1][yy] - s[xx][YY-1] + s[XX-1][YY-1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char c; int x = 0; cin >> c;
            if (c == '*') x = 1;
            a[i][j] = x;
            b[i + j - 1][n - i + j] = x;
        }
    for (int i = 1; i <= m + n - 1; i++)
        for (int j = 1; j <= m + n - 1; j++)
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + b[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] && (a[i-1][j] || a[i][j-1])) F1[i][j] = 1;
            else F1[i][j] = min(F1[i-1][j], F1[i][j-1]) + 1;

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 1; j--)
            if (a[i][j] && (a[i][j+1] || a[i-1][j])) F2[i][j] = 1;
            else F2[i][j] = min(F2[i-1][j], F2[i][j+1]) + 1;

    for (int i = n; i >= 1; i--)
        for (int j = 1; j <= m; j++)
            if (a[i][j] && (a[i][j-1] || a[i+1][j])) F3[i][j] = 1;
            else F3[i][j] = min(F3[i+1][j], F3[i][j-1]) + 1;

    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--)
            if (a[i][j] && (a[i][j+1] || a[i+1][j])) F4[i][j] = 1;
            else F4[i][j] = min(F4[i+1][j], F4[i][j+1]) + 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int r = min(F1[i][j], min(F2[i][j], min(F3[i][j], F4[i][j])));
            int sum = calc(i, j, r);
            if (sum > res)
            {
                res = sum;
                u_res = i;
                v_res = j;
                r_res = r-1;
            }
        }
    cout <<res<<" "<<u_res<<" "<<v_res<<" "<<r_res;
}
