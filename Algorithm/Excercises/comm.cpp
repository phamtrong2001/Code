#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxn 155
#define maxc 1000000007
#define PB push_back

using namespace std;

int n, m, s, t, w, cmin;
int gt[maxn*maxn], f[maxn];
bool kt[maxn];
double kq;

struct data
{
    int vv, cc, dd;
    data (int _vv = 0, int _cc = 0, int _dd = 0) {
        vv = _vv;
        cc = _cc;
        dd = _dd;
    }
};

vector <data> ke[maxn];

void nhap()
{
    cin >> n >> m >> s >> t >> w;
    for (int i = 1; i <= m ;i++)
    {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        ke[u].PB(data(v, c, d));
        ke[v].PB(data(u, c, d));
        gt[i] = c;
    }
}

void chuanbi()
{
    sort(gt+1, gt+m+1);
    gt[0] = maxc;
    kq = 1.0*maxc;
}

void dijktra()
{
    memset(kt, 0, sizeof(kt));
    for (int i = 0; i <= n; i++)
        f[i] = maxc;
    f[s] = 0;
    while(1)
    {
        int u = 0;
        for (int i = 1; i <= n; i++)
            if (!kt[i] && f[u] > f[i]) u = i;
        if (!u || u == t) break;
        kt[u] = 1;
        for (int i = 0; i < ke[u].size(); i++)
        {
            int v = ke[u][i].vv;
            int g = ke[u][i].cc;
            int d = ke[u][i].dd;
            if (g < cmin) continue;
            if (!kt[v] && f[v] > f[u] + d)
                f[v] = f[u] + d;
        }
    }
}

void tinh(int x)
{
    cmin = x;
    dijktra();
    double cur = double(w)/cmin + f[t];
    kq = min(kq, cur);
}

void xuli()
{
    for (int i = 1; i <= m; i++)
        if (gt[i] != gt[i-1]) tinh(gt[i]);
}

int main()
{
    freopen("comm.inp", "r", stdin);
    freopen("comm.out", "w", stdout);
    nhap();
    chuanbi();
    xuli();
    printf("%0.2f", kq);
    return 0;
}
