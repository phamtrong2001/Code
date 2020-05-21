#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 50005
#define maxc 1ll*1000000000000000007

using namespace std;

ll n, k, play[N], ddplay[N], sz[N], tt, d[N], used[N];
vector<pii> a[N];

bool solve(ll u, ll p, ll X)
{

    vector<ll> ve;
    if (ddplay[u]) ve.PB(0), sz[u] = 1;
    else sz[u] = 0;
    bool res = 1;
    for (auto z : a[u])
    {
        ll v = z.F;
        ll w = z.S;
        if (v == p) continue;
        res &= solve(v, u, X);
        if (sz[v] % 2)
            ve.PB(d[v] + w);
        sz[u] += sz[v];
    }
    sort(ve.begin(), ve.end());
    ll szVe = ve.size();

    if (ve.size() % 2 == 0)
    {
        for (ll i = 0; i < szVe; i++)
            if (ve[i] + ve[szVe-i-1] > X) return 0;
        res &= 1;
    }
    else
    {
        tt++; ll dem = 0;
        set<pii> se;
        for (ll i = 0; i < szVe; i++) se.insert(mp(ve[i], i));
        for (ll i = szVe-1; i >= 0; i--)
        {
            if (used[i] == tt) continue;
            used[i] = tt;
            se.erase(mp(ve[i], i));
            auto it = se.upper_bound(mp(X - ve[i], N));
            if (it == se.begin())
            {
                used[i] = tt-1;
                se.insert(mp(ve[i], i));
                continue;
            }
            else
            {
                it--;
                ll id = (*it).S;
                used[id] = tt;
                se.erase(it);
                dem++;
            }
        }
        d[u] = (*se.begin()).F;
        if (dem == szVe/2) res &= 1;
        else return 0;
    }
    return res;
}

int readInt () {
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
int main()
{
    freopen("BUBBLETEA.INP", "r", stdin);
    freopen("BUBBLETEA.OUT", "w", stdout);
    n = readInt(); k = readInt();
    for (ll i = 1; i <= k; i++) play[i] = readInt(), ddplay[play[i]] = 1;
    for (ll i = 1; i < n; i++)
    {
        ll u, v, w;
        u = readInt(); v = readInt(); w = readInt();
        a[u].PB(mp(v, w));
        a[v].PB(mp(u, w));
    }

    ll l = 0, r = maxc;
    while (r - l > 1)
    {
        ll mid = (r + l) / 2;
        if (solve(1, -1, mid)) r = mid;
        else l = mid;
    }
    cout <<r;
}
