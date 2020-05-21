#include <bits/stdc++.h>

#define ff(i,a,b)       for(int i=(a), _b=(b); i<=_b; ++i)
#define gg(i,a,b)       for(int i=(a), _b=(b); i>=_b; --i)
#define REP(i, b)       for(int i=(0), _b=(b); i< _b; ++i)
#define endl            '\n'
#define long            long long
#define Love(x)         {cerr << #x <<" = "<< x << endl; }
#define _               << "," <<
#define BIT(i,t)        ( ((t)>>(i)) & 1)
#define ALL(v)          v.begin(), v.end()
#define X               first
#define Y               second

#define NAME            "FAFLOWER"

using namespace std;
const int N = 20;
typedef pair<int, int> ii;

int n, a[N], BFF[N], sum[1<<N], Next[1<<N], cnt[1<<N];
long T, MAP[1<<N];

void Enter() {
    cin >> n >> T;
    REP(i, n) {
        char c;
        REP(j, n) cin >> c, a[i] += (c-'0') << j;
        REP(j, n) BFF[i] = __builtin_popcount(a[i]);
    }
}

void to2(int x){
    REP(i, n) cout << BIT(i,x);
    cout << endl;
}

void Init() {
    REP(t, 1<<n) {
        int cur = 0;
        REP(i, n) {
            sum[t] += (BIT(i,t) ? 1 : 2) * BFF[i];
            if (BIT(i,t)) {
                cur ^= a[i];
            }
        }
        Next[t] = cur;
    }
}

void Trau() {
    int cur = a[0];
    int t = T, res = BFF[0];
    for (; t > 0; --t) {
        int tmp = Next[cur];
        res += sum[cur];
        cur = tmp;
        Love(tmp _ res)
    }
    cout << res << endl;
}

void Process() {
    Init();
    int cur = a[0];
    long Total = BFF[0];
    MAP[cur] = Total;
    cnt[cur] = 1;
    --T;

    //Trau();

    for (; T > 0; --T) {
        int tmp = Next[cur];
        //Love("cur"); to2(cur);
        //Love("tmp ====="); to2(tmp);
        if (!cnt[tmp]) {
            cnt[tmp] = cnt[cur] + 1; //Love(cnt[tmp])
            MAP[tmp] = MAP[cur] + sum[cur];
            Total += sum[cur];
        }
        else {
            long cir = cnt[cur] + 1 - cnt[tmp];
            long loop = T / cir; //Love(cir)
            Total += loop * (MAP[cur] + sum[cur] - MAP[tmp]) + sum[cur];
            T %= cir;
            fill_n(MAP, 1<<N, 0);
            fill_n(cnt, 1<<N, 0);
        }
        cur = tmp;
    }

    cout << Total << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(NAME".inp", "r", stdin);
    freopen(NAME".out", "w", stdout);
    Enter();
    Process();
}
