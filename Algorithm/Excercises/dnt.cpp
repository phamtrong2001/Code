#include <bits/stdc++.h>
#define maxc 1000000007
#define maxn 60004

using namespace std;

int n, a[maxn], res = 0, t[maxn*4];

void update(int x)
{
    while (x <= maxn)
    {
        t[x]++;
        x += (x & (-x));
    }
}

int get(int x)
{
    int cur = 0;
    while (x > 0)
    {
        cur += t[x];
        x -= (x & (-x));
    }
    return cur;
}

int main()
{
    freopen("dnt.inp", "r", stdin);
    freopen("dnt.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 1; i--)
        {
            res += get(a[i]-1);
            update(a[i]);
        }
    cout << res;
    return 0;
}
