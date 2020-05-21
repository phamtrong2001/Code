#include <bits/stdc++.h>
#define maxn 500005
#define maxC 1000000000
#define pii pair <int, int>
#define F first
#define S second
#define PB push_back
#define mp make_pair

using namespace std;

int n, m, loca, p, top, val, tplt, pivot;
int tp[maxn], a[maxn], low[maxn], index[maxn];
long long res[maxn], ts[maxn], q[maxn];
int s[maxn], dt[maxn], dd[maxn], inp[maxn];
vector <int > ke[maxn], b[maxn];
//map <pii, bool> m1;

struct canh{
    int u, v;
} ed[maxn];

void setup()
{
    scanf("%d%d", &n, &m);
    for(int i=1 ; i<=m ; i++)
    {
        scanf("%d%d", &ed[i].u, &ed[i].v);
        ke[ed[i].u].PB(ed[i].v);
        //m1[mp(ed[i].u, ed[i].v)] = 1;
    }
    for(int i=1 ; i<=n ; i++) scanf("%d", &a[i]);
    scanf("%d%d", &loca, &p);
    for(int i=1,u ; i<=p ; i++)
        scanf("%d", &dt[i]);
}

void DFS(int u)
{
    index[u] = ++val;
    low[u] = val;
    s[++top] = u;
    dd[u] = 1;
    for(int &v : ke[u])
    {
        if(!index[v])
        {
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
        else if(dd[v]) low[u] = min(low[u], low[v]);
    }
    if(index[u] == low[u])
    {
        tplt++;
        while(s[top] != u)
        {
            ts[tplt] += a[s[top]];
            tp[s[top]] = tplt;
            dd[s[top]] = 0;
            top--;
        }
        ts[tplt] += a[u];
        tp[u] = tplt;
        dd[u] = 0;
        top--;
    }
}

void solve()
{
    for(int i=1 ; i<=n ; i++)
        if(!index[i]) DFS(i);

    for(int i=1 ; i<=m ; i++)
    {
        int x = tp[ed[i].u];
        int y = tp[ed[i].v];
        if(x == y) continue;
        //if(m1[mp(ed[i].u, ed[i].v)])
        b[x].PB(y), inp[y]++;
        //else b[y].PB(x), inp[x]++;
    }
}

void Tarjan()
{
    for(int i=1 ; i<=tplt ; i++)
        res[i] = -1ll*maxC*maxC;
    int l = 1, r = 0;
    //inp[pivot] = maxC;
    pivot = tp[loca];
    res[pivot] = ts[pivot];
    for(int i=1 ; i<=tplt ; i++) if(!inp[i]) q[++r] = i;
    while(l <= r)
    {
        int u = q[l++];
        for(int &v : b[u])
        {
            if(--inp[v] == 0) q[++r] = v;
            if(res[v] < res[u] + ts[v])
                res[v] = res[u] + ts[v];
        }
    }
    long long ans = -maxC;
    for(int i=1 ; i<=p ; i++)
        ans = max(ans, res[tp[dt[i]]]);
    printf("%lld", ans);
}

int main()
{
    freopen("atm.inp","r",stdin);
    freopen("atm.out","w",stdout);
    setup();
    solve();
    Tarjan();
    return 0;
}
