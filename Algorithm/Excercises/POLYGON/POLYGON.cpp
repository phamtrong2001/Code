#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 202
#define maxc 1000000007

using namespace std;

int n, dp[N][N];
pii a[N], tr[N][N], ans;

bool cmp(pii p, pii q)
{
    int u = p.F*p.F*(q.F*q.F + q.S*q.S);
    int v = q.F*q.F*(p.F*p.F + p.S*p.S);
    if (u != v) return u > v;
    return p.F < q.F;
}
int CCW(pii p1, pii p2, pii p3)
{
    return (p2.F - p1.F)*(p3.S - p1.S) - (p2.S - p1.S)*(p3.F - p1.F);
}
int main()
{
    freopen("POLYGON.INP", "r", stdin);
    freopen("POLYGON.OUT", "w", stdout);
    cin >> n;
    a[0] = mp(0, 0);
    for (int i = 1; i <= n; i++) cin >> a[i].F >> a[i].S;
    sort(a+1, a+n+1, cmp);

    int res = 3;
    //dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
        tr[i][0] = mp(0, 0);
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = -maxc;
            for (int k = 0; k < j; k++)
                if (CCW(a[k], a[j], a[i]) > 0 && dp[j][k] + 1 > dp[i][j])
                {
                    dp[i][j] = dp[j][k] + 1;
                    tr[i][j] = mp(j, k);
                }


            if (CCW(a[j], a[i], a[0]) > 0 && dp[i][j] + 1 > res)
            {
                res = dp[i][j] + 1;
                ans = mp(i, j);
            }
        }
    }
    cout <<res<<endl;
    while (ans != mp(0, 0))
    {
        cout <<a[ans.F].F<<" "<<a[ans.F].S<<endl;
        ans = tr[ans.F][ans.S];
    }
    cout <<0<<" "<<0;
}
