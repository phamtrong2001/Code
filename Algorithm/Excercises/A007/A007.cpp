#include <bits/stdc++.h>
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define PB push_back
#define N 100005
#define ll long long
using namespace std;

ll b, n, m, szIn[N], sumSz[N], val[N], sz[N], newV[N], C[N], scc, state[N];
long long dp[N];
ll indexx[N], low[N], tt, belong[N], in[N];
stack<ll> s;
vector<ll> a[N], g[N];

void nhap()
{
    cin >> b >> n >> m;
    for (int i = 1; i <= b; i++)
    {
        cin >> szIn[i]; sumSz[i] = sumSz[i-1] + szIn[i];
        for (int j = 1; j <= szIn[i]; j++)
        {
            ll x; cin >> x;
            val[sumSz[i-1] + j] = x;
        }
    }
    for (int i = n+1; i <= n+m; i++)
    {
        cin >> val[i] >> sz[i];
        for (int j = 0; j < sz[i]; j++)
        {
            ll x; cin >> x;
            a[x].PB(i);
        }
    }
}

void visit(ll u)
{
    indexx[u] = ++tt;
    low[u] = indexx[u];
    s.push(u);
    for (auto v : a[u])
    {
        if (indexx[v] != 0) low[u] = min(low[u], indexx[v]);
        else
        {
            visit(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (indexx[u] == low[u])
    {
        ll v = 0; ++scc;
        while (v != u)
        {
            v = s.top(); s.pop();
            indexx[v] = maxc;
            belong[v] = scc;
        }
    }
}

void buildGraph()
{
    for (int i = 1; i <= n+m; i++)
        if (!indexx[i]) visit(i);
    memset(newV, 60, sizeof newV);
    for (int i = 1; i <= n+m; i++)
        newV[belong[i]] = min(newV[belong[i]], val[i]);
    for (int u = 1; u <= n+m; u++)
        for (auto v : a[u])
        {
            if (belong[u] == belong[v]) continue;
            g[belong[u]].PB(belong[v]);
            in[belong[v]]++;
        }
}
void topoPrepare()
{
    queue<pair<ll, ll> > q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i]) continue;
        ll u = belong[i];
        ll lab = lower_bound(sumSz+1, sumSz+b+1, i) - sumSz - 1;
        state[u] = (1 << lab);
    }
    for (int i = 1; i <= scc; i++)
    {
        if (in[i]) continue;
        q.push(mp(i, state[i]));
    }
    while (!q.empty())
    {
        ll u = q.front().F;
        ll vv = q.front().S;
        q.pop();
        for (auto v : g[u])
        {
            state[v] |= vv;
            in[v]--;
            if (in[v] == 0) q.push(mp(v, state[v]));
        }
    }
    memset(C, 60, sizeof C);
    for (int i = 1; i <= scc; i++)
        C[state[i]] = min(C[state[i]], newV[i]);
}
void dpSolve()
{
    memset(dp, 60, sizeof dp); dp[0] = 0;
    for (int x = 0; x < (1 << b); x++)
        for (int y = 0; y < (1 << b); y++)
            dp[x | y] = min(dp[x | y], dp[x] + C[y]);
    cout <<dp[(1 << b)-1];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("A007.INP", "r", stdin);
    //freopen("A007.OUT", "w", stdout);
    nhap();
    buildGraph();
    topoPrepare();
    dpSolve();
}
