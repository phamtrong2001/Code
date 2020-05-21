#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1ll*100000000000000007

using namespace std;

int n;
ll a[N], f1[N], f2[N], f3[N];

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
    freopen("SEQ.INP", "r", stdin);
    freopen("SEQ.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    f1[0] = f2[0] = f3[0] = -maxc;
    for (int i = 1; i <= n; i++)
        f1[i] = max(f1[i-1], a[i]);
    for (int i = 1; i <= n; i++)
        f2[i] = max(f2[i-1], a[i]*2 + f1[i-1]);
    for (int i = 1; i <= n; i++)
        f3[i] = max(f3[i-1], a[i]*3 + f2[i-1]);
    cout <<f3[n];
}
