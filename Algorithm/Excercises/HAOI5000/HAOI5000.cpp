#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 2000005
#define maxc 1ll*1000000000000000007

using namespace std;

ll n, k, a[N], f[N], g[N], preF[N], nexG[N];
ll v[N], ans;
ll calcF(ll u, ll v)
{
    if (u < v) u += n;
    return f[u] - f[v] - abs(u-v)*preF[v];
}
ll calcG(ll u, ll v)
{
    if (v <= u) v += n;
    return g[u] - g[v] - abs(u-v)*nexG[v];
}

int main()
{
    freopen("INP.TXT", "r", stdin);
    //freopen("HAOI5000.INP", "r", stdin);
    cin >> n >> k;
    if (n == 1)
    {
        cout <<0<<endl<<1<<endl<<1;
        return 0;
    }
    for (ll i = 1; i <= k; i++)
    {
        ll x; cin >> x;
        a[x]++;
        a[x+n]++;
    }
    for (ll i = 1; i <= 2*n; i++)
    {
        f[i] = f[i-1] + preF[i-1];
        preF[i] = preF[i-1] + a[i];
    }
    for (ll i = 2*n; i >= 1; i--)
    {
        g[i] = g[i+1] + nexG[i+1];
        nexG[i] = nexG[i+1] + a[i];
    }
    ll res = maxc;
    for (ll i = 1; i <= n; i++)
    {
        int pos = (i + n/2) % n;
        if (pos == 0) pos = n;
        ll curAns = calcF(i, pos) + calcG(i, pos) + a[pos]*min(abs(i-pos), n-abs(i-pos));
        curAns = min(curAns, calcF(i, pos%n+1) + calcG(i, pos%n+1) + a[pos%n+1]*min(abs(i-pos%n-1), n-abs(i-pos%n-1)));

        if (curAns < res)
        {
            res = curAns;
            ans = 0;
            v[++ans] = i;
        }
        else if (curAns == res) v[++ans] = i;
    }
    cout <<res<<endl;
    cout <<ans<<endl;
    for (int i = 1; i <= ans; i++) cout <<v[i]<<" ";
}
