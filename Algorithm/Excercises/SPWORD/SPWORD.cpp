#include <bits/stdc++.h>
#define N 1000005
using namespace std;

string s;
int n, Z[N];
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
    int lmax = 0;
    for (int i = 1; i < n-1; i++)
    {
        if (Z[i] == n - i) lmax = max(lmax, Z[i]-1);
        else lmax = max(lmax, Z[i]);
    }
    for (int i = lmax; i >= 1; i--)
        if (Z[n - i] == i)
        {
            cout <<s.substr(0, i);
            exit(0);
        }
    cout <<"No solution!";
}
int main()
{
    freopen("SPWORD.INP", "r", stdin);
    //freopen("SPWORD.OUT", "w", stdout);
    prepare();
    solve();
}
