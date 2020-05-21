#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define ll long long
#define maxc 1000000007
#define ZZ j2][j3][j5][j7
#define ZZZ u2][u3][u5][u7

using namespace std;

ll n, sum[20][500005], dp[20][500005][10], a, b, res, tt, dd[60][45][30][30];
map<pair<pii, pii>, ll> ma;

ll getId(ll u1, ll u2, ll u3, ll u4)
{
    if (!dd[u1][u2][u3][u4]) dd[u1][u2][u3][u4] = ++tt;
    return dd[u1][u2][u3][u4];
}
void prepare()
{
    sum[0][getId(0, 0, 0, 0)] = 1;
    for (ll i = 1; i <= 18; i++)
    {
        ll cur = 1;
        for (ll j2 = 0; j2 < 61; j2++)
        {
            if (b/cur < 2 && j2) break;
            if (j2) cur *= 2;
            ll save2 = cur;
            for (ll j3 = 0; j3 < 39; j3++)
            {
                if (b / cur < 3 && j3)
                {
                    cur = save2;
                    break;
                }
                if (j3) cur *= 3;
                ll save3 = cur;
                for (ll j5 = 0; j5 < 27; j5++)
                {
                    if (b / cur < 5 && j5)
                    {
                        cur = save3;
                        break;
                    }
                    if (j5) cur *= 5;
                    ll save5 = cur;
                    for (ll j7 = 0; j7 < 23; j7++)
                    {
                        if (b / cur < 7 && j7)
                        {
                            cur = save5;
                            break;
                        }
                        if (j7) cur *= 7;
                        ll id = getId(j2, j3, j5, j7);
                        dp[i][id][1] += sum[i-1][id];
                        if (j2) dp[i][id][2] += sum[i-1][getId(j2-1, j3, j5, j7)];
                        if (j3) dp[i][id][3] += sum[i-1][getId(j2, j3-1, j5, j7)];
                        if (j2 > 1) dp[i][id][4] += sum[i-1][getId(j2-2, j3, j5, j7)];
                        if (j2 && j3) dp[i][id][6] += sum[i-1][getId(j2-1, j3-1, j5, j7)];
                        if (j5) dp[i][id][5] += sum[i-1][getId(j2, j3, j5-1, j7)];
                        if (j7) dp[i][id][7] += sum[i-1][getId(j2, j3, j5, j7-1)];
                        if (j2 > 2) dp[i][id][8] += sum[i-1][getId(j2-3, j3, j5, j7)];
                        if (j3 > 1) dp[i][id][9] += sum[i-1][getId(j2, j3-2, j5, j7)];
                        for (ll c = 1; c <= 9; c++)
                            sum[i][id] += dp[i][id][c];
                    }
                }
            }
        }
    }
}
string convert(ll X)
{
    string ans;
    stringstream ss;
    ss << X;
    ss >> ans;
    return ans;
}
ll get(ll X, ll u2, ll u3, ll u5, ll u7)
{
    string s = convert(X);
    ll len = s.size(); s = "#" + s;
    ll res = 0;
    ll id = getId(u2, u3, u5, u7);
    for (ll i = 1; i < len; i++)
        res += sum[i][id];
    for (ll i = 1; i <= len; i++)
    {
        ll x = s[i] - '0';
        for (ll j = 1; j < s[i] - '0'; j++)
        {
            ll y = j;
            ll v2 = u2, v3 = u3, v5 = u5, v7 = u7;
            while (y % 2 == 0) {y /= 2; v2--;}
            while (y % 3 == 0) {y /= 3; v3--;}
            while (y % 5 == 0) {y /= 5; v5--;}
            while (y % 7 == 0) {y /= 7; v7--;}
            if (v2 >= 0 && v3 >= 0 && v5 >= 0 && v7 >= 0)
                res += dp[len-i+1][id][j];
        }
        if (x)
        {
            while (x % 2 == 0) {x /= 2; u2--;}
            while (x % 3 == 0) {x /= 3; u3--;}
            while (x % 5 == 0) {x /= 5; u5--;}
            while (x % 7 == 0) {x /= 7; u7--;}
        }
        else break;
        if (u2 < 0 || u3 < 0 || u5 < 0 || u7 < 0) break;
        id = getId(u2, u3, u5, u7);
    }
    bool flag = 0;
    for (int i = 1; i <= len; i++)
        if (s[i] == '0') flag = 1;
    if (!u2 && !u3 && !u5 && !u7 && !flag) res++;
    return res;
}


ll poww(ll x, ll y)
{
    if(y == 1) return x;
    ll ans = poww(x, y/2);
    if(y % 2) return ans * ans * x;
    return ans * ans;
}

ll solve(ll b)
{
    ll res = 0;
    if (b == 0) return 0;
    ll cur = 1;
    for (ll j2 = 0; j2 < 61; j2++)
    {
        if (j2 && b / cur <= 2) break;
        if (j2) cur *= 2;
        ll save2 = cur;
        for (ll j3 = 0; j3 < 39; j3++)
        {
            if (j3 && 1.*b / cur < 3.)
            {
                cur = save2;
                break;
            }
            if (j3) cur *= 3;
            ll save3 = cur;
            for (ll j5 = 0; j5 < 27; j5++)
            {

                if (j5 && 1.*b / cur < 5.)
                {
                    cur = save3;
                    break;
                }
                if (j5) cur *= 5;
                ll save5 = cur;
                for (ll j7 = 0; j7 < 23; j7++)
                {

                    if (j7 && 1.*b / cur < 7.)
                    {
                        cur = save5;
                        break;
                    }
                    if (j7) cur *= 7;
                    ll z = b/cur;
                    if (z) res += get(z, j2, j3, j5, j7);
                }
            }
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("DIGITPRD.INP", "r", stdin);
    //freopen("DIGITPRD.OUT", "w", stdout);
    cin >> a >> b; a--;
    prepare();
    res = solve(b);
    res -= solve(a);
    cout <<res;
}
