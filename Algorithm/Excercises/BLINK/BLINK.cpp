#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, dd[N], stC, enC, res, tt;
long long B;

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
    cin >> n >> B;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if (x) st |= (1 << i);
    }
    dd[st] = 1;
    while (1)
    {
        for (int i = 0; i < n; i++)
        {
            int z = (i-1+n) % n;
            if (bit(x, z) && !bit(x, i)) y |= (1 << i);
        }
        if (dd[y])
        {
            stC = dd[y];
            enC = dd[x] + 1;
        }
        else
        {
            dd[y] = ++tt;
            x = y;
        }
    }
    if (B < stC) res = B;
    else
    {
        int lenC = enC - stC + 1;
        res = (B - stC) % lenC + stC;
    }
    for (int i = 0; i < (1 << 16); i++)
        if (dd[i] == res)
        {
            cout <<res;
            return 0;
        }

}
