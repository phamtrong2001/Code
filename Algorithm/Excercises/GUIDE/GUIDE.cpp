#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 200005
#define LN 25
#define maxc 1000000007

using namespace std;

int n, k, belong[N], p[N][LN], h[N], tt;
vector<int> a[N];

int readInt()
{
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
void nhap()
{
    n = readInt(); k = readInt();
    for (int i = 1; i <= k; i++)
    {
        int u, v; u = readInt(); v = readInt();
        a[u].PB(v);
        a[v].PB(u);
    }
}
void DFS(int u)
{
    belong[u] = tt;
    for (auto v : a[u])
    {
        if (belong[v]) continue;
        h[v] = h[u] + 1;
        p[v][0] = u;
        for (int i = 1; i < LN; i++)
            p[v][i] = p[p[v][i-1]][i-1];
        DFS(v);
    }
}
int up(int v, int delta)
{
    for (int i = 0; i < LN; i++)
        if ((delta >> i) & 1) v = p[v][i];
    return v;
}
int LCA(int u, int v)
{
    if (h[u] > h[v]) swap(u, v);
    int delta = h[v] - h[u];
    v = up(v, delta);
    if (u == v) return u;
    for (int i = LN-1; i >= 0; i--)
        if (p[u][i] != p[v][i])
        {
            u = p[u][i];
            v = p[v][i];
        }
    return p[u][0];
}
void solve()
{
    for (int i = 1; i <= n; i++)
        if (belong[i] == 0)
        {
            tt++;
            DFS(i);
        }
    int m = readInt();
    for (int i = 1; i <= m; i++)
    {
        int u, v; u = readInt(); v = readInt();
        if (u == v)
        {
            cout <<u<<'\n';
            continue;
        }
        if (belong[u] != belong[v])
        {
            cout <<-1<<'\n';
            continue;
        }
        int lca = LCA(u, v);
        if (lca != u)
        {
            cout <<p[u][0]<<'\n';
            continue;
        }
        cout <<up(v, h[v] - h[u] - 1)<<'\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("GUIDE.INP", "r", stdin);
    freopen("GUIDE.OUT", "w", stdout);
    nhap();
    solve();
}
