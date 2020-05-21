#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define full l[h[1]][h[2]][h[3]][h[4]][h[5]][h[6]][h[7]]

using namespace std;

int n, a[10];
int l[9][9][9][9][9][9][9], dem;
double d[404][N];

void nhap()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < 404; ++i)
        for (int j = 0; j < N; ++j) d[i][j] = -1;
    for(int i = 1; i <= 8; ++i)
        for(int j = 1; j <= 8; ++j)
        for(int k = 1; k <= 8; ++k)
        for(int m = 1; m <= 8; ++m)
        for(int x = 1; x <= 8; ++x)
        for(int y = 1; y <= 8; ++y)
        for(int z = 1; z <= 8; ++z)
            l[i][j][k][m][x][y][z] = -1;
}

int doi(int a[])
{
    if(l[a[1]][a[2]][a[3]][a[4]][a[5]][a[6]][a[7]] > -1) return l[a[1]][a[2]][a[3]][a[4]][a[5]][a[6]][a[7]];
    return l[a[1]][a[2]][a[3]][a[4]][a[5]][a[6]][a[7]] = ++dem;
}

bool check(int a[])
{
    for(int i = 1; i < n; i++)
        if(a[i] != i) return 0;
    return 1;
}
double tinh(int p, int h[], int dep)
{
    int id = doi(a);

    if (d[dep][id] != -1.0) return d[dep][id];
    if (dep > 400)
        return d[dep][id] = 0;
    if(check(a))
        return  d[dep][id] = 0;
    if (!p)
    {
        double res = 100000000.0;
        for (int i = 1; i < n; ++i)
        {
            swap(h[i], h[i+1]);
            res = min(res, tinh(p^1, a, dep+1)+1);
            swap(h[i], h[i+1]);
        }
        return d[dep][id] = res;
    }
    else
    {
        double sum = 0;
        for (int i = 1; i < n; ++i)
        {
            swap(h[i], h[i+1]);
            sum += tinh(p^1, h, dep+1) + 1;
            swap(h[i], h[i+1]);
        }
        return d[dep][id] = sum/(n-1);
    }
}
int main()
{
    //freopen("INP.TXT", "r", stdin);
    freopen("P12N.INP", "r", stdin);
    //freopen("P12N.OUT", "w", stdout);
    nhap();
    {
        double res = tinh(0, a, 0);
        printf("%0.3f", res);
    }
}
