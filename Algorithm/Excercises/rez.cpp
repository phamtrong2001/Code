/******** Kho kinh nguoi ********/
#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 200005
#define task "rez"

using namespace std;

int n;

long long m[maxn], c[maxn];

pair <int, int> a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].S >> a[i].F;
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
        c[i] = a[i].F - a[i].S;
    m[1] = c[1];
    for (int i = 2; i <= n; i++)
    {
        int j = upper_bound(a+1, a+n+1, MP(a[i].S, maxc)) - a - 1;
        c[i] += m[j];
        /*int l = 0;
        int r = i;
        while (r - l > 1)
        {
            int mid = (l+r) >> 1;
            if (a[mid].F <= a[i].S) l = mid;
                else r = mid;
        }
        c[i] += m[l];*/
        m[i] = max(m[i-1], c[i]);
    }
    cout << m[n];
    return 0;
}
