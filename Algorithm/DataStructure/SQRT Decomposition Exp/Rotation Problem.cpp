#include <bits/stdc++.h>
#define M 400
#define N 100005
using namespace std;

deque<int> qu[300];
int dem[300][N], res;
int n, m;

void xuli1(int l, int r)
{
    int u = l/M; int p = l%M;
    int v = r/M; int q = r%M;
    if (u == v)
    {
        int x = qu[u].at(q);
        qu[u].erase(qu[u].begin()+q);
        qu[u].insert(qu[u].begin()+p, x);
    }
    else
    {
        int x = qu[v].at(q);
        dem[v][x]--; qu[v].erase(qu[v].begin()+q);
        dem[u][x]++; qu[u].insert(qu[u].begin()+p, x);
        for (int i = u; i < v; i++)
        {
            x = qu[i].back();
            dem[i][x]--; qu[i].pop_back();
            dem[i+1][x]++; qu[i+1].push_front(x);
        }
    }
}
int xuli2(int l, int r, int k)
{
    int u = l/M; int p = l%M;
    int v = r/M; int q = r%M;
    int res = 0;
    if (u == v)
    {
        for (int i = p; i <= q; i++)
            if (qu[u].at(i) == k) res++;
    }
    else
    {
        for (int i = u+1; i < v; i++) res += dem[i][k];
        for (int i = p; i < M; i++)
            if (qu[u].at(i) == k) res++;
        for (int i = 0; i <= q; i++)
            if (qu[v].at(i) == k) res++;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("INP.TXT", "r", stdin);
    //freopen("SHIFT.OUT", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        qu[i/M].push_back(x);
        dem[i/M][x]++;
    }
    cin >> m;
    for (int i = 1; i <= n; i++)
    {
        int type, l, r, k;
        cin >> type >> l >> r;
        l = ((l+res-1) % n)+1;
        r = ((r+res-1) % n)+1;
        if (l > r) swap(l, r);
        l--; r--;
        if (type == 1) xuli1(l, r);

        else
        {
            cin >> k;
            k = ((k+res-1) % n)+1;
            res = xuli2(l, r, k);
            cout <<res<<'\n';
        }
    }
    return 0;
}
