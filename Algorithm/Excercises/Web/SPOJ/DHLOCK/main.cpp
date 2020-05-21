#include <bits/stdc++.h>
#define N 305
#define maxc 1000000007
using namespace std;

int n, k, a[N], b[N], c[N], d[N], res = maxc;
void solve()
{
    for (int step = 0; step < n; step++)
    {
        for (int i = 1; i <= n; i++)
        {
            int pos = (i + step) % n;
            if (pos == 0) pos = n;
            d[pos] = a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            memcpy(c, d, sizeof d);
            int add;
            if (c[i] <= b[i])
                add = b[i] - c[i];
            else
                add = (b[i] + k - c[i] + 1);

            int cur = add;
            for (int j = 1; j <= n; j++)
            {
                c[j] += add;
                if (c[j] > k) c[j] -= (k + 1);
                if (c[j] <= b[j])
                    cur += (b[j] - c[j]);
                else
                    cur += (b[j] + k - c[j] + 1);
            }
            res = min(res, cur + step);
        }
    }
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    solve();
    cout <<res;
}
