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
#define task "coffee"
#define maxc 1000000007
#define maxn 100005

using namespace std;

int n, res = -maxc, cur;

pii a[maxn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].F >> a[i].S;
    sort(a+1, a+n+1);
    cur = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i].F*60 + a[i].S < a[i-1].F*60 + a[i-1].S + 1) cur++;
            else cur = 1;
        res = max(res, cur);
    }
    cout << res;
    return 0;
}
