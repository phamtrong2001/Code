#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
using namespace std;

int n, w, h, people[N], dir[N], res[N];
vector<pii> all[3][3*N];
vector<pair<pii, int> > store[3];
void nhap()
{
    cin >> n >> w >> h;
    for (int i = 1; i <= n; i++)
    {
        int type, pos, twait;
        cin >> type >> pos >> twait;
        people[i] = pos;
        all[type][pos - twait + N].PB(mp(pos, i));
        store[type].PB(mp(mp(pos, twait), i));
    }
}
void solve()
{
    sort(store[1].begin(), store[1].end());
    sort(store[2].begin(), store[2].end());
    for (int i = 0; i <= 2*N; i++)
    {
        sort(all[1][i].begin(), all[1][i].end());
        sort(all[2][i].begin(), all[2][i].end());
    }
    for (auto z : store[1])
    {
        int delta = z.F.F - z.F.S + N;
        if (all[2][delta].size() == 0)
        {
            dir[z.S] = 1;
            res[z.S] = people[z.S];
        }
        else
        {
            int sz = all[2][delta].size();
            pii zz = all[2][delta][sz-1];
            all[2][delta].pop_back();
            all[2][delta].push_back(mp(zz.F, z.S));
            dir[zz.S] = 1;
            res[zz.S] = people[z.S];
        }
    }
    for (auto z : store[2])
    {
        int delta = z.F.F - z.F.S + N;
        if (all[1][delta].size() == 0)
        {
            dir[z.S] = 2;
            res[z.S] = people[z.S];
        }
        else
        {
            int sz = all[1][delta].size();
            pii zz = all[1][delta][sz-1];
            all[1][delta].pop_back();
            all[1][delta].push_back(mp(zz.F, z.S));
            dir[zz.S] = 2;
            res[zz.S] = people[z.S];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dir[i] == 2) cout <<w<<" "<<res[i]<<endl;
        else cout <<res[i]<<" "<<h<<endl;
    }
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    nhap();
    solve();
}
