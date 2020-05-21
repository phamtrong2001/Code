#include <bits/stdc++.h>
#define pii pair<int, int>
#define N 1004
#define mp make_pair
#define F first
#define S second
#define PB push_back

using namespace std;

int n, flag, dd[N];
pii a[N];
int main()
{
    freopen("INP.TXT", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i].F = i;
        cin >> a[i].S;
    }
    for (int i = 1; i <= n; i++)
    {
        memset(dd, 0, sizeof dd);
        dd[1] = 1;
        int u = a[i].F - a[1].F;
        int v = a[i].S - a[1].S;
        int l1, l2;
        bool hs = 0;
        if (v == 0)
        {
            for (int j = 2; j <= n; j++)
                if (a[j].S == a[1].S) dd[j] = 1;
            hs = 1;
        }
        else
        {

            int g = __gcd(u, v);
            u /= g; v /= g;
            for (int j = 2; j <= n; j++)
            {
                int x = a[j].F - a[1].F;
                int y = a[j].S - a[1].S;
                if (x % u || y % v || x/u != y/v) continue;
                dd[j] = 1;
            }
            l1 = u; l2 = v;
        }
        vector<int> ve;
        for (int j = 1; j <= n; j++)
            if (!dd[j]) ve.PB(j);
        if (ve.size() == 0) continue;
        if (ve.size() == 1)
        {
            flag = 1;
            break;
        }
        u = a[ve[0]].F - a[ve[1]].F;
        v = a[ve[0]].S - a[ve[1]].S;
        bool ok = 0;
        if (v == 0)
        {
            for (int j = 1; j < ve.size(); j++)
                if (a[ve[j]].S != a[ve[0]].S)
                {
                    ok = 1;
                    break;
                }
        }
        else
        {
            int g = __gcd(u, v);
            u /= g; v /= g;
            if (l1 / u != l2 / v && hs == 0) continue;
            for (int j = 1; j < ve.size(); j++)
            {
                int x = a[ve[j]].F - a[ve[0]].F;
                int y = a[ve[j]].S - a[ve[0]].S;
                if (x % u || y % v || x/u != y/v)
                {
                    ok = 1;
                    break;
                }
            }
        }
        if (!ok)
        {
            flag = 1;
            break;
        }
    }
    if (flag) cout <<"Yes";
    else cout <<"No";
}
