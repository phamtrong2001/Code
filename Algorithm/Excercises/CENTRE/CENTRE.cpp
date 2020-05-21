#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, m, dist1[N], distn[N];
ll cnt1[N], cntn[N];
vector<pii> a[N];

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

void setup()
{
    n = readInt(); m = readInt();
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; u = readInt(); v = readInt(); w = readInt();
        a[u].PB(mp(v, w));
        a[v].PB(mp(u, w));
    }
}
void IJK(int s, int dist[], ll cnt[])
{
    priority_queue<pair<int, int> > q;
    for (int i = 1; i <= n; i++) dist[i] = maxc;
    dist[s] = 0; cnt[s] = 1;
    q.push(mp(0, s));
    while (!q.empty())
    {
        int u = q.top().S;
        int l = -q.top().F;
        q.pop();
        if (dist[u] < l) continue;
        for (auto z : a[u])
        {
            int v = z.F;
            int w = z.S;
            if (dist[v] > l + w)
            {
                dist[v] = l + w;
                cnt[v] = cnt[u];
                q.push(mp(-dist[v], v));
            }
            else if (dist[v] == l + w)
                cnt[v] += cnt[u];
        }
    }
}
int main()
{
    freopen("CENTRE.INP", "r", stdin);
    freopen("CENTRE.OUT", "w", stdout);
    setup();
    IJK(1, dist1, cnt1);
    IJK(n, distn, cntn);
    vector<int> res;
    for (int i = 2; i < n; i++)
    {
        if (dist1[n] < dist1[i] + distn[i]) res.PB(i);
        else if (cnt1[n] > cnt1[i]*cntn[i]) res.PB(i);
    }
    cout <<res.size()<<'\n';
    for (int i = res.size()-1; i >= 0; i--) cout<<res[i]<<'\n';
}
