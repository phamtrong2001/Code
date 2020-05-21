#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 200005
#define maxc 1000000007

using namespace std;

int n, m, pos[N], res[N], cur, t[N];
pii all[N*20];
pair<pii, int> q[N];
bool cmp1(pii p, pii q)
{
    return p.S < q.S;
}
bool cmp2(pair<pii, int> p, pair<pii, int> q)
{
    return p.F.S < q.F.S;
}
void upd(int x, int val)
{
    for (; x < N; x += (x & -x)) t[x] += val;
}
int get(int x)
{
    int ans = 0;
    for (; x; x -= (x & -x)) ans += t[x];
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("INP.TXT", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        pos[x] = i;
    }
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
        {
            int u = pos[i];
            int v = pos[j];
            if (u > v) swap(u, v);
            all[++cur] = mp(u, v);
        }
    sort(all+1, all+cur+1, cmp1);
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        q[i] = mp(mp(u, v), i);
    }
    sort(q+1, q+m+1, cmp2);
    int j = 1;
    for (int i = 1; i <= m; i++)
    {
        while (all[j].S <= q[i].F.S && j <= cur)
        {
            upd(all[j].F, 1);
            j++;
        }
        res[q[i].S] = get(q[i].F.S) - get(q[i].F.F-1);
    }
    for (int i = 1; i <= m; i++) cout <<res[i]<<'\n';
}
