#include <bits/stdc++.h>
#define N 50005
using namespace std;

int res, t, n, a[N];
void update(int x)
{
    if (x <= res) return;
    int g1 = a[1];
    int g2 = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] % x == 0) g1 = __gcd(g1, a[i]);
        else
        {
            if (g2 == 0) g2 = a[i];
            else g2 = __gcd(g2, a[i]);
        }
        if (g2 > 0 && min(g1, g2) <= res) return;
    }
    if (g2 == 0) g2 = g1;
    res = max(res, min(g1, g2));
    return;
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a+1, a+n+1);
        res = 1;
        update(a[1]);
        for (int i = sqrt(a[1]); i >= 2; i--)
        {
            if (a[1] % i) continue;
            update(i);
            update(a[1]/i);
        }
        printf("%d\n", res);
    }
}
