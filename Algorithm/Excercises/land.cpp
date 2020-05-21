/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define pii pair<int, int>
#define pdd pair<double, double>
#define PB push_back
#define MP make_pair
#define ll long long
#define F first
#define S second
#define task "land"
#define maxc 1000000007
#define maxn 10004

using namespace std;

int n, dem = 0;

double a1, b1, c1, a2, c2, b2, s1 = 0.0, s2 = 0.0;

pdd a[maxn], cur[2*maxn];

pair <pdd, int> b[maxn];

void nhap()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i].F = x;
        a[i].S = y;
    }
}

double dientich(int pos)
{
    double res = 0;
    for (int i = 1; i <= pos; i++)
        res += (cur[i].F - cur[i-1].F) * (cur[i].S + cur[i-1].S);
    return res;
}

pdd vect(pdd p, pdd q)
{
    return MP(p.F - q.F, p.S - q.S);
}

double CCW(pdd p, pdd q, pdd r)
{
    pdd u = vect(p, r);
    pdd v = vect(r, q);
    return (u.F*v.S - u.S*v.F);
}

void giao(int id, pdd x, pdd y, int &dem)
{
    if (CCW(a[1], a[n], x) * CCW(a[1], a[n], y) >= 0) return;
    a2 = x.S - y.S;
    b2 = y.F - x.F;
    c2 = x.S*(x.F - y.F) - x.F*(x.S - y.S);
    if (!(a2*b1-a1*b2)) return;
    double Y = 1.0 * (a1*c2-a2*c1)/(a2*b1-a1*b2);
    double X = -1.0*(b1*Y+c1)/a1;
    b[++dem] = MP(MP(X, Y), id);
}

void chuanbi()
{
    a1 = a[1].S - a[n].S;
    b1 = a[n].F - a[1].F;
    c1 = a[1].S*(a[1].F - a[n].F) - a[1].F*(a[1].S - a[n].S);
    dem = 0;
    b[++dem] = MP(a[1], 1);
    for (int i = 1; i < n; i++)
        giao(i, a[i], a[i+1], dem);
    b[++dem] = MP(a[n], n-1);
}

void xuli()
{
    for (int i = 2; i <= dem; i++)
    {
        int pos = 0;
        cur[++pos] = b[i].F;
        int vt = b[i].S;
        while (vt != b[i-1].S)
            cur[++pos] = a[vt--];
        cur[++pos] = b[i-1].F;
        cur[0] = cur[pos];
        double res = dientich(pos);
        if (res < 0) s2 += res;
            else s1 += res;
    }
    printf("%0.4f\n", s1/2);
    printf("%0.4f", abs(s2)/2);
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
