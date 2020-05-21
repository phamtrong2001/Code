#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1000005
#define maxc 1000000007

using namespace std;

int n, m, a[N], b[N], bmax, bmin, lmin[N], lmax[N];

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
    freopen("LIMSPEED.INP", "r", stdin);
    freopen("LIMSPEED.OUT", "w", stdout);
    n = readInt(); m = readInt();
    b[n+1] = 1e9+7; bmin = n+1;
    for (int i = 1; i <= m; i++)
    {
        b[i] = readInt();
        if (b[bmax] < b[i]) bmax = i;
        if (b[bmin] > b[i]) bmin = i;
    }
    for (int i = 1; i <= n; i++) a[i] = readInt();
    deque<int> q1, q2;
    for (int i = 1; i <= n; i++)
    {
        while (!q1.empty() && i - q1.back() >= m) q1.pop_back();
        while (!q1.empty() && a[q1.front()] < a[i]) q1.pop_front();
        q1.push_front(i);
        lmax[i] = q1.back();

        while (!q2.empty() && i - q2.back() >= m) q2.pop_back();
        while (!q2.empty() && a[q2.front()] > a[i]) q2.pop_front();
        q2.push_front(i);
        lmin[i] = q2.back();
    }
    int res = 0;
    for (int i = m; i <= n; i++)
    {
        if (m - (i - lmax[i]) != bmax) continue;
        if (m - (i - lmin[i]) != bmin) continue;
        if (((a[i] - a[i-m+1]) > 0) != ((b[m] - b[1]) > 0)) continue;
        res++;
    }
    cout <<res;
}
