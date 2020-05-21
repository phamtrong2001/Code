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
#define task "convex"
#define maxc 1000000007
#define maxn 200005

using namespace std;

int n, m;

pair <pii, int> a[maxn], b[maxn];

void nhap()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = MP(MP(x, y), i);
    }
}

pii vect (pair <pii, int> p, pair <pii, int> q)
{
    return MP(q.F.F  - p.F.F, q.F.S- p.F.S);
}

long long CCW(pair <pii, int> p, pair <pii, int> q, pair <pii, int> r)
{
    pii u = vect(p, q);
    pii v = vect(q, r);
    return (1ll * u.F * v.S - 1ll * u.S * v.F);
}

void Make_convex(pair <pii, int> a[], int n, pair <pii, int> b[], int &m)
{
    sort(a+1, a+n+1);
    m = 1;
    b[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        while (m > 1 && CCW(b[m-1], b[m], a[i]) <= 0) m--;
        b[++m] = a[i];
    }
    int chot = m;
    for (int i = n-1; i >= 1; i--)
    {
        while (m > chot && CCW(b[m-1], b[m], a[i]) <= 0) m--;
        b[++m] = a[i];
    }
    m--;
}

double dis(pair <pii, int> a, pair <pii, int> b)
{
    long long hx = a.F.F - b.F.F;
    long long hy = a.F.S - b.F.S;
    return sqrt(hx*hx + hy*hy);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    nhap();
    Make_convex(a, n, b, m);
    printf("%d\n", m);
    for (int i = 1; i <= m; i++)
        printf("%d ", b[i].S);
    b[m+1] = b[1];
    ll dientich = 0;
    double chuvi = 0.0;
    for (int i = 1; i <= m; i++)
    {
        dientich += 1ll * (b[i].F.F - b[i+1].F.F) * (b[i].F.S + b[i+1].F.S);
        chuvi += dis(b[i], b[i+1]);
    }
    printf("\n%0.6f\n", chuvi);
    printf("%lld.%d", dientich/2, (dientich % 2) ? 5 : 0);
    return 0;
}
