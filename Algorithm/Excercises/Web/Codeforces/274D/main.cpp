#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, m, ans[N], in[N], res, tt, pos[N];
vector<int> g[N];

void solve(int x)
{
    queue<int> q;
    q.push(x);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u <= m) pos[u] = ++res;
        for (auto v : g[u])
        {
            in[v]--;
            if (in[v] == 0) q.push(v);
        }
    }
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    scanf("%d %d", &n, &m);
    int cnt = m;
    for (int i = 1; i <= n; i++)
    {
        map<int, vector<int> >a;
        for (int j = 1; j <= m; j++)
        {
            int x; scanf("%d", &x);
            a[x].PB(j);
        }
        vector<pair<int, vector<int> > >v(a.begin(), a.end());
        for (int j = 0; j < v.size()-1; j++)
            if (v[j].F != -1)
            {
                ++cnt;
                for (int u : v[j].S) g[u].PB(cnt), in[cnt]++;
                for (int u : v[j+1].S) g[cnt].PB(u), in[u]++;
            }
    }
    for (int i = 1; i <= m; i++)
        if (!pos[i] && in[i] == 0)
        {
            tt++;
            solve(i);
        }
    if (res < m) {printf("-1"); return 0;}
    for (int i = 1; i <= m; i++) ans[pos[i]] = i;
    for (int i = 1; i <= m; i++) printf("%d ", ans[i]);

}
