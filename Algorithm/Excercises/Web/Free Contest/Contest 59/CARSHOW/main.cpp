#include <bits/stdc++.h>
#define N 100005

using namespace std;

multiset<int> myset;

int n, t, x[N], v[N];
long long val[N], b[N];
void nhap()
{
    scanf("%d %d", &n, &t);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &x[i], &v[i]);
        val[i] = 1ll*x[i] + 1ll*v[i] * t;
        b[i] = val[i];
    }
    sort(b+1, b+n+1);
    int m = unique(b+1, b+n+1) - b - 1;
    for (int i = 1; i <= n; i++) val[i] = lower_bound(b+1, b+m+1, val[i]) - b;

    int res = 1;
    myset.insert(val[1]);
    for (int i = 2; i <= n; i++)
    {
        auto it = myset.lower_bound(val[i]);
        if (it == myset.begin())
        {
            myset.insert(val[i]);
            res++;
        }
        else
        {
            it--;
            myset.erase(it);
            myset.insert(val[i]);
        }
    }
    cout <<res;
}
int main()
{
    //freopen("INP.TXT", "r", stdin);
    nhap();
}
