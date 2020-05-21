#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, a[N], b[N], c[N], x[N];

bool check(int val)
{
    for (int i = 1; i <= n; i++)
        if (b[i] >= val) c[i] = 1; else c[i] = 0;
    int cur = 0;
    for (int i = 1; i <= n+1; i++)
    {
        if (c[i] == 0)
        {
            sort(x+1, x+cur+1);
            reverse(x+1, x+cur+1);
            if (cur > 1 && x[1] + x[2] >= val) return 1;
            cur = 0;
        }
        else x[++cur] = a[i];
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("SEQAB.INP", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int l = 0, r = 1e9;
    while (r - l > 1)
    {
        int mid = (r + l)/2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout <<l;
}
