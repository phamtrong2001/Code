#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1000005
#define maxc 1000000007

using namespace std;

int n, k, a[N], x[N], dem[N], curDem, res;

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

void upd(int x, int val)
{
    if (dem[x]) curDem--;
    dem[x] += val;
    if (dem[x]) curDem++;
}
int main()
{
    freopen("KDEL.INP", "r", stdin);
    freopen("KDEL.OUT", "w", stdout);
    n = readInt(); k = readInt();
    for (int i = 1; i <= n; i++)
    {
        a[i] = readInt();
        x[i] = a[i];
    }
    sort(x+1, x+n+1);
    int cur = unique(x+1, x+n+1) - x - 1;
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(x+1, x+cur+1, a[i]) - x;
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        upd(a[i], 1);
        while (j <= i && curDem > k+1)
        {
            upd(a[j], -1);
            j++;
        }
        res = max(res, dem[a[i]]);
    }
    cout <<res;
}
