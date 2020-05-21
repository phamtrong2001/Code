// MR.J
#include<bits/stdc++.h>
#define maxn 21
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
#define Task "marriage"
using namespace std;
const ll N = (1 << 21) + 10;
ll dp[N][maxn], sc[N][maxn];
ll n, s[maxn][maxn];

void setup() {
    cin >> n;
    rep(i, 1, n)
        rep(j, 1, n) cin >> s[i][j];
}

ll getbit(ll st, ll i) {
    return ((st >> i) & 1);
}

void prepare() {
    rep(j, 1, n) {
        dp[1 << (j - 1)][1] = s[j][1];
        sc[1 << (j - 1)][1] = 1;
    }
}

void handling() {
    rep(i, 2, n) {
        rep(st, 0, (1 << n) - 1) {
            ll numbit = __builtin_popcount(st);
            if(numbit != i) continue;
            rep(j, 1, n) {
                if(!getbit(st, j-1)) continue;
                ll y = st ^ (1 << (j - 1));
                ll t = dp[y][i-1] + s[j][i];
                if(dp[st][i] < t) {
                    dp[st][i] = t;
                    sc[st][i] = sc[y][i-1];
                } else if(dp[st][i] == t) sc[st][i] += sc[y][i-1];
            }
        }
    }
    cout << dp[(1 << n) - 1][n] << ' ' << sc[(1 << n) - 1][n];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    prepare();
    handling();
    return 0;
}
