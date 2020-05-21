#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 105
#define maxc 1000000007

using namespace std;

int n, m, p[N];
string s;
pii st, en;
char a[N][N];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool check()
{
    int u = st.F, v = st.S;
    for (int i = 0; i < s.size(); i++)
    {
        int x = s[i] - '0' + 1;
        u += dx[p[x]-1]; v += dy[p[x]-1];
        if (a[u][v] == '#') return 0;
        if (a[u][v] == 'E') return 1;
    }
    return a[u][v] == 'E';
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'S') st = mp(i, j);
            if (a[i][j] == 'E') en = mp(i, j);
        }
    cin >> s;
    for (int i = 1; i <= n; i++)
        a[i][0] = a[i][m+1] = '#';
    for (int i = 1; i <= m; i++)
        a[0][i] = a[n+1][i] = '#';
    for (int i = 1; i <= 4; i++) p[i] = i;

    int res = check();
    while (next_permutation(p+1, p+5))
        if (check())
        {
            //for (int i = 1; i <= 4; i++) cout <<p[i]<<" ";
            res++;
        }
    cout <<res;
}
