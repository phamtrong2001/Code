// MR.J
#include<bits/stdc++.h>
#define maxn 105
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
#define Task "apple"
using namespace std;
int n, ed[maxn], q, tp[maxn], id, prv[maxn];
vector <pii > g[maxn];
bool dd[maxn];
ll f[maxn][maxn];

void setup() {
    cin >> n >> q;
    rep(i, 1, n-1) {
        int u, v, ts;
        cin >> u >> v >> ts;
        g[u].PB(mp(v, ts));
        g[v].PB(mp(u, ts));
    }
}

void DFS(int u) {
    dd[u] = 1;
    tp[++id] = u;
    for(pii P : g[u]) {
        int v = P.F;
        if(dd[v]) continue;
        ++ed[u];
        prv[v] = u;
        DFS(v);
        ed[u] += ed[v];
    }
}

void calc() {
    //rep(i, 1, n) cout << ed[i] << ' ';
    repd(i, n, 1) {
        int u = tp[i];
        rep(j, 1, min(ed[u], q)) {
            int v0 = 0, v1 = 0, w0, w1;
            for(pii P : g[u]) {
                int v = P.F;
                if(prv[v] != u) continue;
                if(!v0) {
                    v0 = P.F;
                    w0 = P.S;
                } else {
                    v1 = P.F;
                    w1 = P.S;
                }
            }
            int sl = (v1 > 0) + (v0 > 0);
            if(j >= sl) {
                ll sum = 0;
                if(v0) sum += w0;
                if(v1) sum += w1;
                rep(k, 0, j-2) {
                    if(v0) sum += f[v0][k];
                    if(v1) sum += f[v1][j-2-k];
                }
                f[u][j] = max(f[u][j], sum);
            }
            if(v0) f[u][j] = max(f[u][j], w0 + f[v0][j-1]);
            if(v1) f[u][j] = max(f[u][j], w1 + f[v1][j-1]);
        }
    }
    cout << f[1][q];
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
