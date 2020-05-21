#include <bits/stdc++.h>
#define maxn 2000

using namespace std;

int n, l, r, a[maxn], d1[maxn][maxn], d2[maxn][maxn], d3[maxn][maxn];

int main()
{
    freopen("bit.inp","r",stdin);
    //freopen("bit.out","w",stdout);
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
            d1[a[i]&a[j]][j]++;
    for (int i = 0; i <= 1024; i++)
        for (int j = 1; j <= n; j++)
            d1[i][j] += d1[i][j-1];
    for (int i = 0; i <= 1024; i++)
        for (int j = 1; j <= n; j++)
            d2[i|a[j]][j] += d1[i][j-1];
    for (int i = 0; i <= 1024; i++)
        for (int j = 1; j <= n; j++)
            d2[i][j] += d2[i][j-1];
    for (int i = 0; i <= 1024; i++)
        for (int j = 1; j <= n; j++)
            if (1ll*(i^a[j]) <= 1024 && 1ll*(i^a[j]) >= 0)
                d3[i^a[j]][j] += d2[i][j-1];
    for (int i = 0; i <= 1024; i++)
        for (int j = 1; j <= n; j++)
            d3[i][j] += d3[i][j-1];
    long long res = 0;
    for (int i = l; i <= r; i++)
        res += d3[i][n];
    cout << res;
    return 0;
}
