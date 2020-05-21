#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define N 200005


using namespace std;

int n, res[N];
pii skipa[N], skipb[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> skipa[i].first, skipa[i].second = i;
    for (int i = 1; i <= n; i++) cin >> skipb[i].first, skipb[i].second = i;
    sort(skipa+1, skipa+n+1);
    sort(skipb+1, skipb+n+1);
    reverse(skipb+1, skipb+n+1);
    for (int i = 1; i <= n; i++) res[skipb[i].second] = skipa[i].first;
    for (int i = 1; i <= n; i++) cout <<res[i]<<" ";
}
