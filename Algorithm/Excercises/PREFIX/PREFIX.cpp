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

ll n, m, Z[N], a[N];
char c[N];
ll s[N], res[N];
pair<ll, char> S[N];
vector<pair<ll, ll> > all;
pair<ll, ll> p[N];

void Z_function()
{
    for (int i = 2; i <= n; i++) S[i-2] = mp(a[i], c[i]);
    int L = 0, R = 0;
    Z[0] = n-1;
    for (int i = 1; i < n-1; i++)
       if (i > R)
       {
          L = R = i;
          while (R < n-1 && S[R] == S[R - L]) R++;
          Z[i] = R - L; R--;
       }
       else
       {
          int k = i - L;
          if (Z[k] < R - i + 1) Z[i] = Z[k];
          else
          {
              L = i;
              while (R < n-1 && S[R] == S[R - L]) R++;
              Z[i] = R - L; R--;
          }
       }
    for (int i = n-2; i >= 0; i--) Z[i+2] = Z[i];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("PREFIX.INP", "r", stdin);
    freopen("PREFIX.OUT", "w", stdout);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) cin >> a[i], s[i] = s[i-1] + a[i];
    for (ll i = 1; i <= n; i++) cin >> c[i];
    Z_function();
    for (ll i = 3; i <= n; i++)
    {
        if (c[i-1] == c[1] && a[i-1] >= a[1])
        {
            ll st = s[i-1] - a[1] + 1;
            ll x = Z[i] + 2;
            ll y = i + Z[i];
            ll en = s[y-1];
            if (c[x] == c[y]) en += min(a[x], a[y]);
            all.PB(mp(st, en));
        }
    }
    sort(all.begin(), all.end());
    for (ll i = 1; i <= m; i++) cin >> p[i].F, p[i].S = i;
    sort(p+1, p+m+1);


    priority_queue<pair<ll, ll> > pri;
    ll j = 0;
    for (ll i = 1; i <= m; i++)
    {
        ll id = p[i].S;
        while (j < all.size() && all[j].F <= p[i].F)
        {
            pri.push(mp(-all[j].F, j));
            j++;
        }
        ll val = -1;
        while (!pri.empty())
        {
            pii x = pri.top();
            if (all[x.S].S < p[i].F) pri.pop();
            else
            {
                val = -x.F;
                break;
            }
        }
        if (val != -1) res[id] = p[i].F - val + 1;
        ll pos = lower_bound(s+1, s+n+1, p[i].F) - s;
        if (c[pos] == c[1] && pos != 1) res[id] = max(res[id], min(1ll*a[1], p[i].F-s[pos-1]));
        else if (c[pos] == c[1] && pos == 1) res[id] = max(res[id], 1ll*p[i].F-1);
    }
    for (ll i = 1; i <= m; i++) cout <<res[i]<<" ";
}
