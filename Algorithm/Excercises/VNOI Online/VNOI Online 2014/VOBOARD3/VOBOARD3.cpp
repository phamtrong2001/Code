#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1005
#define maxc 1000000007

using namespace std;

int n, m, a[N][N], s[N][N], dd[N][N], res;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("VOBOARD3.INP", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char c; cin >> c;
            a[i][j] = c - '0';
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int cnt = s[i-1][j] + s[i][j-1] - s[i-1][j-1];
            s[i][j] = cnt;
            if ((cnt + a[i][j]) % 2 == 1)
            {
                s[i][j] = cnt + 1;
                dd[i][j] = 1;
                res++;
            }
        }
    cout <<res<<'\n';
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (dd[i][j]) cout <<i<<" "<<j<<" "<<n-i+1<<" "<<m-j+1<<'\n';
}
