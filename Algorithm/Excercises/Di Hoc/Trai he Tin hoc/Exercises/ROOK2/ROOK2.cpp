#include <bits/stdc++.h>
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 90
#define mod 1000001
#define ll long long

using namespace std;

int t, n, m, k;
int dd[N][N][N][N], dp[N][N][N][N];
ll calc(int u, int n0, int n1, int n2)
{
    if (n0 < 0 || n1 < 0 || n2 < 0) return 0;
    if (n1 + n2*2 == k) return 1;
    if (u >= n+1) return 0;
    if (n1 == 0 && n0 == 0) return 0;
    if (dd[u][n0][n1][n2] == t+1) return dp[u][n0][n1][n2];
    else dd[u][n0][n1][n2] = t+1;
    return dp[u][n0][n1][n2] = (n0*calc(u+1, n0-1, n1+1, n2) % mod + n1*calc(u+1, n0, n1-1, n2+1) % mod + calc(u+1, n0, n1, n2) + n0*(n0-1)/2*calc(u+1, n0-2, n1, n2+1) % mod) % mod;

}
int main()
{
    freopen("INP.TXT", "r", stdin);
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        cout <<calc(1, m, 0, 0)<<endl;
    }
}
