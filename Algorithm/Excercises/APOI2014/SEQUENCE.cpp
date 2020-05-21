#include <bits/stdc++.h>
#define N 100005
#define PB push_back
#define ll long long

using namespace std;

int n, k, trace[205][N];
ll s[N], dp[N], poller;
vector <long long > v, u, vl, ul, p, pl;
bool check(ll x, ll y, ll z)
{
    return (v[z] - v[x])*(u[x] - u[y]) <= (v[y] - v[x])*(u[x] - u[z]);
}
void add(ll x, ll y, ll vt)
{
    u.PB(x);
    v.PB(y);
    p.PB(vt);
    while (u.size() >= 3 && check(u.size()-3, u.size()-2, u.size()-1))
    {
        u.erase(u.end()-2);
        v.erase(v.end()-2);
        p.erase(p.end()-2);
    }
}
ll get(ll x, ll val)
{
    return ul[x]*val+vl[x];
}
ll get_ans(ll val)
{
    if (poller >= ul.size()) poller = ul.size()-1;
    while (poller < ul.size()-1 && get(poller+1, val) >= get(poller, val)) poller++;
    return get(poller, val);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("SEQUENCE.INP", "r", stdin);
    freopen("SEQUENCE.OUT", "w", stdout);
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] += s[i-1];
    }
    for (ll i = 1; i <= n; i++)
    {
        dp[i] = s[i]*(s[n] - s[i]);
        add(s[i], dp[i] - s[i]*s[n], i);
    }
    swap(ul, u); swap(vl, v); swap(pl, p);
    for (ll i = 2; i <= k; i++)
    {
        poller = 0;
        for (ll j = i; j <= n; j++)
        {
            dp[j] = get_ans(s[j]) + s[j]*s[n] - s[j]*s[j];
            trace[i][j] = pl[poller];
            add(s[j], dp[j] - s[j]*s[n], j);
        }
        swap(ul, u); swap(vl, v); swap(pl, p);
        u.clear();
        v.clear();
        p.clear();
    }
    ll res = -1; ll pos = 0; ll dem = k;
    for (ll i = 1; i <= n; i++)
        if (res <= dp[i])
        {
            res = dp[i];
            pos = i;
        }
    cout <<res<<endl;
    vector<ll> ans;
    while (dem > 0)
    {
        ans.PB(pos);
        pos = trace[dem--][pos];
    }
    sort(ans.begin(), ans.end());
    for (ll &v : ans) cout <<v<<" ";
}
