#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

int n, a[N], dem;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 1) dem++;
    }
    if (dem)
    {
        cout <<n - dem;
        return 0;
    }
    int res = maxc;
    for (int i = 1; i <= n; i++)
    {
        int cur = a[i];
        for (int j = i; j <= n; j++)
        {
            cur = __gcd(cur, a[j]);
            if (cur == 1) res = min(res, j-i);
        }
    }
    if (res == maxc) cout <<-1;
    else cout <<res + n-1;
}
