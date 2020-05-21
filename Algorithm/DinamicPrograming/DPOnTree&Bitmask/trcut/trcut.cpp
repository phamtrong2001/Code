// MR.J
#include<bits/stdc++.h>
#define maxn 500005
#define maxC 1000000000
#define MOD 1000000007
#define mp make_pair
#define PB push_back
#define F first
#define S second
#define pii pair<ll, ll>
#define ll long long
#define rep(i, a, b) for(ll i=(a) ; i<=(b) ; ++i)
#define repd(i, a, b) for(ll i=(a) ; i>=(b) ; --i)
#define Task "trcut"
using namespace std;
ll n, tp[maxn], id, k, a[maxn], prv[maxn], f[maxn];
vector <ll > g[maxn];
ll l, r;
bool dd[maxn];

void setup() {
    scanf("%lld%lld", &n, &k);
    rep(i, 1, n) {
        scanf("%lld", &a[i]);
        l = max(l, 1ll*a[i]);
        r += a[i];
    }
    rep(i, 1, n-1) {
        ll u, v;
        scanf("%lld%lld", &u, &v);
        g[u].PB(v);
        g[v].PB(u);
    }

}

void DFS(ll u) {
    dd[u] = 1;
    tp[++id] = u;
    for(ll &v : g[u]) {
        if(dd[v]) continue;
        prv[v] = u;
        DFS(v);
    }
}

bool check(ll T) {
    ll dem = 0;
    repd(i, n, 1) {
        priority_queue <ll > p;
        ll u = tp[i];
        f[u] = a[u];
        for(ll &v : g[u]) {
            if(prv[v] != u) continue;
            f[u] += f[v];
            p.push(f[v]);
        }
        while(f[u] > T) {
            ++dem;
            f[u] -= p.top();
            p.pop();
        }
    }
    return (dem <= k);
}

void handling() {
    --l;
    while(r - l > 1) {
        ll mid = (r + l) >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    printf("%lld", r);
}

int main() {
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    DFS(1);
    handling();
    return 0;
}
