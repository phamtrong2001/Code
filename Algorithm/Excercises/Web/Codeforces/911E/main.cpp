#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 200005
#define maxc 1000000007

using namespace std;

int n, k, dd[N], p[N], cnt, cur, pmax;
stack<int> s;

int main()
{
    freopen("INP.TXT", "r", stdin);
    cin >> n >> k;
    s.push(n+1);
    cur = 1;
    for (int i = 1; i <= k; i++)
    {
        cin >> p[i];
        dd[p[i]] = 1;
        s.push(p[i]);
        while (s.top() == cur)
        {
            s.pop();
            cur++;
        }
    }
    int pre = cur-1;
    cnt = k;
    while (!s.empty())
    {
        int z = s.top(); s.pop();
        if (z < pre)
        {
            cout <<-1;
            return 0;
        }
        for (int i = z-1; i >= pre+1; i--)
            p[++cnt] = i;
        pre = z;
    }
    for (int i = 1; i <= n; i++) cout <<p[i]<<" ";
}
