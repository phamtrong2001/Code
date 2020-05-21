#include <bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;

ll t, n, s[N], a[N];
long long get(ll l, ll r)
{
    if (l == r) return 0;
    ll sum = s[r] - s[l-1];
    ll mid = lower_bound(s+l, s+r+1, s[l-1] + sum/2) - s;
    if (mid - 1 >= l && abs(sum/2 - (s[mid] - s[l-1])) > abs(sum/2 - (s[mid-1] - s[l-1]))) mid--;
    return get(l, mid) + get(mid+1, r) + sum;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (ll i = 1; i <= n; i++) cin >> a[i], s[i] = s[i-1] + a[i];
        cout << get(1, n)<<endl;
    }
}
