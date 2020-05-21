#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define PB push_back
#define F first
#define S second
#define N 100005
#define ll long long

using namespace std;

int n;
int spe[N], sz[N], dd[N], belong[N], h[N], sl;
ll up[N], down[N], ans, M, PHI;
vector<pii> a[N];
vector<int> vlist;
void nhap()
{
    scanf("%d %d", &n, &M);
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u++; v++;
        a[u].PB(mp(v, w));
        a[v].PB(mp(u, w));
    }
}
int phi(int x)
{
	int ans = 1; int y = x;
	for(ll i = 2; i <= sqrt(x); i++)
	{
		if(x % i == 0)
		{
			y /= i;
			ans *= (i - 1);
		}
		while(x % i==0) x /= i;
	}
	if (x > 1)
	{
		y /= x;
		ans *= (x - 1);
	}
	x = 1;
	ans *= y;
	return ans;
}

ll Pow(ll a, ll b)
{
    if (b == 0) return 1;
    ll x = Pow(a, b/2);
    x = (x*x) % M;
    if (b & 1) return (x * a) % M;
    return x;
}
ll inv(ll a)
{
    return Pow(a, PHI-1);
}
void dfsCentroid(int u)
{
    spe[u] = 0; sz[u] = 1;
    dd[u] = 1;
    for (auto z : a[u])
    {
        int v = z.F;
        if (dd[v]) continue;
        dfsCentroid(v);
        if (sz[v] > sz[spe[u]]) spe[u] = v;
        sz[u] += sz[v];
    }
    dd[u] = 0;
}
int centroid(int u)
{
    int siz = sz[u]/2;
    while (sz[spe[u]] > siz)
        u = spe[u];
    return u;
}

void DFS1(int u, int p, int cent)
{
    if (p == cent) belong[u] = sl++;
    else if (p != -1) belong[u] = belong[p];
    vlist.PB(u);
    for (auto z : a[u])
    {
        int v = z.F;
        int w = z.S;
        if (v == p || dd[v]) continue;
        up[v] = (up[u] + (1ll*w*Pow(10, h[u])) % M) % M;
        down[v] = ((down[u]*10) % M + w) % M;
        h[v] = h[u] + 1;
        DFS1(v, u, cent);
    }
}
void solve(int u)
{
    dfsCentroid(u);
    u = centroid(u);
    dd[u] = 1;
    vlist.clear(); sl = 0;
    up[u] = down[u] = h[u] = 0;
    belong[u] = -1;
    DFS1(u, -1, u);
    map<ll, ll> all;
    vector<map<ll, ll> > only;
    only.resize(sl+2);
    all[0]++;
    for (auto v : vlist)
    {
        if (v == u) continue;
        all[up[v]]++;
        only[belong[v]][up[v]]++;
    }
    for (auto v : vlist)
    {
        int dep = h[v];
        int comp = belong[v];
        if (v == u)
        {
            ans += all[0] - 1;
        }
        else
        {
            ll val = (-down[v] + M) % M;
            val = (val * inv(Pow(10, dep))) % M;
            ans += all[val] - only[comp][val];
        }
    }
    for (auto z : a[u])
        if (!dd[z.F]) solve(z.F);
}
void xuli()
{
    if (M == 1) ans = 1ll*n*(n-1);
    else
    {
        PHI = phi(M);
        solve(1);
    }
    cout <<ans;


}
int main()
{
    freopen("INP.TXT", "r", stdin);
    nhap();
    xuli();

}
