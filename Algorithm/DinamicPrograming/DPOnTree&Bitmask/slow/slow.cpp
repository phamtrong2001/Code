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
#define Task "slow"
using namespace std;
int tp[maxn], s[maxn], f[maxn], p[maxn], id, n;
bool dd[maxn];
vector <int > g[maxn];

struct FenwickTree {
    int tree[maxn];

    int getAns(int node) {
        int res = 0;
        while(node > 0) {
            res += tree[node];
            node -= node & (-node);
        }
        return res;
    }

    void update(int node, int val) {
        while(node <= n) {
            tree[node] += val;
            node += node & (-node);
        }
    }
} BIT;

void setup() {
    cin >> n;
    rep(i, 1, n-1) {
        int u, v;
        cin >> u >> v;
        g[u].PB(v);
        g[v].PB(u);
    }
    rep(i, 1, n) cin >> p[i];
}

void DFS(int u) {
    dd[u] = 1;
    tp[++id] = u;
    s[u] = id;
    for(int &v : g[u]) {
        if(dd[v]) continue;
        DFS(v);
    }
    f[u] = id;
}

void calc() {
    rep(i, 1, n) {
        int k = s[p[i]];
        int h = f[p[i]];
        int val = BIT.getAns(k);
        //val -= BIT.getAns(k-1);
        BIT.update(k, 1);
        BIT.update(h+1, -1);
        cout << val << '\n';
    }
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
