#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define ll long long
#define PB push_back
#define N 100005
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

ll n, k, a[N], cnt[N], luu[N], curres, sl, cou;
vector<ll> all;
ll dp[N][100];
map<ll, ll> dd;
void nhap()
{
    cin >> n >> k;
    for (ll i = 1; i <= n; i++) cin >> a[i];
}
void prepare()
{
    all.PB(1);
    for (ll i = 2; i <= sqrt(k); i++)
    {
        if (k % i == 0)
        {
            all.PB(i); cou++;
            while (k % i == 0) {cnt[cou]++; k /= i;}
        }
    }
    if (k > 1)
    {
        if (!dd[k])
        {
            all.PB(k);
            dd[k] = ++cou;
        }
        ll id = dd[k];
        cnt[id]++;
    }
    sl = all.size()-1;
    for (int i = 1; i <= n; i++)
    {
        int x = a[i];
        for (int j = 1; j <= sl; j++)
        {
            while (x % all[j] == 0) {x /= all[j]; dp[i][j]++;}
        }
    }
}

void add(ll id)
{
    for (ll i = 1; i <= sl; i++)
    {
        if (luu[i] >= cnt[i]) curres--;
        luu[i] += dp[id][i];
        if (luu[i] >= cnt[i]) curres++;
    }
}
void rem(ll id)
{
    for (ll i = 1; i <= sl; i++)
    {
        if (luu[i] >= cnt[i]) curres--;
        luu[i] -= dp[id][i];
        if (luu[i] >= cnt[i]) curres++;
    }
}
void solve()
{
    ll j = 1; ll res = 0;
    for (ll i = 1; i <= n; i++)
    {
        while (curres < sl && j <= n)
            add(j++);
        j = max(j, i+1);
        if (curres == sl) res += (n - j + 2);
        rem(i);
    }
    cout <<res;
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    nhap();
    prepare();
    solve();

}
