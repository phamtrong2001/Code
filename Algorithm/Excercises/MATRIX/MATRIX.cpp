#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define maxc 1000000007

using namespace std;

long long n, k;
int main()
{
    freopen("MATRIX.INP", "r", stdin);
    freopen("MATRIX.OUT", "w", stdout);

    cin >> n >> k;
    long long u = 1, v = 1, cur = 1, res = 1;
    for (long long i = 1; i <= k; i++)
    {
        char c; cin >> c;
        long long z = 0; if (c == 'R' || c == 'L') z = 1;
        if (c == 'D' || c == 'R')
        {
            if ((u + v) % 2 == 0)
            {
                if (u + v < n+1) cur += u*2 - z;
                else cur += (n-v+1)*2 - 1 - z;
            }
            else
            {
                if (u + v >= n+1) cur += (n-u+1)*2 - 2 + z;
                else cur += v*2 - 1 + z;
            }
            if (c == 'D') u++; else v++;
        }
        else
        {
            if ((u + v) % 2 == 0)
            {
                if (u + v <= n+1) cur -= v*2 - 1 - z;
                else cur -= (n - u + 1)*2 - z;
            }
            else
            {
                if (u + v <= n+1) cur -= u*2 - 2 + z;
                else cur -= (n - v + 1)*2 - 1 + z;
            }
            if (c == 'U') u--; else v--;
        }
        res += cur;
    }
    cout <<res;
}
