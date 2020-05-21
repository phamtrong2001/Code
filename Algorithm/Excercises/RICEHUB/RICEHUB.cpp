#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define ll long long
#define maxc 1000000007

using namespace std;

ll n, xmax, b, x[N], s[N], res;

ll calc(ll u, ll v)
{
    ll mid = (u + v)/2;
    ll res = x[mid]*(mid - u + 1) - (s[mid] - s[u-1]);
    res += (s[v] - s[mid-1]) - x[mid]*(v - mid + 1);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> xmax >> b;
    for (ll i = 1; i <= n; i++)
    {
        cin >> x[i];
        s[i] = s[i-1] + x[i];
    }
    ll j = 1;
    for (ll i = 1; i <= n; i++)
    {
        while (j <= i && calc(j, i) > b) j++;
        res = max(res, i-j+1);
    }
    cout <<res;
}
