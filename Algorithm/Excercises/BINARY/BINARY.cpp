#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define mod 1000000007

using namespace std;

int n, visit[N], c[N], res = 1;
vector<pii> a[N];

void addEdge(int u, int v, int val)
{
    a[u].PB(mp(v, val));
    a[v].PB(mp(u, val));
}
void stop()
{
    cout <<0;
    exit(0);
}
void DFS(int u, int col)
{
    visit[u] = 1;
    for (auto z : a[u])
    {
        int v = z.F;
        int val = z.S;
        if (!visit[v])
        {
            c[v] = c[u]^val;
            DFS(v, c[v]);
        }
        else if (c[v] != c[u]^val) stop();
    }
}
int main()
{
    freopen("BINARY.INP", "r", stdin);
    freopen("BINARY.OUT", "w", stdout);
    cin >> n; int www; cin >> www;
    if (www > 0) stop();
    for (int i = 2; i <= n; i++)
    {
        int x; cin >> x;
        if (x == -1) continue;
        if (i + x > n+1) stop();
        for (int j = i; j <= i+x-1; j++) addEdge(j-i+1, j, 0);
        if (i + x <= n) addEdge(x+1, i+x, 1);
    }
    for (int i = 1; i <= n; i++)
        if (!visit[i])
        {
            DFS(i, 0);
            res = (res*2) % mod;
        }
    cout <<res;
}
