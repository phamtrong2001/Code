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
#define Task "one"
using namespace std;
int n, s, leng, res, ans;
vector <pii > g[maxn];
bool dd[maxn];

void setup() {
    cin >> n >> s;
    rep(i, 1, n-1) {
        int u, v, ts;
        cin >> u >> v >> ts;
        ans += ts;
        g[u].PB(mp(v, ts));
        g[v].PB(mp(u, ts));
    }
}

void DFS(int u, int dis) {
    dd[u] = 1;
    leng = max(leng, dis);
    for(pii p : g[u]) {
        int v = p.F;
        int ts = p.S;
        if(dd[v]) continue;
        DFS(v, dis + ts);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    DFS(s, 0);
    cout << ans*2 - leng;
    return 0;
}
