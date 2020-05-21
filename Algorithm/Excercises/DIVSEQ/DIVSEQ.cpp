#include <bits/stdc++.h>
#define PB push_back
#define N 300005
#define maxc 1000000007

using namespace std;

int n, a[N], dd[N], Z[N], res[N];
vector<int> all;
void nhap()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    dd[0] = dd[1] = 1;
    all.PB(1);
    for (int i = 2; i < N; i++)
        if (!dd[i])
        {
            all.PB(i);
            for (int j = i*2; j < N; j+=i) dd[j] = 1;
        }
}
void solve()
{
    int L = 0, R = 0;
    Z[0] = n;
    for (int i = 1; i < n; i++)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n && a[R] == a[R - L]) R++;
            Z[i] = R - L; R--;
        }
        else
        {
            int k = i - L;
            if (Z[k] < R - i + 1) Z[i] = Z[k];
            else
            {
                L = i;
                while (R < n && a[R] == a[R - L]) R++;
                Z[i] = R - L; R--;
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (Z[i] == n-i) Z[i] = maxc;

    for (int i = 1; i <= n; i++) res[i] = Z[0];
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= sqrt(i); j++)
        {
            if (i % j) continue;
            res[j] = min(res[j], Z[i]);
            res[i/j] = min(res[i/j], Z[i]);
        }
    res[n] = n;
    for (int i = 1; i <= n; i++)
        if (res[i] >= i)
        {
            cout <<i;
            exit(0);
        }
}
int main()
{
    freopen("DIVSEQ.INP", "r", stdin);
    freopen("DIVSEQ.OUT", "w", stdout);
    nhap();
    solve();
}
