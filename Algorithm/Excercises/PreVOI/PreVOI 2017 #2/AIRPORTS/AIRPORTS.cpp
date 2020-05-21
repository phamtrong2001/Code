#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 400005
#define maxc 1ll*1000000000000000007

using namespace std;

int n, m, Q, root[N], cnt;
ll s[N], a[N];

struct edge
{
    int u, v, w;
    edge(int u=0, int v=0, int w=0) : u(u), v(v), w(w) {}
}e[N];
bool cmp1(edge p, edge q) {return p.w < q.w;}

int readInt ()
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
    n = readInt(); m = readInt(); Q = readInt();
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; u = readInt(); v = readInt(); w = readInt();
        e[i] = edge(u, v, w);
    }
    sort(e+1, e+m+1, cmp1);
}
int get_root(int u)
{
    return (root[u] == 0) ? u : root[u] = get_root(root[u]);
}
void Kruskal()
{
    memset(s, 60, sizeof s);
    s[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        int u = e[i].u;
        int v = e[i].v;
        int p = get_root(u);
        int q = get_root(v);
        if (p != q)
        {
            root[p] = q;
            cnt++;
            s[cnt] = s[cnt-1] + e[i].w;
            a[cnt] = e[i].w;
        }
    }
}
ll f(int u, int mid)
{
    int pos = n - mid;
    return 1ll*s[pos] + 1ll*u*mid;
}
void solve()
{
    for (int i = 1; i <= Q; i++)
    {
        int u, v; u = readInt(); v = readInt();
        if (v < n - cnt)
        {
            printf("-1\n");
            continue;
        }
        int pos = upper_bound(a+1, a+cnt+1, u) - a;
        if (n-pos+1 > v) pos = n-v+1;
        ll res = s[pos-1] + 1ll*(n-pos+1)*u;
        printf("%lld\n", res);
    }
}

int main()
{
    freopen("AIRPORTS.INP", "r", stdin);
    freopen("AIRPORTS.OUT", "w", stdout);
    nhap();
    Kruskal();
    solve();
}
