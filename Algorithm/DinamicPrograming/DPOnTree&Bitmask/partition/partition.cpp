// MR.J
#include <bits/stdc++.h>
#define maxn 20
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
#define Task "partition"
using namespace std;
int sum[maxn][maxn], a[maxn][maxn], n, l = -1, r, k, luu[maxn], dem;

void setup() {
    cin >> n >> k;
    rep(i, 1, n)
        rep(j, 1, n) {
            cin >> a[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
}

int getbit(int x, int i) {
    return (x >> i) & 1;
}

bool calc(int state, int doc, int maxval) {
    int cut = 0;
    dem = 0;
    rep(i, 0, 18)
        if(getbit(state, i)) luu[++dem] = i + 1;
    int tr = 0;
    bool ok = 0;
    rep(i, 1, n) {
        int mval = -1;
        rep(j, 1, dem) {
            mval = max(mval, sum[luu[j]][i] - sum[luu[j]][tr] - sum[luu[j-1]][i] + sum[luu[j-1]][tr]);
        }
        mval = max(mval, sum[n][i] - sum[n][tr] - sum[luu[dem]][i] + sum[luu[dem]][tr]);
        if(mval > maxval) {
            if(!ok) return 0;
            ok = 0;
            ++cut;
            --i;
            tr = i;
        } else ok = 1;
    }
    return (cut <= doc);
}

bool check(int maxval) {
    int Lstate = (1 << (n - 1)) - 1;
    int doc;
    rep(ngang, 0, k) {
        rep(i, 0, Lstate) {
            int numbit = __builtin_popcount(i);
            if(numbit != ngang) continue;
            if(calc(i, k - ngang, maxval)) return 1;
        }
    }
    return 0;
}

void cnp() {
    r = sum[n][n] + 1;
    while(r - l > 1) {
        int mid = (r + l) >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    cnp();
    return 0;
}
