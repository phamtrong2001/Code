/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxc 1000000007
#define task "atm"
#define maxn 500005

using namespace std;

int m, n, s, p, q[maxn], dd[maxn], a[maxn], index[maxn], low[maxn], cnt, top, dem, vt, tp[maxn];

long long gt[maxn], res[maxn], kq = -maxc;

bool dd2[maxn], kt[maxn];

vector <int> ke[maxn], b[maxn];

pair <int, int> canh[maxn];

map <pair <int, int>, bool> ma;

void nhap()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &canh[i].F, &canh[i].S);
        ke[canh[i].F].PB(canh[i].S);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    scanf("%d%d", &s, &p);
    for (int i = 1; i <= p; i++)
        scanf("%d", &dd[i]);
}

void visit(int u)
{
    index[u] = ++cnt;
    low[u] = cnt;
    kt[u] = 1;
    q[++top] = u;
    for (int &v : ke[u])
    {
        if (!index[v])
            {
                visit(v);
                low[u] = min(low[u], low[v]);
            }
        else if (kt[v]) low[u] = min(low[u], index[v]);
    }
    if (index[u] == low[u])
    {
        dem++;
        while (q[top] != u)
        {
            int v = q[top];
            gt[dem] += a[v];
            tp[v] = dem;
            kt[v] = 0;
            top--;
        }
        gt[dem] += a[u];
        tp[u] = dem;
        kt[u] = 0;
        top--;
    }
}

void xuli()
{
    for (int i = 1; i <= n; i++)
        if (!index[i]) visit(i);
    for (int i = 1; i <= m; i++)
    {
        int u = canh[i].F;
        int v = canh[i].S;
        if (ma[MP(tp[u], tp[v])] || tp[u] == tp[v]) continue;
        ma[MP(tp[u], tp[v])] = 1;
        b[tp[u]].PB(tp[v]);
    }
}

void ghi()
{
    int vt = tp[s];
    int l, r;
    l = r = 1;
    memset(q, 0, sizeof(q));
    q[1] = vt;
    dd2[vt] = 1;
    res[vt] = gt[vt];
    while(l <= r)
    {
        int u = q[l++];
        for (int &v : b[u])
            {
                res[v] = max(res[v], res[u]+gt[v]);
                dd2[v] = 1 ;
                q[++r] = v;
            }
    }
    for (int i = 1; i <= p; i++)
        kq = max(kq, res[tp[dd[i]]]);
    printf("%lld", kq);
}

int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    nhap();
    xuli();
    ghi();
    return 0;
}
