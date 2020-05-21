#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 205
#define maxc 1000000007

using namespace std;

int n, x[N], y[N];
long long res;

ll get(int x1, int x2)
{
    ll ans = 1ll*(x2-x1)*(x2-x1);
    int ymin = maxc;
    int ymax = -maxc;
    for (int i = 1; i <= n; i++)
    {
        if (x1 <= x[i] && x[i] <= x2) continue;
        int Y = y[i];
        if (x1 != maxc) ans = max(ans, max(1ll*x1*x1, 1ll*x2*x2) + 1ll*Y*Y);
        ymax = max(ymax, Y);
        ymin = min(ymin, Y);
    }
    if (ymax != -maxc) ans = max(ans, 1ll*(ymax-ymin)*(ymax-ymin));
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("FLOWER.INP", "r", stdin);
    freopen("FLOWER.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];

    res = get(maxc, maxc);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (x[i] <= x[j])
                res = min(res, get(x[i], x[j]));
    cout <<res;
}
