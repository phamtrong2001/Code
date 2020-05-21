#include <bits/stdc++.h>
#define ll long long
#define mid ((l + r) >> 1)

using namespace std;

struct line
{
    ll a, b;

    line(ll a = 0, ll b = 0) : a(a), b(b) {}

    ll val(ll x) {return a*x + b;}
};

struct IntervalTree
{
    int l, r;
    line cur;
    IntervalTree* lc;
    IntervalTree* rc;

    IntervalTree(int l = 0, int r = 0) : l(l), r(r)
    {
        cur = line();
        if (l == r)
            lc = rc = NULL;
        else
        {
            lc = new IntervalTree(l, mid);
            rc = new IntervalTree(mid+1, r);
        }
    }

    void update(int x, int y, line val)
    {
        if (l > y || r < x) return;
        if (l >= x && r <= y)
        {
            ll lCur = cur.val(l);
            ll rCur = cur.val(r);
            ll lVal = val.val(l);
            ll rVal = val.val(r);
            if (lCur >= lVal && rCur >= rVal)
                return;
            if (lCur <= lVal && rCur <= rVal)
            {
                cur = val;
                return;
            }
            ll gCur = cur.val(mid);
            ll gVal = val.val(mid);
            if (lCur >= lVal && gCur >= gVal)
            {
                rc -> update(x, y, val);
                return;
            }
            if (lCur <= lVal && gCur <= gVal)
            {
                rc -> update(x, y, cur);
                cur = val;
                return;
            }
            if (gCur >= gVal && rCur >= rVal)
            {
                lc -> update(x, y, val);
                return;
            }
            if (gCur <= gVal && rCur <= rVal)
            {
                lc -> update(x, y, cur);
                cur = val;
                return;
            }
        }
        lc -> update(x, y, val);
        rc -> update(x, y, val);
    }
    ll getmax(int x)
    {
        if (l > x || r < x) return 0;
        ll res = cur.val(x);
        if (l == r) return res;
        res = max(res, lc -> getmax(x));
        res = max(res, rc -> getmax(x));
        return res;
    }
}t;

int n, m;

int main()
{
    //freopen("INP.TXT", "r", stdin);
    cin >> n >> m;
    t = IntervalTree(1, n);
    ll s, e, v, d;
    for (int i = 1; i <= m; i++)
    {
        cin >> s >> e >> v >> d;
        t.update(s, e, line(d, v - s*d));
    }
    for (int i = 1; i <= n; i++) cout <<t.getmax(i)<<'\n';
    return 0;
}
