// MR.J
#include<bits/stdc++.h>
#define maxn 50005
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
#define Task "maxtree"
using namespace std;
int tp[maxn], s[maxn], f[maxn], n, dp[maxn], id, prv[maxn];
bool dd[maxn];
vector <pii > g[maxn];

void setup() {
    cin >> n;
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
    s[u] = id;
    for(pii P : g[u]) {
        int v = P.F;
        if(dd[v]) continue;
        prv[v] = u;
        DFS(v);
    }
    f[u] = id;
}

void calc() {
    repd(i, n, 1) {
        int u = tp[i];
        for(pii P : g[u]) {
            int v = P.F;
            int ts = P.S;
            if(prv[v] != u) continue;
            dp[u] += (dp[v] + ts > 0 ? dp[v] + ts : 0);
        }
    }
    cout << *max_element(dp+1, dp+n+1);
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
