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
#define task "seq2015"
#define maxc 1000000007
#define maxn 705
#define MOD 30103

using namespace std;

int n, a[maxn], t[maxn][2004], dp[maxn][maxn];

void update(int x, int y, int val)
{
    for (; x < maxn; x += (x & -x))
        for (int z = y; z <=
         2000; z += (z & -z)) t[x][z] += val;
}

int get(int x, int y)
{
    int cur = 0;
    for (; x; x -= (x & -x))
        for (int z = y; z; z -= (z & -z)) cur = (cur + t[x][z]) % MOD;
    return cur;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = n; j >= 2; j--)
        for (int i = j-1; i >= 1; i--)
        {
            int x = a[i] + a[j];
            dp[i][j] = (get(i-1, 2000) - get(i-1, x) + 1 + MOD) % MOD;
            update(i, x, dp[i][j]);
        }
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
            res = (res + dp[i][j] - 1 + MOD) % MOD;
    cout << res;
    return 0;
}
