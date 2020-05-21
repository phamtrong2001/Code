#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 105
#define Task "pcolor"
using namespace std;
int n,m,dem = -1,cur[maxn*maxn],c[12*maxn*maxn],sum,q[maxn*maxn],h[12*maxn*maxn],F[12*maxn*maxn];
int xx[4] = {-1,0,1,0};
int yy[4] = {0,1,0,-1};
vector <pair <int,int> > a[maxn*maxn];
void them(int u,int v,int w)
{
    a[u].pb(mp(v,++dem));
    c[dem] = w;
    a[v].pb(mp(u,++dem));
    c[dem] = 0;
}
void nhap()
{
    int x;
    cin >> n;
    FOR(i,1,n)
        FOR(j,1,n)
        {
            cin >> x;
            sum += x;
            them(0,(i-1)*n + j,x);
        }
    FOR(i,1,n)
        FOR(j,1,n)
        {
            cin >> x;
            sum += x;
            them((i-1)*n + j,n*n+1,x);
        }
    FOR(i,1,n)
        FOR(j,1,n)
            FOR(k,0,3)
            {
                cin >> x;
                int u = i + xx[k];
                int v = j + yy[k];
                if ( u >= 1 && u <= n && v <= n &&v >= 1)
                    them((i-1)*n+j,(u-1)*n+v,x);
            }
}
bool bfs()
{
    int top = 1, bot = 1;
    memset(h,-1,sizeof (h));
    q[1] = h[0] = 0;
    while (bot <= top)
    {
        int u = q[bot++];
        for (int i = 0; i < a[u].size();++i)
        {
            int v = a[u][i].first;
            int id = a[u][i].S;
            if ( F[id] < c[id] && h[v] == -1)
            {
                h[v] = h[u] + 1;
                q[++top] = v;
            }
        }
    }
    return (h[n*n+1] != -1);
}
int getf(int u,int f)
{
    int ans = 0;
    if ( u == n*n + 1 || !f) return f;
    for(;cur[u] < a[u].size();++cur[u])
    {
        int v = a[u][cur[u]].first;
        int id = a[u][cur[u]].S;
        if ( h[v] != h[u] + 1 || c[id] <= F[id]) continue;
        int p = getf(v,min(f,c[id] - F[id]));
        if (p)
        {
            F[id] += p;
            F[id^1] -= p;
            ans += p;
            f -= p;
            if (!f) break;
        }
    }
    return ans;
}
int Maxflow()
{
    int kq = 0;
    while (1)
    {
        if(!bfs()) break;
        memset(cur,0,sizeof (cur));
        while (int P = getf(0,maxc))
            kq += P;
    }
    return kq;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    freopen(Task".inp", "r",stdin);
    freopen(Task".out", "w",stdout);
    nhap();
    cout << sum - Maxflow();
    return 0;
}
