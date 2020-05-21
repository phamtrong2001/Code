/******** Kho kinh nguoi ********/
#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define maxc 1000000007
#define maxn 100005
#define task "subseq"

using namespace std;

int n, a[maxn], b[maxn], f[maxn];

struct data
{
    int F, S;
} t[maxn];

void update(int x, int val, int sl)
{
    while (x <= maxn)
    {
        if (val > t[x].F) t[x].F = val, t[x].S = sl;
            else if (val == t[x].F) t[x].S = (sl + t[x].S) % maxc;
        x += x & (-x);
    }
}

data get(int x)
{
    data cur = {0, 0};
    while (x > 0)
    {
        if (cur.F < t[x].F) cur = t[x];
            else if (cur.F == t[x].F) cur.S = (cur.S + t[x].S) % maxc;
        x -= x & (-x);
    }
    return cur;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
    sort(b+1, b+n+1);
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(b+1, b+n+1, a[i]) - b;
    a[n+1] = maxn;
    data cur;
    for (int i = 1; i <= n+1; i++)
        {
            cur = get(a[i]-1);
            f[i] = cur.F + 1;
            if (cur.S == 0) cur.S++;
            update(a[i], f[i], cur.S);
        }
    cout << cur.S;
    return 0;
}
