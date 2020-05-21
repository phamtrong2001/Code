/***************************************************************************/
/**********************  LANG TU HAO HOA  **********************************/
/***************************************************************************/
#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define maxc 1000000007
#define task "rect"
#define maxn 500005

using namespace std;

int n, m, h[maxn], k[maxn];

int l[maxn], r[maxn];
stack <int> s;

long long res = -maxc;

void solve(int mang[])
{
    for (int i = 1; i <= n; i++)
    {
        while (!s.empty() && mang[s.top()] >= mang[i]) s.pop();
        if (s.empty()) l[i] = 0;
            else l[i] = s.top();
        s.push(i);
    }
    for (int i = n; i >= 1; i--)
    {
        while (!s.empty() && mang[s.top()] >= mang[i]) s.pop();
        if (s.empty()) r[i] = n+1;
            else r[i] = s.top();
        s.push(i);
    }
    for (int i = 1; i <= n; i++)
        res = max(res, 1ll*mang[i]*(r[i] - l[i] - 1));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i], k[i] = m - h[i];
    solve(h);
    solve(k);
    cout << res;
    return 0;
}
