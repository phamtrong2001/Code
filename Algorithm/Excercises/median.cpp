/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define pii pair<int, int>
#define PB push_back
#define MP make_pair
#define ll long long
#define F first
#define S second
#define task "median"
#define maxc 1000000007
#define maxn 500005

using namespace std;

ll n, a[maxn], b[maxn], k, dem = 0, dema = 0;

ll f[maxn], t[maxn];

ll res = 0;

void update(ll x)
{
    for(; x <= dema; x += x & (-x)) t[x]++;
}

ll get(ll x)
{
    ll pos = 0;
    for (; x; x -= x & (-x)) pos += t[x];
    return pos;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> k;
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i] = f[i-1] + (a[i] >= k);
        b[++dem] = 2*f[i] - i - 1;
        b[++dem] = 2*f[i-1] - i;
    }
    sort(b+1, b+dem+1);
    b[++dem] = maxc;
    for (int i = 1; i <= dem; i++)
        if (b[i] < b[i+1]) a[++dema] = b[i];
    for (int i = 1; i <= n; i++)
    {
        ll x = lower_bound(a+1, a+dema+1, 2*f[i-1] - i) - a;
        update(x);
        x = lower_bound(a+1, a+dema+1, 2*f[i] - i - 1) - a;
        res += get(x);
    }
    cout << res;
    return 0;
}
