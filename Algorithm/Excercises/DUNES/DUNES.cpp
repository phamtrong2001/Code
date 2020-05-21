#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, m, l[N], r[N], w[N], x[2*N], res[N], addmore[N];

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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("DUNES.INP", "r", stdin);
    freopen("DUNES.OUT", "w", stdout);
    cin >> n >> m;
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i] >> w[i];
        x[++cur] = l[i];
        x[++cur] = r[i];
    }
    sort(x+1, x+cur+1);
    cur = unique(x+1, x+cur+1) - x - 1;
    for (int i = 1; i <= n; i++)
    {
        int u = lower_bound(x+1, x+cur+1, l[i]) - x;
        int v = lower_bound(x+1, x+cur+1, r[i]) - x;
        addmore[u] += w[i];
        for (int j = u; j < v; j++)
        {
            int z = x[j] - l[i];
            if (z % 2) res[j] -= w[i];
            else res[j] += w[i];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int y; cin >> y;
        int id = lower_bound(x+1, x+cur+1, y) - x;
        int ans = 0;
        if (y == x[id]) ans = addmore[id];
        id--;
        if ((y-x[id]) % 2) ans -= res[id];
        else ans += res[id];
        cout <<ans<<'\n';
    }
}
