// MR.J
#include<bits/stdc++.h>
#define maxn 1000005
#define maxC 1000000007
#define mp make_pair
#define PB push_back
#define F first
#define S second
#define pii pair<int, int>
#define MOD 1000000000
#define Task "center_node"

using namespace std;

int n, dp[maxn], dp2[maxn], vs[maxn], dis[maxn], root[maxn];
vector <pii > g[maxn];

void setup() {
    cin >> n;
    for(int i=1, u, v, ts ; i<=n ; i++) {
        cin >> u >> v >> ts;
        g[u].PB(mp(v, ts));
        g[v].PB(mp(u, ts));
    }
}

void DFS(int u) {
        for(pii p : g[u]) {
            int v = p.F;
            int ts = p.S;
            if(root[u] == v) continue;
            root[v] = u;
            dis[v] = dis[u] + ts;
            DFS(v);
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    DFS(1);
    int pivot = max_element(dis+1, dis+1+n) - dis;
    memset(dis, 0, sizeof dis);
    memset(root, 0, sizeof root);
    DFS(pivot);
    int pivot2 = max_element(dis+1, dis+1+n) - dis;
    int ok = maxC, tt = pivot2;
    while(tt != pivot) {
        if(ok > max(dis[pivot2] - dis[tt], dis[tt])) ok = max(dis[pivot2] - dis[tt], dis[tt]);
        tt = root[tt];
    }
    cout << ok;
    return 0;
}
