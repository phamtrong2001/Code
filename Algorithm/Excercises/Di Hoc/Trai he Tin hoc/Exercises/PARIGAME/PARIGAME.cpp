#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 505
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, s[N][N];
bool l[2][N][N][2][2], dd[2][N][N][2][2];

void nhap()
{
    memset(s, 0, sizeof s);
    memset(dd, 0, sizeof dd);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int x; scanf("%d", &x);
            s[i][j] = ((s[i-1][j] + s[i][j-1] - s[i-1][j-1] + x) % 2 + 2) % 2;
        }
}
int get(int u, int v, int x, int y)
{
    return ((s[x][y] - s[u-1][y] - s[x][v-1] + s[u-1][v-1]) % 2 + 2) % 2;
}

bool play(int p, int r, int c, int s, int t)
{
    if (dd[p][r][c][s][t]) return l[p][r][c][s][t];
    dd[p][r][c][s][t] = 1;
    if (!r || !c) return l[p][r][c][s][t] = 0;

    if (s == 0)
    {
        if ((t + get(r, 1, r, c)) % 2 == 0 && play(1-p, r-1, c, 0, 0) == 0 && play(1-p, r-1, c, 1, 0) == 0)
            return l[p][r][c][s][t] = 1;
        if (play(p, r-1, c, s, (t + get(r, 1, r, c)) % 2) == 1)
            return l[p][r][c][s][t] = 1;
    }
    else
    {
        if ((t + get(1, c, r, c)) % 2 == 0 && play(1-p, r, c-1, 0, 0) == 0 && play(1-p, r, c-1, 1, 0) == 0)
            return l[p][r][c][s][t] = 1;
        if (play(p, r, c-1, s, (t + get(1, c, r, c)) % 2) == 1)
            return l[p][r][c][s][t] = 1;
    }
    return l[p][r][c][s][t] = 0;
}


int main()
{
    //IOS
    freopen("PARIGAME.INP", "r", stdin);
    freopen("PARIGAME.OUT", "w", stdout);
    int t; scanf("%d", &t);
    while (t--)
    {
        nhap();

        if (play(0, n, m, 0, 0) || play(0, n, m, 1, 0)) printf("TRUE\n");
        else printf("FALSE\n");
    }

}
