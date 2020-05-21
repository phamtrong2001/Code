#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define ll long long
#define mid (r + l)/2
#define maxc 1000000007

using namespace std;

int n, m;

struct IntervalTree
{
    ll t[4][N << 2];

    void refine(int id)
    {
        int l = id*2, r = id*2+1;
        t[0][id] = max(t[0][l] + t[2][r], max(t[1][l] + t[2][r], t[1][l] + t[0][r]));
        t[1][id] = max(t[0][l] + t[3][r], max(t[1][l] + t[1][r], t[1][l] + t[3][r]));
        t[2][id] = max(t[2][l] + t[2][r], max(t[3][l] + t[0][r], t[3][l] + t[2][r]));
        t[3][id] = max(t[3][l] + t[3][r], max(t[3][l] + t[1][r], t[2][l] + t[3][r]));
    }
    void add(int l, int r, int id, int x, int val)
    {
        if (l > x || r < x) return;
        if (l == r)
        {
            t[0][id] = val;
            return;
        }
        if (x <= mid) add(l, mid, id*2, x, val);
        add(mid+1, r, id*2+1, x, val);
        refine(id);
    }
    ll get()
    {
        return max(t[0][1], max(t[1][1], max(t[2][1], t[3][1])));
    }
}t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("CANDY.INP", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        t.add(1, n, 1, i, x);
    }
    ll res = 0;
    for (int i = 1; i <= m; i++)
    {
        int x, val; cin >> x >> val;
        t.add(1, n, 1, x, val);
        res += t.get();
    }
    cout <<res;
}
