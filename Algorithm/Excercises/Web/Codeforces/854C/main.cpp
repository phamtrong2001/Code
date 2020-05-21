#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 300005
#define maxc 1000000007

using namespace std;

int n, k, c[N], ans[N];
long long res;
int main()
{
    cin >> n >> k; k++;
    for (int i = 1; i <= n; i++) cin >> c[i];

    priority_queue<pair<int, int> >q;
    for (int i = 1; i <= k; i++) q.push(mp(c[i], i));
    int tt = k-1;
    while (!q.empty())
    {
        tt++;
        int val = q.top().F;
        int id = q.top().S;
        q.pop();
        res += 1ll*val*(tt - id);
        ans[id] = tt;
        if (k >= n) continue;
        else q.push(mp(c[++k], k));
    }
    cout <<res<<endl;
    for (int i = 1; i <= n; i++) cout <<ans[i]<<" ";
}
