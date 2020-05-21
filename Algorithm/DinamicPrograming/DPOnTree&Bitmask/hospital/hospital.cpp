// MR.J
#include<bits/stdc++.h>
#define maxn 100005
#define maxC 1000000000
#define MOD 1000000007
#define mp make_pair
#define PB push_back
#define F first
#define S second
#define pii pair<ll, ll>
#define ll long long
#define rep(i, a, b) for(ll i=(a) ; i<=(b) ; ++i)
#define repd(i, a, b) for(ll i=(a) ; i>=(b) ; --i)
#define Task "hospital"
using namespace std;
ll n, ts[maxn], tp[maxn], id, s[maxn], f[maxn], prv[maxn], d[maxn];
vector <ll > g[maxn];
bool dd[maxn];
ll sum;

void setup() {
    cin >> n;
    rep(i, 1, n) cin >> ts[i], sum += ts[i], d[i] = ts[i];
    rep(i, 1, n-1) {
        ll u, v;
        cin >> u >> v;
        g[u].PB(v);
        g[v].PB(u);
    }
}

void DFS(ll u) {
    dd[u] = 1;
    tp[++id] = u;
    s[u] = id;
    for(ll &v : g[u]) {
        if(dd[v]) continue;
        prv[v] = u;
        DFS(v);
    }
    f[u] = id;
}

void calc() {
    ll res = 1ll*maxC*maxC;
    int node;
    repd(i, n, 1) {
        int u = tp[i];
        ll ans = -1ll*maxC*maxC;
        for(ll &v : g[u]) {
            if(prv[v] != u) continue;
            ans = max(ans, d[v]);
            d[u] += d[v];

        }
        if(res > max(ans, sum - d[u])) {
            res = max(ans, sum - d[u]);
            node = u;
        }
    }
    cout << node;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    DFS(1);
    calc();
    return 0;
}
