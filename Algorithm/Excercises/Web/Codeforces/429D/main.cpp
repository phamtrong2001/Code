#include <bits/stdc++.h>
#define pii pair<double, double>
#define F first
#define S second
#define maxc 1e13
#define N 100005

using namespace std;

int n;
long long s[N];
pii a[N], strip[N];
bool compareY(pii p, pii q)
{
    if (p.S != q.S) return p.S < q.S;
    return p.F < q.F;
}
double dist(pii p, pii q)
{
    double XX = p.F - q.F;
    double YY = p.S - q.S;
    return sqrt(XX*XX + YY*YY);
}
double bruteForce(pii P[], int n)
{
    double kmin = maxc;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            kmin = min(kmin, dist(P[i], P[j]));
    return kmin;
}
double stripClosest(pii strip[], int n, double d)
{
    double kmin = d;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n && (strip[j].S - strip[i].S) < kmin; j++)
            kmin = min(kmin, dist(strip[i], strip[j]));
    return kmin;
}
double Calc(pii P[], int n)
{
    if (n <= 3)
    {
        sort(P, P+n, compareY);
        return bruteForce(P, n);
    }
    int mid = n/2;
    pii midpoint = P[mid];
    double dl = Calc(P, mid);
    double dr = Calc(P+mid, n-mid);
    double d = min(dl, dr);

    int cnt = 0;
    merge(P, P+mid, P+mid, P+n, strip, compareY);
    for (int i = 0; i < n; i++)
        if (abs(strip[i].F - midpoint.F) < d) strip[cnt++] = strip[i];
    return min(d, stripClosest(strip, cnt, d));
}
double Closest(pii a[], int n)
{
    sort(a, a+n);
    n = unique(a, a+n) - a;
    return Calc(a, n);
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].F;
        if (i == 0) s[i] = a[i].F;
        else s[i] = s[i-1] + a[i].F;
        a[i].F = s[i];
        a[i].S = i+1;
    }
    double res = Closest(a, n);
    //cerr<<res<<endl;
    res = ceil(res*res - 1e-5);
    long long ans = res;
    cout <<ans;
}
