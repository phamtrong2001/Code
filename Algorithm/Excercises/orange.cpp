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
#define task "orange"
#define maxc 1000000007
#define maxn 1000005

using namespace std;

int n, a[maxn];

ll res = -maxc;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 0; i <= a[n]; i++)
    {
        int l = 0, r = n+1;
        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            if (a[mid] <= i) l = mid;
                else r = mid;
        }
        if (a[l] == i) res = max(res, 1ll*i*(n-l+1));
            else res = max(res, 1ll*i*(n-l));
    }
    cout << res;
    return 0;
}
