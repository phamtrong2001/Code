#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1000005
#define maxc 1000000007

using namespace std;

int n, res;
pii a[N];

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
    freopen("RECT.INP", "r", stdin);
    freopen("RECT.OUT", "w", stdout);
    n = readInt();
    for (int i = 1; i <= n; i++)
    {
        int u, v; u = readInt(); v = readInt();
        if (u < v) swap(u, v);
        a[i] = mp(u, v);
    }
    sort(a+1, a+n+1);

    set<pii> s;
    for (int i = n; i >= 1; i--)
    {
        auto it = s.lower_bound(mp(a[i].S, 0));
        if (it == s.begin())
        {
            s.insert(mp(a[i].S, i));
            res++;
            continue;
        }
        it--;
        s.erase(it);
        s.insert(mp(a[i].S, i));
    }
    cout <<res;
}
