#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 25
#define maxc 1000000007

using namespace std;

ll n, h, heigh[N], weigh[N], health[N], dp[1 << N], ok[1 << N];

bool bit(ll x, ll i) {return (x >> i) & 1;}
int main()
{
    freopen("MGUARD.INP", "r", stdin);
    freopen("MGUARD.OUT", "w", stdout);
    cin >> n >> h;
    for (ll i = 0; i < n; i++) cin >> heigh[i] >> weigh[i] >> health[i];

    ll res = -1;
    ok[0] = 1; dp[0] = maxc;
    for (ll x = 1; x < (1 << n); x++)
    {
        ll sumW = 0, sumH = 0;
        for (ll i = 0; i < n; i++)
            if (bit(x, i)) sumW += weigh[i], sumH += heigh[i];
        for (ll i = 0; i < n; i++)
            if (bit(x, i) && health[i] >= sumW - weigh[i] && ok[x ^ (1 << i)])
            {
                ok[x] = 1;
                dp[x] = max(dp[x], min(health[i] - sumW + weigh[i], dp[x ^ (1 << i)]));
            }
        if (sumH >= h && ok[x]) res = max(res, dp[x]);
    }
    if (res == -1) cout <<"Mark is too tall";
    else cout <<res;
}
