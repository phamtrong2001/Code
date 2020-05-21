#include <bits/stdc++.h>
#define N 104
#define ll long long
using namespace std;

int n;
ll a[N][N], line[N];
int main()
{
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%lld", &a[i][j]);
            line[i] += a[i][j];
            sum += a[i][j];
        }
    sum /= (n-1);
    for (int i = 1; i <= n; i++)
        a[i][i] = sum - line[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) printf("%lld ", a[i][j]);
        printf("\n");
    }
}
