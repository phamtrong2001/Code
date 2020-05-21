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
#define Task "tytactic"
using namespace std;
int tp[maxn], s[maxn],  f[maxn], n, a[maxn], Query, id;
vector <int > g[maxn];
bool dd[maxn];
struct SegmentTree {
    int tree[maxn*6];

    void build(int l, int r, int node) {
        if(l == r) {
            tree[node] = a[tp[l]];
            return;
        }
        int mid = (r + l) >> 1;
        build(l, mid, node*2);
        build(mid+1, r, node*2+1);
        tree[node] = tree[node*2] + tree[node*2+1];
    }

    int getAns(int l, int r, int node, int u, int v) {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return tree[node];
        int mid = (r + l) >> 1;
        return getAns(l, mid, node*2, u, v) + getAns(mid+1, r, node*2+1, u, v);
    }

    void update(int l, int r, int node, int u, int val) {
        if(u < l || u > r) return;
        if(l == r) {
            tree[node] = val;
            return;
        }
        int mid = (r + l) >> 1;
        update(l, mid, node*2, u, val);
        update(mid+1, r, node*2+1, u, val);
        tree[node] = tree[node*2] + tree[node*2+1];
    }

} IT;

void setup() {
    cin >> n >> Query;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n-1) {
        int u, v;
        cin >> u >> v;
        g[u].PB(v);
        g[v].PB(u);
    }
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
    IT.build(1, n, 1);
    while(Query--) {
        char c;
        int S;
        cin >> c >> S;
        if(c == 'Q') {
            int u = s[S];
            int v = f[S];
            cout << IT.getAns(1, n, 1, u, v) << '\n';
        } else {
            int val;
            cin >> val;
            IT.update(1, n, 1, s[S], val);
        }
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
