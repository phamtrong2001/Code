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
#define rep(i, a, b) for(ll i=(a) ; i<=(b) ; ++i)
#define repd(i, a, b) for(ll i=(a) ; i>=(b) ; --i)
#define Task "mclean"
using namespace std;
const ll N = (1 << 11) + 10;
const ll dx[4] = {0, 0, 1, -1};
const ll dy[4] = {1, -1, 0, 0};
ll n, m, dis[21][21][21][21], dem, top, bot, dd[21][21], fl;
ll dp[N][21];
char a[21][21];
pii pos, luu[12], s[22*22];

void setup() {
    cin >> n >> m;
    rep(i, 1, m)
        rep(j, 1, n) {
            cin >> a[i][j];
            if(a[i][j] == '*') luu[++dem] = mp(i, j);
            if(a[i][j] == 'o') pos = mp(i, j);
        }
    if(dem == 0)  {
        cout << 0;
        exit(0);
    }
}

void BFS(pii POS) {
    ++fl;
    int h = POS.F, k = POS.S;
    dis[h][k][h][k] = 0;
    bot = 1; top = 0;
    s[++top] = POS;
    while(bot <= top) {
        int u = s[bot].F;
        int v = s[bot++].S;
        rep(i, 0, 3) {
            int xx = u + dx[i];
            int yy = v + dy[i];
            if(a[xx][yy] == 'x' || dd[xx][yy] == fl || xx < 1 || yy < 1 || xx > m || yy > n) continue;
            dd[xx][yy] = fl;
            dis[h][k][xx][yy] = min(dis[h][k][xx][yy], dis[h][k][u][v] + 1);
            s[++top] = mp(xx, yy);
        }
    }
}

void prepare() {
    memset(dis, 0x32, sizeof dis);
    BFS(pos);
    rep(i, 1, dem) BFS(luu[i]);
}

ll getbit(ll x, ll i) {
    return (x >> i) & 1;
}

void check() {
    luu[++dem] = pos;
    rep(i, 1, dem) {
        ll ok = 0;
        rep(j, 1, dem) {
            if(i == j) continue;
            if(dis[luu[i].F][luu[i].S][luu[j].F][luu[j].S] > maxC*100) ++ok;
        }
        if(ok == dem - 1) {
            cout << -1;
            exit(0);
        }
    }
    --dem;
}

void calc() {
    memset(dp, 0x32, sizeof dp);
    rep(i, 1, (1 << dem) - 1) {
        ll bit = __builtin_popcount(i);
        if(bit == 1) {
            rep(kk, 1, dem) {
                if(i == (1 << (kk - 1))) {
                    dp[i][kk] = dis[pos.F][pos.S][luu[kk].F][luu[kk].S];
                    break;
                }
            }
            continue;
        }
        rep(j, 1, dem) {
            if(!getbit(i, j-1)) continue;
            ll y = i ^ (1 << (j - 1));

            rep(k, 1, dem) {
                if(k == j || !getbit(y, k-1)) continue;
                dp[i][j] = min(dp[i][j], dp[y][k] + dis[luu[k].F][luu[k].S][luu[j].F][luu[j].S]);
            }
        }
    }
    ll ans = 1ll*maxC*maxC;
    rep(i, 1, dem) {
        ans = min(ans, dp[(1 << dem) - 1][i]);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    prepare();
    check();
    calc();
    return 0;
}
