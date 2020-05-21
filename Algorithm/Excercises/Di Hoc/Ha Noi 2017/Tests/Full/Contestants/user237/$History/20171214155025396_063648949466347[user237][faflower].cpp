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
#define maxn 25
#define task "faflower"
#define remain(x) ((x > MOD) ? (x - MOD) : x)

using namespace std;

ll n, t, tr[maxn], tr2[maxn], res = 0;

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
    for (auto i : ke[1]) res++, tr[i] = 1;
    t--;
    while (t--)
    {
        bool dd = 0;
        memset(tr2, 0, sizeof (tr2));
        FOR(i, 1, n)
        {
            int pos = ((tr[i] % 2) ? 1 : 2);
            for (auto j : ke[i])
            {
                res += pos;
                tr2[j] += pos;
            }
        }
        FOR(i, 1, n)
        {
            tr[i] = tr2[i];
            if (tr[i]%2) dd = 1;
        }
        if (!dd)
        {
            res += n*2*t;
            break;
        }
    }
    cout << res;
    return 0;
}
