#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, a[N];

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
    for (int i = 1; i <= n; i++) a[i] = readInt() - 1;
    a[1]++;
    int cnt = 0;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == 0) cnt++;
        else
        {
            if (a[i] > cnt)
            {
                cout <<"NO";
                return 0;
            }
            else cnt -= a[i] - 1;
        }
    }
    if (cnt == 1)cout <<"YES";
    else cout <<"NO";
}
