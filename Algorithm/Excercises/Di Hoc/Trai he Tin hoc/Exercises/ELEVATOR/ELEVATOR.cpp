#include <bits/stdc++.h>
#define N 105
#define mod 1000000007
using namespace std;

int n, c, p, t, a[N], b[N];
int check(int num)
{
    int pos; int ans = 0;
    for (int i = 1; i <= n; i++)
        if (b[i] >= num) {
            pos = i; break;
        }

    int peo = num - b[pos-1];
    for (int i = pos; i >= 1; )
    {
        int z = (peo-1)/c + 1;
        ans += 2ll*i*p*z;
        if (peo % c == 0)
        {
            i--;
            peo = a[i];
        }
        else
        {
            peo = peo% c;
            for (int j = i-1; j >= 0; j--)
                if (a[j] + peo <= c) peo += a[j];
                else
                {
                    peo = a[j] - (c - peo);
                    i = j; break;
                }
        }
    }
    return ans <= t;
}
int main()
{
    freopen("ELEVATOR.INP", "r", stdin);
    freopen("ELEVATOR.OUT", "w", stdout);
    cin >> n >> c >> p >> t;
    a[0] = mod;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    int l = 0, r = b[n] + 1;
    while (r - l > 1)
    {
        int mid = (r + l) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout <<l;
}
