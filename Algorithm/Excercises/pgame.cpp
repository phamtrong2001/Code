/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define pii pair <int, int>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ll long long
#define maxn 10000005
#define maxc 1000000007
#define MOD 1000000007
#define task "pgame"

using namespace std;

int a[maxn], dem = 0, n, k, x;

bool dd[maxn];

void sang()
{
    dd[0] = dd[1] = 1;
    int i = 1;
    while (dem <= 500000)
    {
        ++i;
        if (dd[i]) continue;
        a[++dem] = i;
        for (int j = i+i; j <= maxn; j += i)
            dd[j] = 1;
    }
}

int calc(int x)
{
    FORD(i, k, 1)
    {
        if (x == (a[i] % n))
        {
            x = 0;
            continue;
        }
        x = (x + a[i]/(n-1)) % n;
        if (x <= (a[i]%(n-1))) x++;
    }
    x %= n;
    return x+1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    sang();
    cin >> n >> k >> x;
    int vt = x - 1;
    FOR (i, 1, k)
    {
        if (vt == 0)
        {
            vt = a[i] % n;
            continue;
        }
        if (vt <= (a[i]%(n-1))) vt--;
        vt -= a[i]/(n-1);
        vt = (vt + 10*n) % n;
    }
    //cout << vt << '\n';
    int l = vt - 1, r = vt + 1;
    if (l == -1) l = n-1;
    if (r == n) r = 0;
    cout << calc(r) << " " << calc(l);
    return 0;
}
