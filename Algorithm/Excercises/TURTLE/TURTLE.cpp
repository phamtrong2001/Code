#include <bits/stdc++.h>
#define N 155
#define pii pair<int, int>
#define F first
#define S second

using namespace std;

int n, m, q;
bitset<150> d[N][N][2*N], a[2*N];
int sl[4];
pii b[4][N*N];

void setup()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char c; cin >> c;
            if (c == '.') a[i+j].set(i-1);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (a[i+j][i-1]) d[i][j][i+j].set(i-1);
            for (int k = i+j+1; k <= n+m; k++)
                d[i][j][k] = (d[i][j][k-1] | (d[i][j][k-1] << 1)) & a[k];
            for (int k = i+j-1; k >= 2; k--)
                d[i][j][k] = (d[i][j][k+1] | (d[i][j][k+1] >> 1)) & a[k];
        }
}

bool check(pii A, pii B, pii C)
{
    int x1 = A.F + A.S;
    int x2 = B.F + B.S;
    int x3 = C.F + C.S;
    if (x1 > x3) return 0;
    if (x1 > x2 || x2 > x3)
        return d[A.F][A.S][x3][C.F-1];

    bitset<150> temp = d[A.F][A.S][x2] & d[C.F][C.S][x2];
    temp.set(B.F-1, 0);
    return temp.any();
}
void solve()
{
    cin >> q;
    while (q--)
    {
        int res = 0;
        for (int i = 1; i <= 3; i++)
        {
            cin >> sl[i];
            for (int j = 1; j <= sl[i]; j++)
                cin >> b[i][j].F >> b[i][j].S;
        }
        for (int i = 1; i <= sl[1]; i++)
            for (int j = 1; j <= sl[2]; j++)
                for (int k = 1; k <= sl[3]; k++)
                    res += check(b[1][i], b[2][j], b[3][k]);
        cout <<res<<'\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("TURTLE.INP", "r", stdin);
    freopen("TURTLE.OUT", "w", stdout);
    setup();
    solve();
}
