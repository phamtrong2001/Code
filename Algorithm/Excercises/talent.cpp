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
#define task "talent"
#define maxc 1000000007
#define maxn 100005

using namespace std;

pii a[maxn];

int m, n;

ll sum[maxn], mul[maxn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i].F;
    for (int i = 1; i <= n; i++) cin >> a[i].S;
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + a[i].S;
        mul[i] = mul[i-1] + 1ll*a[i].F*a[i].S;
    }
    while (m--)
    {
        int p;
        cin >> p;
        int l = 0, r = n+1;
        while (r - l > 1)
        {
            int mid = (r + l) >> 1;
            if (a[mid].F < p) l = mid;
                else r = mid;
        }
        ll res = (sum[l]*2 - sum[n]) * p + mul[n] - mul[l]*2;
        cout << res << '\n';
    }
    return 0;
}
