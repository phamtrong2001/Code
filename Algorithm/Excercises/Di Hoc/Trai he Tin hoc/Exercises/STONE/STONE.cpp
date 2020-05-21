#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, k, a[N], dp[N], dem2[N], dem[N];
bool flag;
void nhap()
{
    memset(dp, 0, sizeof dp);
    memset(dem2, 0, sizeof dem2);
    memset(dem, 0, sizeof dem);
    cin >> n >> k;
    for (int i = 1; i <= k; i++) cin >> a[i];
    sort(a+1, a+k+1);
    for (int i = 1; i <= k; i++) if (a[i] != i) flag = 1;
}

void sub1()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (a[j] > i) break;
            dem[i]++;
            dem2[i] += dp[i-a[j]];
        }
        if (dem2[i] == dem[i] || dem[i] == 0) dp[i] = 0;
        else dp[i] = 1;
    }
    if (dp[n]) cout <<"YES"<<endl; else cout <<"NO"<<endl;
}
void sub2()
{
    if ((n % (k+1))) cout <<"YES"<<endl;
    else cout <<"NO"<<endl;
}
int main()
{
    IOS
    freopen("STONE.INP", "r", stdin);
    freopen("STONE.OUT", "w", stdout);
    int t; cin >> t;
    while (t--)
    {
        nhap();
        if (flag) sub1();
        //else sub2();
    }
}
