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
#define Task "ctree"
using namespace std;
int n, prv[maxn], s[maxn], f[maxn], tp[maxn], dp1[maxn], dp1a[maxn], dp2[maxn], id;
vector <int > g[maxn];
bool dd[maxn];
int luu[maxn], dem;

void setup() {
    cin >> n;
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
    for(int &v : g[u])  {
        if(dd[v]) continue;
        prv[v] = u;
        DFS(v);
    }
}

void calc1() {
    repd(i, n, 1) {
        int u = tp[i];
        for(int &v : g[u]) {
            if(prv[v] != u) continue;
            if(dp1[u] < dp1[v] + 1) {
                dp1a[u] = dp1[u];
                dp1[u] = dp1[v] + 1;
            } else if(dp1a[u] < dp1[v] + 1) {
                dp1a[u] = dp1[v] + 1;
            }
        }
    }
}

void calc2() {
    rep(i, 1, n) {
        int u = tp[i];
        int w = prv[u];
        if(w) {
            dp2[u] = dp2[w] + 1;
            if(dp1[u] + 1 == dp1[w]) {
                dp2[u] = max(dp2[u], dp1a[w] + 1);
            } else dp2[u] = max(dp2[u], dp1[w] + 1);
        }
    }
}

void handling() {
    int res = maxC;
    rep(i, 1, n) {
        if(res > max(dp1[i], dp2[i])) {
            res = max(dp1[i], dp2[i]);
            dem = 0;
            luu[++dem] = i;
        } else if(res == max(dp1[i], dp2[i])) luu[++dem] = i;
    }
    cout << dem << '\n';
    rep(i, 1, dem) cout << luu[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    DFS(1);
    calc1();
    calc2();
    handling();
    return 0;
}
