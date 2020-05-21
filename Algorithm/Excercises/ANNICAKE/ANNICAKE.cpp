#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, T, x[N], t[N];

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


bool check(int mid)
{
    priority_queue<int> q;
    ll curAns = 0;
    for (int i = 1; i <= mid; i++) {q.push(t[i]), curAns += t[i];}
    if (1ll*T - x[mid] >= curAns) return 1;
    for (int i = mid+1; i <= n; i++)
    {
        if (q.top() > t[i])
        {
            curAns -= q.top();
            curAns += t[i];
            q.pop();
            q.push(t[i]);
        }
        if (1ll*T - x[i] >= curAns) return 1;
    }
    return 0;
}
int main()
{
    freopen("ANNICAKE.INP", "r", stdin);
    freopen("ANNICAKE.OUT", "w", stdout);
    n = readInt(); T = readInt();
    for (int i = 1; i <= n; i++)
    {
        x[i] = readInt();
        t[i] = readInt();
    }
    int l = 0, r = n+1;
    while (r - l > 1)
    {
        int mid = (r + l)/2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout <<l;
}
