#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 55
#define maxc 1000000007

using namespace std;

int X, Y, Z, T, C, u[5], v[5], s[N][N][N][N];

bool bit(int x, int i) {return (x >> i) & 1;}
int get(int u1, int u2, int u3, int u4, int len)
{
    u[1] = u1; u[2] = u2; u[3] = u3; u[4] = u4;

    int res = 0;
    for (int x = 0; x < (1 << 4); x++)
    {
        for (int i = 1; i <= 4; i++) v[i] = u[i] + len - 1;
        for (int i = 1; i <= 4; i++)
            if (bit(x, i-1)) v[i] = u[i] - 1;
        if (__builtin_popcount(x) % 2) res -= s[v[1]][v[2]][v[3]][v[4]];
        else res += s[v[1]][v[2]][v[3]][v[4]];
    }
    return res;
}
int main()
{
    freopen("VOS4DCUB.INP", "r", stdin);
    //freopen("VOS4DCUB.OUT", "w", stdout);
    cin >> X >> Y >> Z >> T >> C;
    for (int i = 1; i <= X; i++)
        for (int j = 1; j <= Y; j++)
            for (int k = 1; k <= Z; k++)
                for (int h = 1; h <= T; h++)
                {
                    char c; c = getchar();
                    while (c < '0' || c > '1')
                        c = getchar();
                    int XX = c - '0';
                    for (int x = 1; x < (1 << 4); x++)
                    {
                        u[1] = i; u[2] = j; u[3] = k; u[4] = h;
                        for (int ii = 1; ii <= 4; ii++)
                            if (bit(x, ii-1)) u[ii]--;
                        if (__builtin_popcount(x) % 2) XX += s[u[1]][u[2]][u[3]][u[4]];
                        else XX -= s[u[1]][u[2]][u[3]][u[4]];
                    }
                    s[i][j][k][h] = XX;
                }
    int res = 0;
    for (int i = 1; i <= X; i++)
        for (int j = 1; j <= Y; j++)
            for (int k = 1; k <= Z; k++)
                for (int h = 1; h <= T; h++)
                {
                    int l = 0, r = min(X - i, min(Y - j, min(Z - k, T - h))) + 1;
                    int sideMax = r;
                    while (r - l > 1)
                    {
                        int mid = (r + l)/2;
                        if (get(i, j, k, h, mid) >= C) r = mid;
                        else l = mid;
                    }
                    if (get(i, j, k, h, r) >= C) res += sideMax - r + 1;
                }
    //cout <<ans<<endl;
    cout <<res;
}
