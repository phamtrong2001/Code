// MR.J
#include<bits/stdc++.h>
#define maxn 21
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
#define Task "mguard"
using namespace std;
const int N = 1 << 21;
struct cow {
    int cao, nang, khoe;
} a[maxn];
int n, h;
ll ans, hig[N], kl[N], add[N];

void setup() {
    cin >> n >> h;
    rep(i, 1, n) cin >> a[i].cao >> a[i].nang >> a[i].khoe;
}

int getbit(int x, int i) {
    return (x >> i) & 1;
}

void handling() {
    rep(i, 1, n) add[1 << (i - 1)] = a[i].khoe;
    rep(x, 0, (1 << n) - 1) {
        rep(j, 1, n) {
            if(getbit(x, j-1)) continue;
            int y = x + (1 << (j - 1));
            hig[y] = hig[x] + a[j].cao;
            kl[y] = kl[x] + a[j].nang;
            add[y] = max(add[y], min(add[x], a[j].khoe - kl[x]));
            if(hig[y] >= h) ans = max(ans, add[y]);
        }
    }
    if(ans) cout << ans;
    else cout << "Mark is too tall";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    handling();
    return 0;
}
