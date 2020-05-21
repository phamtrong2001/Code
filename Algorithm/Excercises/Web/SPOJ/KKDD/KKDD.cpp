#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 10005
#define maxc 1ll*1000000000000000007

using namespace std;

int n, k, a[N], b[N], cur;
ll dp[N];

struct Median_Heap
{
    priority_queue<int> q[3];
    ll sum[3];
    Median_Heap()
    {
        sum[1] = sum[2] = 0;
        while (!q[1].empty()) q[1].pop();
        while (!q[2].empty()) q[2].pop();
    }
    int Pop(int id)
    {
        int x = q[id].top(); q[id].pop();
        if (id == 2) x = -x;
        sum[id] -= x;
        return x;
    }
    void Push(int id, int x)
    {
        sum[id] += x;
        if (id == 2) x = -x;
        q[id].push(x);
    }
    void add(int x)
    {
        if (q[2].empty()) Push(2, x);
        else if (q[1].empty()) Push(2, x);
        else
        {
            int x1 = q[1].top();
            if (x < x1) Push(1, x);
            else Push(2, x);
        }
        while (q[1].size() > q[2].size())
        {
            int x = Pop(1);
            Push(2, x);
        }
        while (q[1].size()+1 < q[2].size())
        {
            int x = Pop(2);
            Push(1, x);
        }
    }
    ll get()
    {
        int median = -q[2].top();
        ll lef = (ll)q[1].size()*median - sum[1];
        ll rig = (ll)sum[2] - q[2].size()*median;
        return lef + rig;
    }
};

int readInt () {
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
    freopen("KKDD.INP", "r", stdin);
    n = readInt(); k = readInt();
    for (int i = 1; i <= n; i++) a[i] = readInt();
    for (int i = 1; i <= n; i++)
    {
        dp[i] = maxc; cur = 0;
        Median_Heap q = Median_Heap();
        for (int j = 1; j <= 2*k; j++)
        {
            int id = i-j+1;
            if (id < 1) break;
            q.add(a[id]);
            if (j >= k) dp[i] = min(dp[i], dp[i-j] + q.get());
        }
    }
    cout <<dp[n];
}
