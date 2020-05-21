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
#define Task "watertree"
using namespace std;
struct IND {
    bool val, lazy;
};

struct SegmentTree {
    IND tree[maxn*6];

    void build(int l, int r, int node) {
        if(l == r) {
            tree[node].val = 1;
            tree[node].lazy = 0;
            return;
        }
        int mid = (r + l) >> 1;
        build(l, mid, node*2);
        build(mid+1, r, node*2+1);
        tree[node].val = 1;
        tree[node].lazy = 0;
    }

    void down(int node) {
        if(!tree[node].lazy) return;
        tree[node*2].val = tree[node*2+1].val = 0;
        tree[node*2].lazy = tree[node*2+1].lazy = 1;
        tree[node].lazy = 0;
    }

    void update(int l, int r, int node, int u, int v) {
        if(r < u || v < l) return;
        if(u <= l && r <= v) {
            tree[node].val = 0;
            tree[node].lazy = 1;
            return;
        }
        down(node);
        int mid = (r + l) >> 1;
        update(l, mid, node*2, u, v);
        update(mid+1, r, node*2+1, u, v);
        tree[node].val = tree[node*2].val | tree[node*2+1].val;
    }

    bool getAns(int l, int r, int node, int u, int v) {
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return tree[node].val;
        down(node);
        int mid = (r + l) >> 1;
        return getAns(l, mid, node*2, u, v) | getAns(mid+1, r, node*2+1, u, v);
    }

    void Del(int l, int r, int node, int u) {
        if(u < l || r < u) return;
        if(l == r) {
            tree[node].val = 1;
            return;
        }
        down(node);
        int mid = (r + l) >> 1;
        Del(l, mid, node*2, u);
        Del(mid+1, r, node*2+1, u);
        tree[node].val = tree[node*2].val | tree[node*2+1].val;
    }

} IT;

int n, s[maxn], f[maxn], id, prv[maxn], Q;
vector <int > g[maxn];
bool dd[maxn];

void setup() {
    scanf("%d", &n);
    rep(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].PB(v);
        g[v].PB(u);
    }
}

void DFS(int u) {
    dd[u] = 1;
    s[u] = ++id;
    for(int &v : g[u]) {
        if(dd[v]) continue;
        prv[v] = u;
        DFS(v);
    }
    f[u] = id;
}

void calc() {
    IT.build(1, n, 1);
    scanf("%d", &Q);
    while(Q--) {
        int type, u;
        scanf("%d%d", &type, &u);
        if(type == 1) {
            bool ok = IT.getAns(1, n, 1, s[u], f[u]);
            if(ok) {
                IT.update(1, n, 1, s[u], f[u]);
                if(prv[u]) {
                    IT.Del(1, n, 1, s[prv[u]]);
                }
            }
        } else if(type == 2) {
            IT.Del(1, n, 1, s[u]);
        } else {
            bool ok = IT.getAns(1, n, 1, s[u], f[u]);
            if(ok) printf("%d\n", 0);
            else printf("%d\n", 1);
        }
    }
}

int main() {
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    DFS(1);
    calc();
    return 0;
}
