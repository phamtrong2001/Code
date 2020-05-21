#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1000005
#define maxc 1000000007

using namespace std;

int n, t, a[N];

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
    freopen("TRASH.INP", "r", stdin);
    freopen("TRASH.OUT", "w", stdout);
    n = readInt(); t = readInt();
    for (int i = 1; i <= n; i++) a[i] = readInt();

    int j = 1, curSum = 0;
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        curSum += a[i];
        while (j <= i && curSum > t)
        {
            curSum -= a[j];
            j++;
        }
        res += (i-j+1);
    }
    cout <<res;
}
