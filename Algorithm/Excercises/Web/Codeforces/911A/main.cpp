#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n;
pii a[N];

int main()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        a[i] = mp(x, i);
    }
    sort(a+1, a+n+1);
    int res = n+1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i].F != a[1].F) break;
        res = min(res, a[i].S - a[i-1].S);
    }
    cout <<res;
}
