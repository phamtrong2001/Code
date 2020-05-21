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
#define task "sqsum"
#define maxc 1000000007
#define maxn 100005

using namespace std;

int n, a[maxn][11], f[maxn][11], cnt = 0, hang, res = maxc;

void nhap()
{
    cin >> n;
    hang = (n-1)/10 + 1;
    for (int i = 1; i <= hang; i++)
        for (int j = 1; j <= 10; j++)
        {
            a[i][j] = ++cnt;
            f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
        }
}

void xuli()
{
    for (int k = 1; k <= 10; k++)
        for (int i = k; i <= hang; i++)
            for (int j = k; j <= 10; j++)
                if (f[i][j] + f[i-k][j-k] - f[i][j-k] - f[i-k][j] == n)
                    res = min(res, a[i-k+1][j-k+1]);
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    nhap();
    xuli();
    return 0;
}
