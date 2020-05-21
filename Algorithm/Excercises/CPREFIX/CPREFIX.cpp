#include <bits/stdc++.h>
#define N 100005
using namespace std;

string s;
int Z[N], n, res[N];
void prepare()
{
    cin >> s;
    n = s.size();
    int L = 0, R = 0;
    Z[0] = n;
    for (int i = 1; i < n; i++)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n && s[R] == s[R - L]) R++;
            Z[i] = R - L; R--;
        }
        else
        {
            int k = i - L;
            if (Z[k] < R - i + 1) Z[i] = Z[k];
            else
            {
                L = i;
                while (R < n && s[R] == s[R - L]) R++;
                Z[i] = R - L; R--;
            }
        }
    }
}
void solve()
{
    for (int i = 0; i < n; i++)
    {
        if (Z[i] == 0) continue;
        res[1]++;
        res[Z[i]+1]--;
    }
    for (int i = 1; i <= n; i++)
    {
        res[i] += res[i-1];
        cout <<res[i]<<" ";
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("CPREFIX.INP", "r", stdin);
    //freopen("CPREFIX.OUT", "w", stdout);
    prepare();
    solve();
}
