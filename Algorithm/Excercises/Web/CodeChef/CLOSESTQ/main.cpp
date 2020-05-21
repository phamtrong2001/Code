#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define N 100005
#define PB push_back
#define maxc 1000000007

using namespace std;

struct query
{
    int u, v, startTime, endTime;
    query(int u=0, int v=0, int startTime=0, int endTime=0) : u(u), v(v), startTime(startTime), endTime(endTime) {}
};
vector<query> allQuery, all;

int q, tt[505][505], res[N];
set<int> s[505];
set<int>::iterator up, low;

int dist(pii p, pii q)
{
    int XX = p.F - q.F;
    int YY = p.S - q.S;
    return XX*XX + YY*YY;
}
int addpoint(query x, int xxx)
{
    int res = xxx;
    if (all.size() <= 50)
    {
        for (auto y : all)
            res = min(res, dist(mp(x.u, x.v), mp(y.u, y.v)));
    }
    else
    {
        int st; int en;
        for (int i = 1; i <= 500; i++)
            if ((i - x.u)*(i - x.u) <= res) en = i;
        for (int i = 500; i >= 1; i--)
            if ((i - x.u)*(i - x.u) <= res) st = i;
        for (int i = st; i <= en; i++)
        {
            if (s[i].empty()) continue;
            up = s[i].lower_bound(x.v);
            low = up--;
            if (up != s[i].end()) res = min(res, dist(mp(x.u, x.v), mp(i, *up)));
            if (low != s[i].end()) res = min(res, dist(mp(x.u, x.v), mp(i, *low)));
        }

        //if (res == maxc) res = 0;
    }
    s[x.u].insert(x.v);
    all.PB(x);
    return res;
}
void erasepoint(query x)
{
    all.pop_back(); s[x.u].erase(x.v);
}
void Calc(int l, int r, vector<query> v, int ans)
{
    int mid = (l + r) / 2;
    vector<query> ad, nx;

    for (auto z : v)
    {
        if (z.startTime > r || z.endTime <= l) continue;
        if (z.startTime <= l && z.endTime > r)
        {
            ans = min(ans, addpoint(z, ans));
            ad.PB(z);
        }
        else
        {
            nx.PB(z);
        }
    }
    //if (ans == 0) cerr <<l<<" "<<r<<endl;

    if (l == r) res[l] = ans;
    else
    {
        Calc(l, mid, nx, ans);
        Calc(mid+1, r, nx, ans);
    }
    for (auto z : ad) erasepoint(z);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    cin >> q;
    int dem = 0;
    for (int i = 1; i <= q; i++)
    {
        char c; int u, v; cin >> c >> u >> v;
        if (c == '+') tt[u][v] = i;
        else
        {
            allQuery.PB(query(u, v, tt[u][v], i));
            tt[u][v] = 0;
        }
    }
    for (int i = 1; i <= 500; i++)
        for (int j = 1; j <= 500; j++)
            if (tt[i][j]) allQuery.PB(query(i, j, tt[i][j], q+1));

    Calc(1, q, allQuery, maxc);
    for (int i = 1; i <= q; i++)
        if (res[i] != maxc) cout <<res[i]<<'\n';
        else cout <<0<<'\n';
}
