/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<long long, long long>
#define PB push_back
#define MP make_pair
#define ll long long
#define F first
#define S second
#define task "chiadat"
#define maxc 1000000007
#define maxn 5003

using namespace std;

int n;

double l, r, dientich;

pdd a[maxn];

void nhap()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].F >> a[i].S;
}

double SS (pdd x, pdd y)
{
    return ((x.F - y.F)*(x.S + y.S)/2);
}

void chuanbi()
{
    dientich = 0.0;
    a[n+1] = a[1];
    for (int i = 1; i <= n; i++)
        dientich += SS(a[i], a[i+1]);
    dientich = abs(dientich);
    l = r = a[1].F;
    for (int i = 2; i <= n; i++)
        l = min(l, a[i].F), r = max(r, a[i].F);
}

bool cat(pdd x, pdd y, double pos)
{
    return ((x.F >= pos && y.F <= pos) || (x.F <= pos && y.F >= pos));
}

pdd giao(pdd x, pdd y, double pos)
{
    pdd res;
    res.F = pos;
    double a = x.S - y.S;
    double b = x.F - y.F;
    double c = x.F*(x.S - y.S) - x.S*(x.F - y.F);
    if (!b) res.S = 0;
        else res.S = (pos*a-c)/b;
    return res;
}

double tinh(double pos)
{
    double res = 0.0;
    int x = 1;
    while (!cat(a[x], a[x+1], pos)) x++;
    int y = x+1;
    if (pos == a[x+1].F) y++;
    while (!cat(a[y], a[y+1], pos)) y++;
    pdd u = giao(a[x], a[x+1], pos);
    pdd v = giao(a[y], a[y+1], pos);
    res = SS(u, a[x+1]) + SS(a[y],v) + SS(u, v);
    for (int i = x+1; i <= y-1; i++)
        res += SS(a[i], a[i+1]);
    if (u.S < v.S) res = dientich - res;
    return res;
}

void xuli()
{
    while (r - l >= 0.00001)
    {
        double mid = (l + r) / 2;
        double cur = tinh(mid);
        if (cur < dientich/2) l = mid;
            else r = mid;
    }
    printf("%0.4f", l);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    nhap();
    chuanbi();
    xuli();
    return 0;
}
