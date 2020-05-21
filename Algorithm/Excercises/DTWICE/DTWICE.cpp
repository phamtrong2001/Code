#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define mid (r + l)/2
#define N 500005
#define maxc 1000000007

using namespace std;

int n, Q, a[N], x[N], cur, t[N], tr[N], pos[N], sau[N], res[N];
pair<pii, pii> all[N];
pair<pii, int> q[N];

void upd(int x, int val)
{
    for (; x < N; x += (x & -x))
        t[x] += val;
}
int get(int x)
{
    int ans = 0;
    for (; x; x -= (x & -x))
        ans += t[x];
    return ans;
}
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
    freopen("DTWICE.INP", "r", stdin);
    freopen("DTWICE.OUT", "w", stdout);
    n = readInt();
    Q = readInt();
    for (int i = 1; i <= n; i++)
    {
        a[i] = readInt();
        x[++cur] = a[i];
    }
    sort(x+1, x+cur+1);
    cur = unique(x+1, x+cur+1) - x - 1;
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(x+1, x+cur+1, a[i]) - x;
    for (int i = 1; i <= n; i++)
    {
        tr[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= cur; i++) pos[i] = n+1;
    for (int i = n; i >= 1; i--)
    {
        sau[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= Q; i++)
    {
        int u, v; u = readInt(); v = readInt();
        q[i] = mp(mp(u, v), i);
    }
    sort(q+1, q+Q+1);
    for (int i = 1; i <= n; i++) all[i] = mp(mp(tr[i], i), mp(sau[i], sau[sau[i]]));
    sort(all+1, all+n+1);
    int j = 1;
    for (int i = 1; i <= Q; i++)
    {
        while (j <= n && all[j].F.F+1 <= q[i].F.F)
        {
            int u = all[j].F.S;
            int v = all[j].S.F;

            if (all[j].F.F)
            {
                upd(u, -1);
                upd(v, 1);
            }
            if (v == n+1)
            {
                j++;
                continue;
            }
            upd(v, 1);
            upd(sau[v], -1);
            j++;
        }
        res[q[i].S] = get(q[i].F.S);
    }
    for (int i = 1; i <= Q; i++)
        printf("%d\n", res[i]);

}
