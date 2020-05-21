/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define pii pair<int, int>
#define PB push_back
#define MP make_pair
#define ll long long
#define F first
#define S second
#define task "ncycles"
#define maxc 1000000007
#define maxn 300005

using namespace std;

int n, res = 1;

pii a[maxn];

stack <int> s;

bool comp(pii x, pii y)
{
    return ((x.S < y.S) || (x.S == y.S && x.F > y.F));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, r;
        cin >> x >> r;
        a[i] = MP(x-r, x+r);
    }
    sort(a+1, a+n+1, comp);
    for (int i = 1; i <= n; i++)
    {
        int pos = 0;
        while (!s.empty() && a[s.top()].F >= a[i].F)
        {
            pos += a[s.top()].S - a[s.top()].F;
            s.pop();
        }
        if (pos == a[i].S - a[i].F) res += 2;
            else res += 1;
        s.push(i);
    }
    cout << res;
    return 0;
}
