#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 300005
#define maxc 1000000007

using namespace std;

int n;
long long res;
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
bool cmp(pii p, pii q)
{
    return p.F + p.S > q.F + q.S;
}
int main()
{
    freopen("DELCOL.INP", "r", stdin);
    freopen("DELCOL.OUT", "w", stdout);
    n = readInt();
    for (int i = 1; i <= n; i++)
    {
        a[i].F = readInt();
        a[i].S = readInt();
    }
    sort(a+1, a+n+1, cmp);
    for (int i = 1; i <= n; i++)
        if (i % 2) res += a[i].F;
        else res -= a[i].S;
    cout <<res;
}
