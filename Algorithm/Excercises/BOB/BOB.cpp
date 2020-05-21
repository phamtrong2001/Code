#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1005
#define maxc 1000000007

using namespace std;

long long n, m, a[N][N], tr[N][N], res, curAns;
stack<pii> s;

long long readInt()
{
	bool minus = false;
	long long result = 0;
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
void Clear()
{
    while (!s.empty()) s.pop();
}
int main()
{
    freopen("BOB.INP", "r", stdin);
    freopen("BOB.OUT", "w", stdout);
    n = readInt(); m = readInt();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) a[i][j] = readInt();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] != a[i-1][j]) tr[i][j] = i-1;
            else tr[i][j] = tr[i-1][j];
        }
    for (int i = 1; i <= n; i++)
    {
        Clear();
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] != a[i][j-1])
            {
                Clear();
                curAns = i - tr[i][j];
                s.push(mp(curAns, 1));
            }
            else
            {
                long long dem = 1;
                long long delta = i - tr[i][j];
                while (!s.empty() && s.top().F >= delta)
                {
                    dem += s.top().S;
                    curAns -= s.top().S*s.top().F;
                    s.pop();
                }
                curAns += delta*dem;
                s.push(mp(delta, dem));
            }
            res += curAns;
        }
    }
    cout <<res;
}
