#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 500005
#define maxc 1000000007

using namespace std;

int n, h[N], sz[N], res;
vector<int> a[N];

void DFS(int u)
{
    for (auto v : a[u])
    {
        DFS(v);
        sz[u] += sz[v];
        h[u] = max(h[u], h[v]);
    }
    if (h[u] > 0 && (sz[u] + h[u] + a[u].size() + 1) % 2 == 0) res++;
    sz[u]++;
    h[u]++;
}
int main()
{
    freopen("TGAME.INP", "r", stdin);
    //freopen("TGAME.OUT", "w", stdout);
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int u; cin >> u;
        a[u].PB(i);
    }
    DFS(1);
    cout <<res;
}
