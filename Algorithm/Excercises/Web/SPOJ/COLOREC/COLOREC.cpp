#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 405
#define MM 201
#define maxc 1000000007

using namespace std;

int n, a[N][N], ok[50], dem[50], tt;
long long res;

void reset(int x)
{
    if (ok[x] != tt)
    {
        ok[x] = tt;
        dem[x] = 0;
    }
}
int main()
{
    freopen("COLOREC.INP", "r", stdin);
    freopen("COLOREC.OUT", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int u, v, col;
        scanf("%d %d %d", &u, &v, &col);
        a[u+MM][v+MM] = col;
    }
    for (int i = 1; i < N; i++)
        for (int j = i+1; j < N; j++)
        {
            tt++;
            for (int k = 1; k < N; k++)
            {
                if (!a[i][k] || !a[j][k] || a[i][k] == a[j][k]) continue;
                int z = (1 << a[i][k]) | (1 << a[j][k]);
                int pre = 30^z;
                reset(pre);
                res += 1ll*dem[pre];
                reset(z);
                dem[z]++;
            }
        }
    printf("%lld", res);
}
