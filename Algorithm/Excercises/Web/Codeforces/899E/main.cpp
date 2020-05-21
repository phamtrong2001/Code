#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 200005
#define maxc 1000000007

using namespace std;

int n, a[N], tr[N], sau[N], sz[N];
set<pii> s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int pos = 0;
    for (int i = 1; i <= n+1; i++)
        if (a[i] != a[i-1])
        {
            tr[i] = pos;
            sau[pos] = i;
            sz[pos] = i - pos;
            pos = i;
        }
    for (int i = 1; i <= n; i++)
        if (tr[i] || sau[i])
            s.insert(mp(-sz[i], i));

    int res = 0;
    while (!s.empty())
    {
        res++;
        auto it1 = s.begin();

        int len = -(*it1).F;
        int id = (*it1).S;
        int ss = sau[id];
        int tt = tr[id];
        s.erase(it1);
        if (tt == 0 && ss == n+1) break;
        sau[tt] = ss;
        tr[ss] = tt;

        if (tt && ss != n+1 && a[tt] == a[ss])
        {
            s.erase(mp(-sz[tt], tt));
            s.erase(mp(-sz[ss], ss));
            s.insert(mp(-sz[tt]-sz[ss], tt));
            sz[tt] = sz[tt] + sz[ss];
            sau[tt] = sau[ss];
            tr[sau[ss]] = tt;
        }
    }
    cout <<res;
}
