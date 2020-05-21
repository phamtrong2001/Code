#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

ll q, dp[11][105][2000];

string convert(ll base, ll x)
{
    string aa = "";
    while (x)
    {
        aa = (char)(x % base + '0') + aa;
        x /= base;
    }
    return aa;
}
ll get(ll base, ll x)
{
    string s = convert(base, x);
    //cerr<<s<<endl;
    ll len = s.size(); s = "#" + s;

    ll ans = 0;
    for (ll i = 2; i < len; i++)
        ans += (dp[base][i][0] - dp[base][i-1][1]);
    ll cur = 0;
    for (ll i = len; i >= 1; i--)
    {
        char c = s[i] - '0'; if (i == 1) c++;
        for (ll j = 0; j < c; j++)
        {
            if (i == 0 && j == 0) continue;
            ll cur1 = cur ^ (1 << j);
            ans += dp[base][len-1][cur1];
        }
        cur ^= (1 << c);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    cin >> q;
    for (ll base = 2; base <= 10; base++)
    {
        dp[base][0][0] = 1;
        for (ll len = 1; len <= 100; len++)
            for (ll x = 0; x < (1 << base); x++)
                for (ll i = 0; i < base; i++)
                {
                    ll y = x ^ (1 << i);
                    dp[base][len][y] += dp[base][len-1][x];
                }
    }
    while (q--)
    {
        ll b, l, r;
        cin >> b >> l >> r;
        for (int i = 1; i <= r; i++) cout <<convert(b, i)<<endl;
        cout <<get(b, r) - get(b, l-1)<<'\n';
    }
}
