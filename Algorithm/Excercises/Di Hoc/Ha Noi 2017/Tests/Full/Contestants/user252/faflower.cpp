#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
#define Tpair pair <int, int>
using namespace std;

typedef long long ll;
const int   oo = 1e9 + 1;
const int  mod = 1e9 + 7;
const int maxn = 1e5 + 5;

ll n, t, dp[42000001], flag[1500001][41], Cky, Start, End, res;
char a[21][21];
vector <int> v[21];
bitset <21> state, f[21];

void Init()
{
    cin >> n >> t;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            if (a[i][j] == '1')
            {
                v[i].push_back(j);
                f[i][j - 1] = 1;
            }
        }
}

void Print (bitset <21> x) {
    for (int i = 0; i < n; ++i) cout << x[i]; cout << endl;
}

void Solve()
{
    //for (int i = 1; i <= n; ++i) Print(f[i]);
    for (int j : v[1]) {
        state[j - 1] = 1; dp[1]++;
    }
    //Print(state); //cout << dp[1] << endl;

    ll x = state.to_ulong();
    flag[x][dp[1]] = 1;
    // le bit 1, chan bit 0;
    for (int i = 2;; ++i)
    {
        bitset <21> newstate;
        for (int j = 1; j <= n; ++j)
        {
            int u = ((state & f[j]).count());
            int t = (int)v[j].size() - u;
            dp[i] += u + t * 2;
            if ((u + t * 2) % 2) newstate[j - 1] = 1;
        }
        state = newstate;
        ll x = state.to_ulong();

        //cout << i << " " << dp[i] << " "; Print(state);

        if (flag[x][dp[i]]) {
            Cky = i - flag[x][dp[i]];
            Start = flag[x][dp[i]];
            End = i - 1;
            break;
        }
        else flag[x][dp[i]] = i;

    }
    //cout << endl << Cky << " " << Start << " " << End << endl;

    if (End >= t) {
        for (int i = 1; i <= t; ++i) res += dp[i];
        cout << res; return;
    }

    else {
        for (int i = 1; i < Start; ++i) res += dp[i];
        t -= Start - 1;

        ll sumCky = 0;
        for (int i = Start; i <= End; ++i) sumCky += dp[i];

        ll d = t / Cky; res += d * sumCky;
        ll r = t % Cky;
        for (int i = Start; i <= Start + r - 1; ++i) res += dp[i];
    }
    cout << res;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("faflower.inp", "r", stdin);
    freopen("faflower.out", "w", stdout);

	Init();
	Solve();
}
//Date 5 Month 12 Year 2017



