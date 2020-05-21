// MR.J
#include <bits/stdc++.h>
#define maxn 1005
#define F first
#define S second
#define maxC 1000000000
#define MOD 1000000007
#define pii pair <int, int>
#define mp make_pair
#define PB push_back
#define Task "design"
#define ll long long
using namespace std;
int n, m;
int canKhop[maxn][maxn];
ll dp[maxn][maxn], res = 0;
vector <vector<pii> > state;

void getState(vector<pii> p, int valm) {
    if(valm == m) {
        state.PB(p); return;
    }
    for(int i=1 ; i<=m-valm ; ++i)
        for(int j=1 ; j<=i ; ++j) {
            p.PB(mp(i, j));
            getState(p, valm + i);
            p.erase(p.end());
        }
}

int check(vector <pii> duoi, vector<pii> tren) {
    int u = 1, v = 1, i = 0, j = 0;
    while(u <= m) {
        while(u <= m && tren[i].F == tren[i].S && i < tren.size()) u += tren[i++].F;
        while(v <= m && duoi[j].S == 1 && j < duoi.size()) v += duoi[j++].F;
        if(u != v) return 0;
        if(u <= m) {
            if(tren[i].F != duoi[j].F) return 0;
            if(tren[i].S + 1 != duoi[j].S) return 0;
            u += tren[i++].F; v += duoi[j++].F;
        }
    }
    return 1;
}

void prepare() {
    vector <pii> p;
    p.clear(); state.clear();
    getState(p, 0);
    memset(dp, 0, sizeof dp);
    memset(canKhop, 0, sizeof canKhop);
    for(int i=0 ; i<state.size() ; ++i)
        for(int j=0 ; j<state.size() ; ++j)
            canKhop[i][j] = check(state[i], state[j]);
}

int okVect(vector <pii> p) {
    for(int i=0 ; i<p.size() ; ++i)
        if(p[i].F != p[i].S) return 0;
    return 1;
}

void calc() {
    dp[0][0] = 1;
    for(int i=1 ; i<=n ; ++i)
        for(int j=0 ; j<state.size() ; ++j)
            for(int k=0 ; k<state.size() ; ++k)
                dp[i][j] = (dp[i][j] + dp[i-1][k] * 1ll *  canKhop[j][k]) % MOD;

    for(int i=0 ; i<state.size() ; ++i)
        res = (res + dp[n][i] * okVect(state[i])) % MOD;
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> m;
    prepare();
    calc();
    return 0;
}
