#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, m, s, t, d[N], h[N];
vector<pii> a[N];

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

int IJK(int s)
{
    priority_queue<pair<int, int> >q;
    for (int i = 1; i <= n; i++) d[i] = maxc;
    d[s] = 0;
    q.push(mp(0, s));
    while (!q.empty())
    {
        int u = q.top().S;
        int l = -q.top().F;
        q.pop();
        if (d[u] < l) continue;
        for (auto z : a[u])
        {
            int v = z.F;
            int w = z.S;
            if (d[v] > max(l, w))
            {
                d[v] = max(l, w);
                q.push(mp(-d[v], v));
            }
        }
    }
    return d[t];
}
int main()
{
    freopen("MOVE.INP", "r", stdin);
    freopen("MOVE.OUT", "w", stdout);
    n = readInt(); s = readInt(); t = readInt();
    for (int i = 1; i <= n; i++) h[i] = readInt();
    m = readInt();
    for (int i = 1; i <= m; i++)
    {
        int u, v; u = readInt(); v = readInt();
        a[u].PB(mp(v, abs(h[u] - h[v])));
        a[v].PB(mp(u, abs(h[u] - h[v])));
    }
    int res = IJK(s);
    if (res == maxc) res = -1;
    cout <<res;
}
