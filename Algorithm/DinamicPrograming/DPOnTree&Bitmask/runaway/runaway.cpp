// MR.J
#include<bits/stdc++.h>
#define maxn 200005
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
#define Task "runaway"
using namespace std;
int n, par[maxn][18];
ll L, ans[maxn], d[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    ans[1] = 1;
    cin >> n >> L;
    rep(i, 2, n) {
        cin >> par[i][0] >> d[i];
        d[i] += d[par[i][0]];
        rep(j, 1, 18)
            par[i][j] = par[par[i][j-1]][j-1];
        int v = i;
        repd(j, 18, 0)
            if(d[i] - d[par[v][j]] <= L) v = par[v][j];
        ++ans[i];
        --ans[par[v][0]];
    }
    repd(i, n, 1)
        ans[par[i][0]] += ans[i];
    rep(i, 1, n) cout << ans[i] << '\n';
    return 0;
}
