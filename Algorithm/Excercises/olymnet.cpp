#include<bits/stdc++.h>
#define maxn 1005
#define maxm 10005
#define maxC 1000000007
#define mp make_pair
#define PB push_back
#define F first
#define S second
using namespace std;

struct data{
    int u, v, ts;
};

vector <int> b[maxn*maxn];
long long n, m;
data a[maxn*maxn];
long long res;
int kq[maxm], dem, val, root[maxn], c[maxn][maxn], fr[maxn];

void setup()
{
    cin >> n >> m;
    for(int i=1, u, v, ts ; i<=m ; i++)
    {
        cin >> u >> v >> ts;
        a[i] = {u,v,ts};
    }

    for(int i=1 ; i<n ; i++)
        for(int j=i+1 ; j<=n ; j++)
            c[i][j] = c[j][i] = maxC;
}

int Get_root(int u)
{
    return (root[u]) ? root[u] = Get_root(root[u]) : u;
}

bool cmp(data q, data p)
{
    return q.ts <= p.ts;
}

void solve()
{
    for(int i=1 ; i <= n ; i++) root[i] = 0;
    sort(a+1, a+1+m, cmp);
    for(int i=1 ; i<=m ; i++)
    {
        int q = Get_root(a[i].u);
        int p = Get_root(a[i].v);
        if(q == p) continue;
        root[q] = p;
        res += a[i].ts;
        kq[++dem] = i;
        b[a[i].u].PB(a[i].v);
        b[a[i].v].PB(a[i].u);
        c[a[i].u][a[i].v] = c[a[i].v][a[i].u] = a[i].ts;
    }
    cout << res << " ";
}

void DFS(int u)
{
    fr[u] = 1;
    for(int i=0 ; i<b[u].size() ; i++)
    {
        int v = b[u][i];
        if(fr[v]) continue;
        DFS(v);
    }
}

void xuly()
{
    int them = maxC;
    for(int i=1 ; i<=dem ; i++)
    {
        int canh = kq[i];
        memset(fr, 0, sizeof fr);
        fr[a[canh].u] = 1;
        DFS(a[canh].v);
        fr[a[canh].u] = 0;
        for(int i=1 ; i<=m ; i++)
            if(fr[a[i].u] != fr[a[i].v] && i!=canh)
                them = min(abs(a[i].ts - a[canh].ts), them);
    }
    cout << res + them;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("olymnet.inp", "r", stdin);
    freopen("olymnet.out", "w", stdout);
    setup();
    solve();
    xuly();
    return 0;
}
