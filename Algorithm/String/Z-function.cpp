#include <bits/stdc++.h>
#define maxn 1000003
using namespace std;
string s, t;
int n, m, res = 0, z[maxn];

void Z_function()
{
    int l = 1, r = 1;
    z[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (i <= r) z[i] = min(r - i + 1, z[i-l+1]);
        while (i + z[i] <= n && s[i+z[i]] == s[z[i]+1]) ++z[i];
        if (i + z[i] - 1 > r)
            r = i + z[i] - 1, l = i;
    }
}
int main()
{
    freopen("INP.TXT", "r", stdin);
    cin >> s >> t;
    m = t.length();
    s = "*" + t + "#" + s;
    n = s.length();
    Z_function();
    for (int i = m-1; i < n; i++) if (z[i] >= m) cout <<i-m-1<<" ";
    //cout <<res;
    return 0;
}
