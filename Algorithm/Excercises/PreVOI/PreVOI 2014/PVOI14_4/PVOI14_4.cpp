#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define mid (r + l)/2
#define N 100005
#define maxc 1000000007

using namespace std;

int n, a[N], x[N], dd1[N], dd2[N], dd3[N], up1[N], up2[N], up3[N], up4[N];

struct IntervalTree
{
    int t[N << 2];
    void update(int l, int r, int id, int x, int val)
    {
        if (l > x || r < x) return;
        if (l == r)
        {
            t[id] = max(t[id], val);
            return;
        }
        update(l, mid, id*2, x, val);
        update(mid+1, r, id*2+1, x, val);
        t[id] = max(t[id*2], t[id*2+1]);
    }
    int get(int l, int r, int id, int x, int y)
    {
        if (l > y || r < x) return 0;
        if (l >= x && r <= y) return t[id];
        int a = get(l, mid, id*2, x, y);
        int b = get(mid+1, r, id*2+1, x, y);
        return max(a, b);
    }
}t1, t2, t3, t4;

int main()
{
    freopen("PVOI14_4.INP", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], x[i] = a[i];
    sort(x+1, x+n+1);
    int cur = unique(x+1, x+n+1) - x - 1;
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(x+1, x+cur+1, a[i]) - x;
    for (int i = 1; i <= n; i++)
    {
        up1[i] = t1.get(1, cur, 1, 1, a[i] - 1) + 1;
        t1.update(1, cur, 1, a[i], up1[i]);
        if (up1[i] <= 1) dd1[i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        up2[i] = t2.get(1, cur, 1, a[i]+1, cur) + 1;
        if (!dd1[i]) t2.update(1, cur, 1, a[i], up1[i]);
        if (up2[i] <= 2) dd2[i] = 1;
        else t2.update(1, cur, 1, a[i], up2[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        up3[i] = t3.get(1, cur, 1, 1, a[i] - 1) + 1;
        if (!dd2[i]) t3.update(1, cur, 1, a[i], up2[i]);
        if (up3[i] <= 3) dd3[i] = 1;
        else t3.update(1, cur, 1, a[i], up3[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        up4[i] = t4.get(1, cur, 1, a[i]+1, cur) + 1;
        if (!dd3[i]) t4.update(1, cur, 1, a[i], up3[i]);
        if (up4[i] > 4) t4.update(1, cur, 1, a[i], up4[i]);
    }
    cout <<*max_element(up4+1, up4+n+1);
}
