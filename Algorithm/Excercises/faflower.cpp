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
#define maxn 2000006
#define task "faflower"
#define remain(x) ((x > MOD) ? (x - MOD) : x)
#define bit(x, i) (((x) >> (i)) & 1)

using namespace std;

ll n, t, res[maxn], luu[maxn], ans = 0, mask, pos, vt;

vector <int> ke[maxn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n >> t;
    FOR(i, 1, n)
        FOR(j, 1, n)
        {
            char c;
            cin >> c;
            if (c - '0') ke[i].PB(j);
        }
    for (auto i : ke[1]) res[1]++, mask += (1 << (i-1));
    //luu[mask] = 1;
    ans += res[1];
    FOR(q, 2, t)
    {
        ll mas = 0;
        FOR(i, 1, n)
        {
            if (!bit(mask, i-1)) res[q] += 2ll * sz(ke[i]);
            else
            {
                res[q] += 1ll * sz(ke[i]);
                for (auto j : ke[i])
                    if (bit(mas, j-1)) mas -= (1 << (j-1));
                        else mas += (1 << (j-1));
            }
        }
        if (!mas)
            {
                FOR(i, 1, n)
                    ans += 2ll * sz(ke[i]) * (t-q);
                cout << ans + res[q];
                return 0;
            }
        mask = mas;
        ans += res[q];
        if (luu[mas])
        {
            pos = q - luu[mas];
            vt = q;
            break;
        }
        luu[mask] = q;
    }
    if (pos)
    {
        t = max(0ll, t - luu[mask]);
        FOR(i, luu[mask]+1, vt)
            ans += res[i]*(t/pos - 1);
        FOR(i, 1, t%pos)
            ans += res[i+luu[mask]];
    }
    cout << ans;
    return 0;
}
