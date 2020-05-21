// MR.J
#include<bits/stdc++.h>
#define maxn 300005
#define maxC 1000000000
#define MOD 1000000007
#define mp make_pair
#define PB push_back
#define F first
#define S second
#define pii pair<int, int>
#define ll long long
#define rep(i, a, b) for(ll i=(a) ; i<=(b) ; ++i)
#define repd(i, a, b) for(ll i=(a) ; i>=(b) ; --i)
#define Task "p2path"
using namespace std;
ll tp[maxn], s[maxn], n, id, ff[maxn], prv[maxn], dp1[maxn], dp2[maxn], f[maxn], f2[maxn], f3[maxn], ft[maxn];
vector <ll> g[maxn];
pii edge[maxn];
bool dd[maxn];

void setup() {
    cin >> n;
    rep(i, 1, n-1) {
        ll u, v;
        cin >> u >> v;
        edge[i] = mp(u, v);
        g[u].PB(v);
        g[v].PB(u);
    }
}

void DFS(ll u) {
    dd[u] = 1;
    tp[++id] = u;
    s[u] = id;
    for(ll&v : g[u]) {
        if(dd[v]) continue;
        prv[v] = u;
        DFS(v);
    }
    ff[u] = id;
}

void prepare() {
    repd(i, n, 1) {
        ll u = tp[i];
        for(ll &v : g[u]) {
            if(prv[v] != u) continue;
            if(f[u] < f[v] + 1) {
                f3[u] = f2[u];
                f2[u] = f[u];
                f[u] = f[v] + 1;
            } else if(f2[u] < f[v] + 1) {
                f3[u] = f2[u];
                f2[u] = f[v] + 1;
            } else if(f3[u] < f[v] + 1) f3[u] = f[v] + 1;
        }
    }
    rep(i, 1, n) {
        ll u = tp[i];
        ll w = prv[u];
        if(w) {
            ft[u] = ft[w] + 1;
            if(f[u] + 1 == f[w]) ft[u] = max(ft[u], f2[w] + 1);
            else ft[u] = max(ft[u], f[w] + 1);
        }
    }
}

void calc() {
    repd(i, n, 1) {
        ll u = tp[i];
        dp1[u] = f[u] + f2[u];
        for(ll &v : g[u]) {
            if(prv[v] != u) continue;
            dp1[u] = max(dp1[u], dp1[v]);
        }
    }
    rep(i, 1, n) {
        ll u = tp[i];
        ll w = prv[u];
        if(w) {
            dp2[u] = dp2[w];
            if(f[u] + 1 == f[w]) dp2[u] = max(dp2[u], ft[w] + f2[w]);
            else dp2[u] = max(dp2[u], ft[w] + f[w]);

            if(f[u] + 1 == f[w]) dp2[u] = max(dp2[u], f2[w] + f3[w]);
            else if(f2[u] + 1 == f[w]) dp2[u] = max(dp2[u], f[w] + f3[w]);
            else dp2[u] = max(dp2[u], f[w] + f2[w]);
        }
    }
}

void handling() {
    ll ans = -1ll*maxC*maxC;
    rep(i, 1, n) {
        ans = max(ans, dp1[i]*dp2[i]);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    DFS(1);
    prepare();
    calc();
    handling();
    return 0;
}
