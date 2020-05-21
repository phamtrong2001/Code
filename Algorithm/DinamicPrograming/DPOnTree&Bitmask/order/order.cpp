// MR.J
#include<bits/stdc++.h>
#define maxn 16
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
#define Task "order"
using namespace std;
const int N = 70000;
int nho[N], dp[N], n, p[maxn], s[maxn][maxn];

void setup() {
    cin >> n;
    rep(i, 1, n)
        rep(j, 1, n) {
            if(i == j) cin >> p[i];
            else cin >> s[i][j];
        }
}

int calc(int x) {
    if(!x) return 0;
    if(nho[x]) return dp[x];
    nho[x] = 1;
    dp[x] = maxC;
    rep(i, 1, n) {
        int y;
        if((x >> (i - 1)) & 1) y = x ^ (1 << (i - 1));
        else continue;
        int t = calc(y) + p[i];
        rep(j, 1, n) {
            if((y >> (j - 1)) & 1) t += s[i][j];
        }
        dp[x] = min(dp[x], t);
    }
    return dp[x];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    cout << calc((1 << n) - 1);
    return 0;
}
