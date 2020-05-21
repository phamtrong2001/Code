// MR.J
#include<bits/stdc++.h>
#define maxn 500005
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
#define Task "drvtruck"
using namespace std;
int n, prv[maxn], k, tp[maxn], st[maxn], fn[maxn], s[maxn], id, fa[maxn], fa2[maxn], fb[maxn];
ll Ta[maxn], Tb[maxn];
vector <pii > g[maxn];
bool dd[maxn], fl[maxn];
map <pii, int > a;

void setup() {
    cin >> n >> k;
    rep(i, 1, n-1) {
        int u, v, ts;
        cin >> u >> v >> ts;
        g[u].PB(mp(v, ts));
        g[v].PB(mp(u, ts));
    }
    rep(i, 1, k) {
        int u;
        cin >> u;
        fl[u] = 1;
        s[u] = 1;
    }
}

void DFS(int u) {
    dd[u] = 1;
    tp[++id] = u;
    st[u] = id;
    for(pii P : g[u]) {
        int v = P.F;
        if(dd[v]) continue;
        prv[v] = u;
        DFS(v);
        s[u] += s[v];
    }
    fn[u] = id;
}

void prepare() {
    repd(i, n, 1) {
        int u = tp[i];
        for(pii P : g[u]) {
            int v = P.F;
            int ts = P.S;
            if(prv[v] != u) continue;
            if(s[v] > 0) {
                Ta[u] += Ta[v] + ts;
                if(fa[u] < fa[v] + ts) {
                    fa2[u] = fa[u];
                    fa[u] = fa[v] + ts;
                } else if(fa2[u] < fa[v] + ts) fa2[u] = fa[v] + ts;
             }
        }
    }
    rep(i, 1, n) {
        int u = tp[i];
        for(pii P : g[u]) {
            int v = P.F, w = P.S;
            if(prv[v] != u || s[v] - k == 0) continue;
            fb[v] = fb[u] + w;
            if(fa[u] == fa[v] + w) fb[v] = max(fb[v], w + fa2[u]);
            else fb[v] = max(fb[v], w + fa[u]);
            if(s[v]) Tb[v] = Tb[u] + w + Ta[u] - Ta[v] - w;
            else Tb[v] = Tb[u] + w + Ta[u];
        }
    }
}

void calc() {
    rep(i, 1, n) {
        ll ans = (Ta[i] + Tb[i])*2 - max(fa[i], fb[i]);
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    DFS(1);
    prepare();
    calc();
    return 0;
}
