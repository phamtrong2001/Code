#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 200005
#define maxc 1000000007

using namespace std;

ll k, m, n;
string s;

struct query__
{
    int lef, rig, pos;
}q[N];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("FASTTYPE.INP", "r", stdin);
    freopen("FASTTYPE.OUT", "w", stdout);
    cin >> k >> m >> s >> n;
    s = "#" + s;
    for (int i = 1; i <= n; i++)
        cin >> q[i].lef >> q[i].rig >> q[i].pos;
    for (int j = 1; j <= k; j++)
    {
        ll id = j;
        for (int i = n; i >= 1; i--)
        {
            if (id > q[i].pos)
            {
                if (id <= q[i].pos + q[i].rig - q[i].lef)
                {
                    id = q[i].lef + id - q[i].pos;
                }
                else id = id - (q[i].rig - q[i].lef);
            }
        }
        cout <<s[id];
    }
}
