#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 5000005
#define skip skipskipskipskipskipskip

using namespace std;

int n, a[N], dd[N];
int main()
{
    // dmmm t skip
    // hay cho t skip
    // dmm codeforces
    // suc vat codeforces
    cin >> n;
    for (int i = 1; i <= 2*n; i++)
    {
        cin >> a[i];
        dd[a[i]] = 1;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = n+1; j <= 2*n; j++) res += dd[a[i]^a[j]];
    if (res % 2 == 0) cout <<"Karen";
    else cout <<"Koyomi";
}
