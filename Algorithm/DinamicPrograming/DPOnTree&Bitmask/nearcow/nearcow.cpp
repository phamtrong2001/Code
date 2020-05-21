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
#define Task "nearcow"
using namespace std;
int n, tp[maxn], prv[maxn], c[maxn], id, k;
ll f[maxn][30], h[maxn][30], ff[maxn][30], hh[maxn][30];
vector <int > gr[maxn];
bool dd[maxn];

void setup() {
    cin >> n >> k;
    rep(i, 1, n-1) {
        int u, v;
        cin >> u >> v;
        gr[u].PB(v);
        gr[v].PB(u);
    }
    rep(i, 1, n) cin >> c[i];
}

void DFS(int u) {
    dd[u] = 1;
    tp[++id] = u;
    for(int &v : gr[u]) {
        if(dd[v]) continue;
        prv[v] = u;
        DFS(v);
    }
}

void calc() {
    rep(i, 1, n) h[i][0] = f[i][0] = ff[i][0] = hh[i][0] = c[i];
    repd(i, n, 1) {
        int u = tp[i];
        for(int &v : gr[u]) {
            if(prv[v] != u) continue;
            rep(i, 1, k) f[u][i] += f[v][i-1];
        }
    }
    rep(i, 1, n) {
        int u = tp[i];
        int w = prv[u];
        if(w) {
            rep(leng, 1, k) {
                h[u][leng] += h[w][leng-1];
                if(leng > 1) h[u][leng] += f[w][leng-1] - f[u][leng-2];
            }
        }
    }
    rep(i, 1, n) {
        rep(j, 1, k) {
            ff[i][j] += ff[i][j-1] + f[i][j];
            hh[i][j] += hh[i][j-1] + h[i][j];
        }
    }
    rep(i, 1, n) cout << ff[i][k] + hh[i][k] - c[i] << '\n';
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
