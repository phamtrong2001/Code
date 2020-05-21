#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1ll*1000000000000000007

using namespace std;

int n, a[N];
ll lef[N], rig[N], sum[N], res;

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
    freopen("INP.TXT", "r", stdin);
    n = readInt();
    for (int i = 2; i <= n; i++) a[i] = readInt();
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > 1) lef[i] = lef[i-1] + (a[i]/2)*2;
        else lef[i] = 0;
        if (a[i]) sum[i] = sum[i-1] + ((a[i]-1)/2)*2 + 1;
        else sum[i] = 0;
    }
    for (int i = n-1; i >= 1; i--)
    {
        if (a[i+1] > 1) rig[i] = rig[i+1] + (a[i+1]/2)*2;
        else rig[i] = 0;
    }

    ll curMax = -maxc;
    for (int i = 1; i <= n; i++)
    {
        curMax = max(curMax, lef[i] - sum[i]);
        res = max(res, rig[i] + sum[i] + curMax);

    }
    cout <<res;
}
