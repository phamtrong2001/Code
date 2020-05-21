/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define pii pair<int, int>
#define sz(x) ((int) x.size())
#define PB push_back
#define PF push_front
#define MP make_pair
#define ll long long
#define F first
#define S second
#define maxc 1000000007
#define MOD 1000000007
#define base 107
#define eps 1e-6
#define maxn
#define task "palinn"
#define remain(x) ((x > MOD) ? (x - MOD) : x)

using namespace std;

ll n, m, k;

ll p[55], f[104][104][11], s[104][104], ans[105];

void DFS(ll u, ll mod, ll val)
{
    if (n % 2 == 1 && u == n/2 + 2) return;
    if (n % 2 == 0 && u == n/2 + 1) return;
    FOR(i, 0, 9)
    {
        if (val > f[u][mod][i]) val -= f[u][mod][i];
            else
            {
                ll x = p[u-1] + p[n-u];
                if (n % 2 == 1 && u == n/2+1) x = p[u-1];
                mod = ((mod - i*(p[u-1] + p[n-u])) % m + m) % m;
                ans[u] = ans[n-u+1] = i;
                DFS(u+1, mod, val);
                return;
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> m >> k;
    p[0] = 1;
    FOR(i, 1, 41)
        p[i] = (p[i-1] * 10) % m;
    if (n == 1)
    {
        ll kq[10], dem = 0;
        FOR(i, 1, 9)
            if (!(i % m)) kq[++dem] = i;
        cout << dem << '\n' << kq[k];
        return 0;
    }
    if (!(n % 2)) s[n/2+1][0] = 1;
        else FOR(i, 0, 9)
        {
            f[n/2+1][i*p[n/2] % m][i]++;
            s[n/2+1][i*p[n/2] % m]++;
        }
    FORD(i, n/2, 1)
        FOR(j, 0, m-1)
            FOR(c, 0, 9)
            {
                if (i == 1 && c == 0) continue;
                ll x = (j + c*(p[i-1] + p[n-i])) % m;
                f[i][x][c] += s[i+1][j];
                s[i][x] += s[i+1][j];
            }
    cout << s[1][0]<< '\n';
    DFS(1, 0, k);
    FOR(i, 1, n) cout << ans[i];
    return 0;
}
