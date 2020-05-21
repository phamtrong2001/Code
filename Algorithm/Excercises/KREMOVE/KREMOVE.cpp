#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1000005
#define maxc 1000000007

using namespace std;

int n, k, a[N], M[N][25], res = maxc;

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
int get(int u, int v)
{
    int k = log2(v - u + 1);
    return min(M[u][k], M[v - (1 << k) + 1][k]);
}
int main()
{
    freopen("KREMOVE.INP", "r", stdin);
    freopen("KREMOVE.OUT", "w", stdout);
    n = readInt(); k = readInt(); k = n - k;
    for (int i = 1; i <= n; i++) a[i] = readInt();
    sort(a+1, a+n+1);
    M[1][0] = maxc;
    for (int i = 2; i <= n; i++)
        M[i][0] = a[i] - a[i-1];
    for (int i = 1; (1 << i) <= n; i++)
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
            M[j][i] = min(M[j][i-1], M[j+(1<<(i-1))][i-1]);
    for (int u = 1; u <= n-k+1; u++)
    {
        int v = u + k - 1;
        res = min(res, a[v] - a[u] + get(u+1, v));
    }
    cout <<res;
}
