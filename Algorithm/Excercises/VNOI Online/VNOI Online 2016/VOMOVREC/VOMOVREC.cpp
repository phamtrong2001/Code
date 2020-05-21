#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define ll long long
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1ll*100000000000007

using namespace std;

ll n, X1[N], X2[N], Y1[N], Y2[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("VOMOVREC.INP", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
    ll l = -1, r = maxc;
    while (r - l > 1)
    {
        ll mid = (r + l)/2;
        ll xmax = -maxc, xmin = maxc, ymax = -maxc, ymin = maxc;
        for (int i = 1; i <= n; i++)
        {
            xmax = max(xmax, X1[i] - mid);
            xmin = min(xmin, X2[i] + mid);
            ymax = max(ymax, Y1[i] - mid);
            ymin = min(ymin, Y2[i] + mid);
        }
        if (xmax < xmin && ymax < ymin) r = mid;
        else l = mid;
    }
    cout <<r;
}
