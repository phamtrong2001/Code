// MR.J
#include<bits/stdc++.h>
#define maxn 100005
#define maxC 1000000000
#define MOD 1000000007
#define mp make_pair
#define PB push_back
#define F first
#define S second
#define pii pair<int, int>
#define ll long long
#define rep(i, a, b) for(int i=(a) ; i<=(b) ; ++i)
#define repd(i, a, b) for(int i=(a) ; i>=(b) ; --i)
#define Task "blo"
using namespace std;
int n, m, index[maxn], low[maxn], cnt, sz[maxn], par[maxn], dd[maxn];
ll res[maxn];
vector <int > g[maxn];

void setup() {
    scanf("%d%d", &n, &m);
    rep(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].PB(v);
        g[v].PB(u);
    }
}

void DFS(int u) {
    index[u] = low[u] = ++cnt;
    int child;
    ll ans = 0, dem = 0;
    for(int &v : g[u]) {
        if(v == par[u]) continue;
        if(index[v]) low[u] = min(low[u], index[v]);
        else {
            par[v] = u;
            DFS(v);
            if(low[v] >= index[u]) {
                ++child;
                ans += 1ll*sz[v]*(n - sz[v]);
                dem += 1ll*sz[v];
            }
            low[u] = min(low[u], low[v]);
            sz[u] += sz[v];
            dd[u] |= ((u == par[u] && child > 1) || (low[v] >= index[u]));
        }
    }
    ++sz[u];
    if(!dd[u]) res[u] = 2ll*(n - 1);
    else res[u] = ans + 1ll*(n - dem)*dem + 2*(n - dem - 1);
}

int main() {
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    DFS(1);
    rep(i, 1 , n) {
        printf("%lld\n", res[i]);
    }
    return 0;
}
