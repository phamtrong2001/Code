#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 200005
#define mid (l + r)/2
#define maxc 1000000007

using namespace std;

int n, q, x[N*2], cur;
pii allQuery[N];

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

struct IntervalTree
{
    int t[N << 2], lazy[N << 2];

    void push(int l, int r, int id)
    {
        int z = lazy[id]; lazy[id] = 0;
        t[id] += z;
        if (l == r) return;
        lazy[id*2] += z;
        lazy[id*2+1] += z;
    }
    void update(int l, int r, int id, int x, int y)
    {
        push(l, r, id);
        if (l > y || r < x) return;
        if (l >= x && r <= y)
        {
            lazy[id]++;
            push(l, r, id);
            return;
        }
        update(l, mid, id*2, x, y);
        update(mid+1, r, id*2+1, x, y);
    }
    int get(int l, int r, int id, int x)
    {
        push(l, r, id);
        if (l == r) return t[id];
        if (x <= mid) return get(l, mid, id*2, x);
        return get(mid+1, r, id*2+1, x);
    }
}t1, t2;
int main()
{
    freopen("DLIGHT.INP", "r", stdin);
    freopen("DLIGHT.OUT", "w", stdout);
    n = readInt(); q = readInt();
    int lef = maxc, rig = 0;
    for (int i = 1; i <= q; i++)
    {
        int u, v; u = readInt(); v = readInt();
        allQuery[i] = mp(u, v);
        x[++cur] = u;
        x[++cur] = v;
        lef = min(lef, u);
        rig = max(rig, v);
    }
    sort(x+1, x+cur+1);
    cur = unique(x+1, x+cur+1) - x - 1;
    for (int i = 1; i <= q; i++)
    {
        allQuery[i].F = lower_bound(x+1, x+cur+1, allQuery[i].F) - x;
        allQuery[i].S = lower_bound(x+1, x+cur+1, allQuery[i].S) - x;
        t1.update(1, cur, 1, allQuery[i].F, allQuery[i].S-1);
        t2.update(1, cur, 1, allQuery[i].F, allQuery[i].S);
    }
    int res = 0;
    for (int i = 1; i <= cur; i++)
    {
        if (i != cur) res += (x[i+1] - x[i] - 1)*((t1.get(1, cur, 1, i) % 3) == 0);
        res += ((t2.get(1, cur, 1, i) % 3) == 0);
    }
    cout <<res + lef - 1 + (n - rig);
}
