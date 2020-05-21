#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define mid (l + r)/2
#define maxc 1000000007

using namespace std;

struct IntervalTree
{
    int t[N << 2];
    void update(int l, int r, int id, int x, int y, int val)
    {
        if (x > y) return;
        if (l > y || r < x) return;
        if (l >= x && r <= y)
        {
            t[id] = max(t[id], val);
            return;
        }
        update(l, mid, id*2, x, y, val);
        update(mid+1, r, id*2+1, x, y, val);
    }
    int get(int l, int r, int id, int x)
    {
        if (l > x || r < x) return 0;
        if (l == r) return t[id];
        if (x <= mid) return max(t[id], get(l, mid, id*2, x));
        return max(t[id], get(mid+1, r, id*2+1, x));
    }
}t, tt;

int n, x[N*2], cur;
pair<pii, int> a[N];
int main()
{
    freopen("HORIZON.INP", "r", stdin);
    freopen("HORIZON.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].F.F >> a[i].F.S >> a[i].S;
        x[++cur] = a[i].F.F;
        x[++cur] = a[i].F.S;
    }
    sort(x+1, x+cur+1);
    cur = unique(x+1, x+cur+1) - x - 1;
    for (int i = 1; i <= n; i++)
    {
        a[i].F.F = lower_bound(x+1, x+cur+1, a[i].F.F) - x;
        a[i].F.S = lower_bound(x+1, x+cur+1, a[i].F.S) - x;
    }
    for (int i = 1; i <= n; i++) tt.update(1, cur-1, 1, a[i].F.F, a[i].F.S-1, a[i].S);
    long long res = 0;
    for (int i = 1; i < cur; i++)
    {
        int y = tt.get(1, cur-1, 1, i);
        res += 1ll*(x[i+1] - x[i])*y;
    }
    cout <<res;
}
