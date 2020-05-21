#include <bits/stdc++.h>
using namespace std;
#define whole(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define ins insert
#define ft first
#define sd second
#define _(a) #a << " : " << (a)
typedef long long ll;
typedef pair <int,int> pii;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m;
ll t;
vi adj[maxn];
int next_state [1 << 21 + 1];
ll sum_next [1 << 21 + 1] = {};
void input ()
{
	cin >> n >> t;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			char p;
			cin >> p;
			if (p == '1') adj[i].pb (j);
		}
}
bool get_bit (int i, int j)
{
	return (i >> j) & 1;
}
int change (int t)
{
	int gg[22] = {};
	for (int i = 0; i < n; ++i)
	{
		if (get_bit (t, i))
		{
			for (int j : adj[i])
				gg[j] += 1;
		}
		else
		{
			for (int j : adj[i])
				gg[j] += 2;
		}
	}
	int next_state = 0;
	int h = 1;
	for (int i = 0; i < n; ++i)
	{
		sum_next [t] += gg[i];
		next_state += (gg[i] % 2) * h;
		h *= 2;
	}
	return next_state;
}
ll cycle_sum = 0;
int cycle_len = 0, pre_len, cycle_head, ft = 0;
bool in_cycle[maxn];
void cycle_detect ()
{
	int i = ft, j = next_state[ft];
	while (i != j)
	{
		i = next_state[i];
		j = next_state[next_state[j]];
	}
	j = next_state[i];
	cycle_len = 1;
	cycle_sum = sum_next[i];
	while (j != i)
	{
		in_cycle[j] = 1;
		cycle_sum += sum_next[j];
		j = next_state[j];
		cycle_len ++;
	}
	in_cycle[i] = 1;
	i = ft;
	while (!in_cycle[i]) ++pre_len, i = next_state[i];
	cycle_head = i;
}
ll walk (int i, int t)
{
	ll res = 0;
	for (; t; --t)
	{
		res += sum_next[i];
		i = next_state[i];
	}
	return res;
}
void solve ()
{
	for (int i = 0; i < (1 << n); ++i)
	{
		next_state [i] = change (i);
	}
	ll res = 0;
	// for (int i = 0; i < (1 << n); ++i) cout << i << ' ' << next_state[i] << ' ' << sum_next[i] << '\n';
	--t;
	for (int j : adj[0]) ft += (1 << j), res ++;
	cycle_detect ();
	if (t <= pre_len)
	{
		cout << walk (ft, t) + res;
		return;
	}
	else
	{
		res += walk (ft, pre_len);
		t -= pre_len;
		res += cycle_sum * (t / cycle_len);
		t %= cycle_len;
		res += walk (cycle_head, t);
		cout << res;
		return;
	}
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	freopen ("faflower.inp", "r", stdin);
	freopen ("faflower.out", "w", stdout);
	cin.tie (NULL);
	cout.tie (NULL);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}