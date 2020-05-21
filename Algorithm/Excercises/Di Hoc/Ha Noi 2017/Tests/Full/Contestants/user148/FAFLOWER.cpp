#include <bits/stdc++.h>
#define maxn 22
#define maxC 1000000007
#define Task "FAFLOWER"
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define F first
#define S second

using namespace std;

int n, Sum;
long long t, ans = 0;
int dd[maxn], d[maxn];
vector <int> a[maxn];

void setup()
{
    cin >> n >> t;
    char x;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> x;
            if (x == '1') a[i].pb(j);
        }
}

void solve()
{
    for (int i = 0; i < a[1].size(); ++i) d[a[1][i]]++, ans += 1ll;
    t--;
    int flag = 0;
    while (!flag && t)
    {
        memset(dd, 0, sizeof(dd));
        flag = 1;
        Sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (d[i] % 2 == 0) dd[i] = 2;
            else dd[i] = 1;
        }
        memset(d, 0, sizeof(d));
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < a[i].size(); ++j)
                d[a[i][j]] += dd[i];
        for (int i = 1; i <= n; ++i)
        {
            Sum += d[i];
            if (d[i] % 2 == 1) flag = 0;
        }
        ans += 1ll * Sum;
        t--;
    }
    if (!t)
    {
        cout << ans;
        return;
    }
    memset(dd, 0, sizeof(dd));
    flag = 1;
    Sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (d[i] % 2 == 0) dd[i] = 2;
        else dd[i] = 1;
    }
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < a[i].size(); ++j)
            d[a[i][j]] += dd[i];
    for (int i = 1; i <= n; ++i)
    {
        Sum += d[i];
        if (d[i] % 2 == 1) flag = 0;
    }
    ans += 1ll * Sum;
    t--;
    ans += 1ll * Sum * t;
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(); cout.tie();
    freopen(Task".INP", "r", stdin);
    freopen(Task".OUT", "w", stdout);
    setup();
    solve();
    return 0;
}
