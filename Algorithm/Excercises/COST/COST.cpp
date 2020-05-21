#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 1000005
#define maxc 1ll*1000000000000000007

using namespace std;

int n, lef[N], rig[N];
ll res, a[N], ans = maxc;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("COST.INP", "r", stdin);
    //freopen("COST.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = a[n+1] = maxc;
    stack<int> s;
    s.push(0);
    for (int i = 1; i <= n; i++)
    {
        while (!s.empty() && a[s.top()] < a[i]) s.pop();
        lef[i] = s.top();
        s.push(i);
    }
    while (!s.empty()) s.pop();
    s.push(n+1);
    for (int i = n; i >= 1; i--)
    {
        while (!s.empty() && a[s.top()] <= a[i]) s.pop();
        rig[i] = s.top();
        s.push(i);
    }
    for (int i = 1; i <= n; i++) res += min(a[lef[i]], a[rig[i]]);
    for (int i = 1; i <= n; i++)
        ans = min(ans, res - min(a[lef[i]], a[rig[i]]));
    cout <<ans;
}
