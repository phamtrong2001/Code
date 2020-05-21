// MR.J
#include <bits/stdc++.h>
#define maxn
#define maxC 1000000000
#define MOD 1000000007
#define F first
#define S second
#define pii pair <int, int>
#define mp make_pair
#define PB push_back
#define ll long long
#define rep(i, a, b) for(int i=(a) ; i<=(b) ; ++i)
#define repd(i, a, b) for(int i=(a) ; i>=(b) ; --i)
#define Task "tshirts"
using namespace std;
int Query, n;
bool b[105][15];
vector <int > a[105];
ll dp[1030][105];

int decode(string str) {
    stringstream ss;
    ss << str;
    int val;
    ss >> val;
    return val;
}

void setup() {
    string str, s;
    memset(dp, 0, sizeof dp);
    memset(b, 0, sizeof b);
    cin >> n;
    getline(cin, s);
    rep(i, 1, n) {
        getline(cin, s);
        stringstream ss (s);
        while(ss >> str) {
            b[decode(str)][i] = 1;
        }
    }
}

int getbit(int x, int i) {
    return (x >> i) & 1;
}

void prepare() {
    rep(i, 1, n)
        rep(j, 1, 100) dp[1 << (i - 1)][j] = b[j][i];
}

void calc() {
    rep(i, 0, (1 << n) - 1)
        rep(j, 1, 100) {
            dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            rep(p, 1, n) {
                if(!getbit(i, p-1) || !b[j][p]) continue;
                int y = i ^ (1 << (p - 1));
                dp[i][j] = (dp[i][j] + dp[y][j-1]) % MOD;
            }
        }
    cout << (dp[(1 << n) - 1][100] % MOD) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> Query;
    while(Query--) {
        setup();
        prepare();
        calc();
    }
    return 0;
}
